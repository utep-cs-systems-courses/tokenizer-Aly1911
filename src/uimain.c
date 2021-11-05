#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char userIn[100];

  while(1) {
    putchar('$');
    fgets(userIn, 100, stdin);
    printf("%s\n", userIn);
  }
  return 0;
}
//Tests 
