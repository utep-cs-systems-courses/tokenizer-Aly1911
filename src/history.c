#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


List* init_history(){
  List *history_list = malloc(sizeof(List));
  history_list->root = malloc(sizeof(Item));
  return history_list;

}

int get_length(char *str){
  char *beg = str;
  char *end = str;
  while (end){
    if (*end++ == '\0') break;
    end++;
  }
  return end - beg;
}

void add_history(List *list, char *str){
  Item *temp = list->root;
  if (list->root == NULL){
    temp->id = 1;
    temp->str = str;
    list->root = temp;
  }
  else{
    int counter = 1;
    while (temp->next != NULL){
      counter++;
      temp = temp->next;
    }
    short len = get_length(str);
    temp->str = (copy_str(str, len + 1));
    temp->id = counter;
    temp->next = malloc(sizeof(Item));
  }
}

char *get_history(List *list, int id)
{
  Item *temp;
  if(!list){
    return '\0';
  }
  else{
    temp = list->root;
    while(temp){
      if(temp->id == id){
	return temp->str;
      }
      temp = temp->next;
    }
    return '\0';
  }
}

void print_history(List *list){
  Item *temp = list->root;
  while (temp->next != NULL){
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  Item *iter = list->root;
  while(iter->next != 0){
    Item *prev = iter;
    iter = iter->next;
    free(prev->str);
    free(prev);
  }
  free(iter->str);
  free(iter);
  free(list);
}
