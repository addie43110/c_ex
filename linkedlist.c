#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

/* function to push a node onto the linked list (at the head) */
void push_head(struct Node **head_ref, int new_pid) {

  /* allocate memory for the node using malloc */
  struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
  
  /* link the new node to the head*/
  new_node.pid = new_pid;
  new_node->next = (*head_ref);

  /* change head reference */
  (*head_ref) = new_node;

}



/* function to push a node to the tail of a linked list */
void push_tail(struct Node **head_ref, int new_pid) {
  
  struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));

  new_node.pid = new_pid;
  new_node->next = NULL;

  /* go to the tail of the list */
  struct Node * curr = (*head_ref);
  struct Node * prev = NULL;
  for(struct Node *curr = (*head_ref); curr!=NULL; curr=curr->next) {
    prev = curr;
  }
  prev->next = new_node;

} 


struct Node * pop_head(struct Node **head_ref) {
  struct Node * cp_node = (struct Node *) malloc(sizeof(struct Node));
  cp_node.pid = (*head_ref.pid);
  cp_node->next = NULL;


  /* free head and make new head */
  struct Node *new_head_ref = (*head_ref)->next;
  free(*head_ref);
  head_ref = new_head_ref;

}
