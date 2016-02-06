#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void)
{
  int i = 0;
  
  struct Node frames[3];
  
  for(i=0;i<3;i++)
  {
    frames[i].data = (void*)i;
    frames[i].next = NULL;
    frames[i].prev = NULL;
  }
  
  struct Stack stack = {0};
  
  stack.top = NULL;
  stack.size = 0;
  
  pop(&stack);
  push(&frames[0], &stack);
  push(&frames[1], &stack);
  pop(&stack);
  push(&frames[2], &stack);
  push(&frames[3], &stack);
  push(&frames[1], &stack);
  
  do
  {
    printf("%d\n", (int)stack.top->data);
  }
  while(pop(&stack) == EXIT_SUCCESS);
  
  return EXIT_SUCCESS;
}
