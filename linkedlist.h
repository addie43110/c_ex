#ifndef LINKEDLIST_H_ /* guard */
#define LINKEDLIST_H_


/* linked list code largely implemented with reference to 
https://www.geeksforgeeks.org/generic-linked-list-in-c-2/ */
struct Node {
  int pid;
  struct Node *next;
};


void push_head(struct Node **head_ref, int new_pid);

struct Node * get_tail(struct Node **head_ref);

void push_tail(struct Node **head_ref, int new_pid); 

struct Node * pop_head(struct Node **head_ref); 

struct Node * pop_tail(struct Node **head_ref);

struct Node * get(struct Node **head_ref, int i);

void print_list(struct Node **head_ref);

#endif
