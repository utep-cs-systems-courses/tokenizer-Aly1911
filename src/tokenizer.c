#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  if (c == ' ' | c == '\t' | c == '\n') {
    return 1;
  }
  else return 0;
}

int non_space_char(char c)
{
  if (c != ' ' & c != '\t' & c != '\n') {
    return 1;
  }
  else return 0;
}

char *word_start(char *str)
{
  while (space_char(*str) > 0){
    str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while (non_space_char(*word) > 0){
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int total = 0;
  char *p = str;
  
  while(p){
    p = word_start(p);
    if (*p++ == '\0') break;
    p = word_terminator(p);
    total++;
  }
  return total;
}

char *copy_str(char *inStr, short len)
{
  int i = 0;
  char *copy = malloc(sizeof(char) * (len + 1));
  for (i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  copy[i] = 0;
  return copy;
}

char **tokenize(char *str)
{
  int size = count_words(str);
  char **tokens = malloc((size + 1) * sizeof(char *));
  int i = 0;
  int length;
  char *start = str;
  char *end = word_terminator(str);

  for(i = 0; i < size; i++)
    {
      if(i > 0) {
	start = word_start(end);
	end = word_terminator(start);
      }
      int word_size = end - start;
	tokens[i] = malloc(word_size * sizeof(char));//copystr change
	for(int j = 0; j < word_size; j++)
	  {
	    tokens[i][j] = start[j];
	  }
      }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++)
    {
      printf("Token [%d]: %s\n", i, tokens[i]);
    }
}
  
void free_tokens(char **tokens)
{
  char **p = tokens;
  while (p != NULL){
    free(*p);
    p++;
  }
  free(p);
}

int string_compare(char str[], char str2[]){
  while (*str != '\0' || *str2 != '\0'){
    if (*str == *str2){
      return 1;
    }
    else{
      return 0;
    }
  }
}
