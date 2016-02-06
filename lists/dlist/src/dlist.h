#ifndef DLIST_H_
#define DLIST_H_

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  void* data;
  struct Node* next;
  struct Node* prev;
};

int insertBefore(struct Node* target_node, struct Node* new_node)
{
  if(new_node != NULL)
  {
    if(target_node != NULL)
    {
      if(target_node->prev != NULL)
      {
        target_node->prev->next = new_node;
      }
      
      new_node->next = target_node;
      new_node->prev = target_node->prev;
      target_node->prev = new_node;
    }
    else
    {
      return EXIT_FAILURE;
    }
  }
  else
  {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

int insertAfter(struct Node* target_node, struct Node* new_node)
{
  if(new_node != NULL)
  {
    if(target_node != NULL)
    {
      if(target_node->next != NULL)
      {
        new_node->next = target_node->next;
        target_node->next->prev = new_node;
      }
      else
      {
        new_node->next = NULL;
      }
      
      new_node->prev = target_node;
      target_node->next = new_node;
    }
    else
    {
      new_node->prev = NULL;
    }
  }
  else
  {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

int removeBefore(struct Node* target_node)
{
  if(target_node != NULL)
  {
    if(target_node->prev != NULL)
    {
      if(target_node->prev->prev != NULL)
      {
        target_node->prev->prev->next = target_node;
        target_node->prev = target_node->prev->prev;
      }
      else
      {
        target_node->prev->next = NULL;
        target_node->prev = NULL;
      }
    }
    else
    {
      return EXIT_FAILURE;
    }
  }
  else
  {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

int removeAfter(struct Node* target_node)
{
  if(target_node != NULL)
  {
    if(target_node->next != NULL)
    {
      if(target_node->next->next != NULL)
      {
        target_node->next->next->prev = target_node;
        target_node->next = target_node->next->next;
      }
      else
      {
        target_node->next->prev = NULL;
        target_node->next = NULL;
      }
    }
    else
    {
      return EXIT_FAILURE;
    }
  }
  else
  {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

int traverseForward(struct Node* target_node)
{
  struct Node* ptr = target_node;
  
  for(ptr=target_node;ptr!=NULL;ptr=ptr->next)
  {
    printf("%d ", (int)(ptr->data));
  }
  
  printf("\n");
  
  return EXIT_SUCCESS;
}

int traverseBackward(struct Node* target_node)
{
  struct Node* ptr = target_node;
  
  for(ptr=target_node;ptr!=NULL;ptr=ptr->prev)
  {
    printf("%d ", (int)(ptr->data));
  }
  
  printf("\n");
  
  return EXIT_SUCCESS;
}

unsigned int length(struct Node* target_node)
{
  unsigned int len = 0;
  struct Node* ptr = target_node;
  
  for(ptr=target_node;ptr!=NULL;ptr=ptr->next)
  {
    len++;
  }
  
  return len;
}

#endif // DLIST_H_
