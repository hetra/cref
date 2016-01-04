#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

#define DEFAULT_LIST_LEN 12

int main(void)
{
  int i = 1;
  struct Node list[DEFAULT_LIST_LEN];
  
  // initialise head because we skip it in loop
  list[0].data = 0;
  list[0].next = NULL;
  
  for(i=1;i<DEFAULT_LIST_LEN;i++)
  {
    // initialise node
    list[i].data = i;
    list[i].next = NULL;
    
    insertAfter(&list[i-1], &list[i]);
  }
  
  traverseForward(&list[0]);
  printf("(%d)\n", length(&list[0]));
  
  removeAfter(&list[3]);
  insertAfter(&list[5], &list[4]);
  removeAfter(&list[11]); // should fail (i.e. return 1)
  removeAfter(&list[10]);
  
  traverseForward(&list[0]);
  printf("(%d)\n", length(&list[0]));
    
  return EXIT_SUCCESS;
}
