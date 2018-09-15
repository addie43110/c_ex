#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"


/* function to push a node onto the linked list (at the head) */
void push_head(struct Node **head_ref, int new_pid) {

  /* allocate memory for the node using malloc */
  struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
  
  /* link the new node to the head*/
  new_node->pid = new_pid;
  new_node->next = (*head_ref);

  /* change head reference */
  (*head_ref) = new_node;

}

/* get the tail */
struct Node * get_tail(struct Node **head_ref) {
  struct Node *prev = NULL;
  for(struct Node *curr=(*head_ref); curr!=NULL; curr=curr->next) {
    prev = curr;
  }

  return prev;
}



/* function to push a node to the tail of a linked list */
void push_tail(struct Node **head_ref, int new_pid) {
  
  struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));

  new_node->pid = new_pid;
  new_node->next = NULL;

  /* go to the tail of the list */
  struct Node *tail = get_tail(head_ref);
  tail->next = new_node;

} 


struct Node * pop_head(struct Node **head_ref) {
  struct Node * cp_node = (struct Node *) malloc(sizeof(struct Node));
  cp_node->pid = (*head_ref)->pid;
  cp_node->next = NULL;

  struct Node *og_head = (*head_ref);

  /* free head and make new head */
  *head_ref  = (struct Node *) (*head_ref)->next;
  free(og_head);

  return cp_node;
}

struct Node * pop_tail(struct Node **head_ref) {
  struct Node * cp_node = (struct Node *) malloc (sizeof(struct Node));
  struct Node *tail = get_tail(head_ref);
  
  struct Node *prev = NULL;
  for(struct Node *curr = (*head_ref); curr->next!=NULL; curr=curr->next) {
    prev=curr;
  }

  prev->next = NULL;

  cp_node->pid = tail->pid;
  cp_node->next = NULL;

  free(tail);
  return cp_node;  

}


struct Node * get(struct Node **head_ref, int ind) {
  int i = 0;
  struct Node * cp_node = (struct Node *) malloc(sizeof(struct Node));

  struct Node *prev = NULL;
  for(struct Node *curr = (*head_ref); curr != NULL; curr=curr->next) {
      if(i<(ind+1)) {
        prev = curr;
        i++;
      } else {
        break;
      }
  }

  cp_node->pid = prev->pid;
  cp_node->next = NULL;

  return cp_node; 
}

void print_list(struct Node **head_ref) {
  printf("\n{");
  for(struct Node *curr = (*head_ref); curr!=NULL; curr=curr->next) {
    printf("%d", curr->pid);
    if(curr->next!=NULL) {
      printf(", ");
    }
  }
  printf("}\n");
}
