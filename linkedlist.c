#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"


/* function to push a node onto the linked list (at the head) */
void push_head(struct Node **head_ref, long new_pid, char *path) {

  /* allocate memory for the node using malloc */
  struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
  
  /* link the new node to the head*/
  new_node->pid = new_pid;
  int len_path = strlen(path);
  new_node->path = malloc(len_path);
  strncpy(new_node->path, path, len_path);
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
void push_tail(struct Node **head_ref, long new_pid, char *path) {  

  struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));

  new_node->pid = new_pid;
  new_node->path = malloc(strlen(path)+1);
  strncpy(new_node->path, path, strlen(path)+1);
  new_node->next = NULL;

  /* go to the tail of the list */
  struct Node *tail = get_tail(head_ref);
  if(tail==NULL) {
    (*head_ref)=new_node;
  } else {
    tail->next = new_node;
  }
} 


struct Node * pop_head(struct Node **head_ref) {
  
  /* if list empty, return null pointer */
  if (*head_ref==NULL) return NULL;

  struct Node * cp_node = (struct Node *) malloc(sizeof(struct Node));
  cp_node->pid = (*head_ref)->pid;
  int len_path = strlen((*head_ref)->path)+1;
  cp_node->path = malloc(len_path);
  strncpy(cp_node->path, (*head_ref)->path, len_path);
  cp_node->next = NULL;

  struct Node *og_head = (*head_ref);

  /* free head and make new head */
  *head_ref  = (struct Node *) (*head_ref)->next;
  free(og_head);

  return cp_node;
}

struct Node * pop_tail(struct Node **head_ref) {

  /* if list is empty, return null-pointer */
  if(*head_ref==NULL) return NULL;

  struct Node * cp_node = (struct Node *) malloc (sizeof(struct Node));
  
  struct Node *tail = NULL;
  struct Node *prev = NULL;
  struct Node *curr = (*head_ref);
  for(; curr->next!=NULL; curr=curr->next) {
    prev=curr;
  }
 
  tail = curr;
  if(prev==NULL) {
    (*head_ref) = NULL;
  } else {
    prev->next = NULL;
  }

  cp_node->pid = tail->pid;
  int len_path = strlen(tail->path)+1;
  cp_node->path = malloc(len_path);
  strncpy(cp_node->path, tail->path, len_path);
  cp_node->next = NULL;

  free(tail);
  return cp_node;  

}


struct Node * get(struct Node **head_ref, int ind) {
  
  /* if list is empty, return null-pointer */
  if(*head_ref == NULL) return NULL;
  /* if ind is <0, don't bother looking */
  if (ind<0) return NULL;

  int i = 0;
  struct Node * cp_node = (struct Node *) malloc(sizeof(struct Node));

  struct Node *prev = NULL;
  struct Node *curr = (*head_ref);
  for(; curr != NULL; curr=curr->next) {
      if(i<(ind+1)) {
        prev = curr;
        i++;
      } else {
        break;
      }
  }

  if (curr==NULL) {
    return NULL; /* index out of bounds */
  }

  cp_node->pid = prev->pid;
  int len_path = strlen(prev->path)+1;
  cp_node->path = malloc(len_path);
  sprintf(cp_node->path, prev->path, len_path);
  cp_node->next = NULL;

  return cp_node; 
}

void print_list(struct Node **head_ref) {

  printf("\n{");
  for(struct Node *curr = (*head_ref); curr!=NULL; curr=curr->next) {
    printf("%ld", curr->pid);
    if(curr->next!=NULL) {
      printf(", ");
    }
  }
  printf("}\n\n");
}


/* assumes each pid is unique. returns index of node in list or -1 if not found */
int find(struct Node **head_ref, long pid) {
  int i=0;
  for(struct Node *curr = (*head_ref); curr!=NULL; curr=curr->next) {
    if(curr->pid == pid) {
      return i;
    }
    i++;
  }

  return -1;
}


void remove_ind(struct Node **head_ref, int ind) {

  /*if empty list, don't do anything */
  if (*head_ref==NULL) return;

  struct Node *prev = NULL;
  struct Node *curr = (*head_ref);
  for(int i=0; i<ind; i++) {
    if(curr==NULL) {
      puts("Could not remove: array index out of bounds.");
      return;
    }
    prev=curr;
    curr=curr->next;
  }

  if(prev==NULL) (*head_ref)=curr->next;
  else {
    prev->next = curr->next;
  }
  free(curr);
}
