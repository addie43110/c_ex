#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main() {

  struct Node **head_ref = malloc(sizeof(struct Node));

  char foo[4];
  snprintf(foo, 3, "foo");
  push_head(head_ref, 6, foo);  
  print_list(head_ref);
  printf("%s : \tHead = 6\n", (*head_ref)->pid==6? "True" : "False");
  printf("%s : \thead->next = null\n", (*head_ref)->next==NULL? "True" : "False");

  char bar[4];
  snprintf(bar, 3, "bar");
  push_tail(head_ref, 8, bar);
  print_list(head_ref);
  printf("%s : \tHead = 6\n", (*head_ref)->pid==6? "True" : "False");
  printf("%s : \tTail = 8\n", get_tail(head_ref)->pid==8? "True" : "False");
  printf("%s : \tTail->next = NULL\n", get_tail(head_ref)->next==NULL? "true" : "false");


  char josh[5];
  snprintf(josh, 4, "josh");
  push_head(head_ref, 5, josh);
  print_list(head_ref);
  printf("%s : \tHead = 5\n", (*head_ref)->pid==5? "True" : "False");
  printf("%s : \ta[1]=6\n", get(head_ref, 1)->pid==6? "True" : "False");
  printf("%s : \tnon-leaky get\n", get(head_ref, 1)->next==NULL? "True" : "False");
  printf("%s : \ta[2]=8\n", get_tail(head_ref)->pid==8? "True" : "False");


  struct Node *tl = pop_tail(head_ref);
  print_list(head_ref);
  printf("%s : \told tail = 8\n", tl->pid==8? "True": "False");
  printf("%s : \tnew tail = 6\n", get_tail(head_ref)->pid==6? "True": "False");
  
  char *rabbit = malloc(strlen("rabbit")+1);
  snprintf(rabbit, strlen("rabbit"), "rabbit");
  push_tail(head_ref, 10, rabbit);
  print_list(head_ref);
  struct Node *hd = pop_head(head_ref);
  print_list(head_ref);
  printf("%s : \told head = 5\n", hd->pid==5? "True": "false");
  printf("%s : \tnon-leaky pop_head\n", hd->next==NULL? "True" : "False");
  printf("%s : \tnew head = 6\n", (*head_ref)->pid ==6? "True": "False");  
  

  char add[4], addi[5];
  snprintf(add, 3, "add");
  snprintf(addi, 4, "addi");
  push_head(head_ref, 2, addi);
  push_head(head_ref, 1, add);
  print_list(head_ref);
  printf("%s : \tfind 1==0\n", find(head_ref,1)==0? "True":"False");
  printf("%s : \tfind 2==1\n", find(head_ref,2)==1? "True":"False");
  printf("%s : \tfind 6==2\n", find(head_ref, 6)==2? "True":"False");

  remove_ind(head_ref, 2);
  print_list(head_ref);
  printf("%s : \tfind 6==1\n", find(head_ref, 6)==1? "True":"False"); 

  struct Node **empty = malloc(sizeof(struct Node));
  (*empty) = NULL;
  print_list(empty);
  printf("%s : \tfind 1==-1\n", find(empty, 1)==-1? "True":"False");
  printf("%s : \tget 0==NULL\n", get(empty, 0)==NULL? "True":"False");
  printf("%s : \tget 5==NULL\n", get(empty, 5)==NULL? "True":"False");

  push_head(empty, 1, addi);
  push_tail(empty, 2, add);
  push_tail(empty, 3, josh);
  print_list(empty);
  printf("%s : \tget 10==NULL\n", get(empty, 10)==NULL? "True":"False");
  printf("%s : \tfind(10)==-1\n", find(empty, 10)==-1? "True":"False");
  printf("%s : \tpop tail==3\n", pop_tail(empty)->pid==3? "True":"False");
  printf("%s : \tpop head==1\n", pop_head(empty)->pid==1? "True":"False");
  printf("%s : \tpop tail==2\n", pop_head(empty)->pid==2? "True":"False");
  
  print_list(empty);
  printf("%s : \tpop_tail==NULL\n", pop_tail(empty)==NULL? "True":"False");
  printf("%s : \tpop_head==NULL\n", pop_head(empty)==NULL? "True":"False");

  return 0;
}
