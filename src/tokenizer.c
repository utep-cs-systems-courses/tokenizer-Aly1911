#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c) {


  if ( c == ' ' || c == '\t') {
    return 1;
  } else {
    return 0;

  }

}


int non_space_char(char c){

  switch (c){
  case '\t':
  case ' ':  
  case '\0':
    return 0;
  default:
    return 1;
  }
}


char *word_start(char *str){

  while(space_char(*str)){

    str++;
  }
  return str;

}


char *word_terminator(char *word) {

  while(non_space_char(*word)) {
    word++;

  }
  return word;

}
int count_words(char *str)

{

  char *tmp = str;
  int count = 0;
  int i = 0;
  tmp = word_start(tmp);

  while(*tmp){
    if(non_space_char(*tmp)){
      count++;
    }

    tmp=word_terminator(tmp);
    tmp=word_start(tmp);

  }
  
  return count;

}


/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)

{

  char *copyStr = malloc(( len + 1) * sizeof(char));
  int i;

  for (i=0; i < len; i++){
    copyStr[i] = inStr[i];
  }

  copyStr[i] = '\0';
  return copyStr;

}



/*Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

should be like 6-7 lines

malloc ***

int *numbers = (what casts it i.e.int*)malloc(number of bytes ex: with 5 numbers it would be 5*sizeofint so (5+1)*sizeof(int))

*/

char **tokenize(char *str)
{
  short size = 0, i = 0;
  int totalWords = count_words(str);
  char *wordStart, *wordEnd;
  char **tokens = (char**)malloc(sizeof(char*)*(totalWords+1));


  for(i = 0; i < totalWords; i++) {
    wordStart = word_start(str);
    wordEnd = word_terminator(wordStart);
    size = wordEnd - wordStart;
    tokens[i] = copy_str(wordStart, size);
    str = word_start(wordEnd);
  }

  tokens[i] = '\0';
  return tokens;

}

/* Prints all tokens. */

void print_tokens(char **tokens)

{

  int i=0;

  while (tokens[i]){

    printf("Token[%d] = %s\n", i, tokens[i]);
    i++;

  }
}


/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens)

{

  int i = 0;

  while(tokens[i]){
    free(tokens[i]);
    i++;
  }

  free(tokens);

}



