#ifndef STACK_H_
#define STACK_H_
#include "../../lists/dlist/src/dlist.h"

struct Stack
{
  unsigned int size;
  struct Node* top;
};

int push(struct Node* new_node, struct Stack* stack)
{
  int result = insertAfter(stack->top, new_node);
  
  if(result == EXIT_FAILURE)
  {
    return EXIT_FAILURE;
  }
  
  stack->size++;
  
  if(stack->top == NULL)
  {
    stack->top = new_node;
  }
  else
  {
    stack->top = stack->top->next; 
  }
  
  return EXIT_SUCCESS;
}

int pop(struct Stack* stack)
{
  if(stack->top == NULL)
  {
    return EXIT_FAILURE;
  }
  
  struct Node* temp = stack->top->prev;
  int result = removeAfter(stack->top->prev);
  
  if(result == EXIT_FAILURE)
  {
    return EXIT_FAILURE;
  }
  
  stack->size--;
  stack->top = temp;
  
  return EXIT_SUCCESS;
}

#endif // STACK_H_
