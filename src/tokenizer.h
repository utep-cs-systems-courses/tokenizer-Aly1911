#ifndef _TOKENIZER_
#define _TOKENIZER_


#include <stdio.h>



int main()

{

  char *word_start(char *str);

  int non_space_char(char c);

  char *word_terminator(char *word);

  char *copy_str(char *inStr, short len);



  char words[] = "  fattyfatfatty";

  printf("%c", *copy_str(words, 10));



  return 0;

}



int space_char(char c) {

  if ( c == ' ' || c == '\t') {

    return 1;

  } else {

    return 0;

  }

}



int non_space_char(char c){

  switch (c) {

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




/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){

  char copy[len];

  for (int i = 0; i < len; i++) {

    copy[i] = inStr[i];

    printf("%c", inStr[i]);}
}

/*Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
 
