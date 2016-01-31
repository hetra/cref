#ifndef SLIST_H_
#define SLIST_H_

struct Node
{
  void* data;
  struct Node* next;
};

int insertAfter(struct Node* target_node, struct Node* new_node)
{
  if(new_node != NULL)
  {
    if(target_node != NULL)
    {
      if(target_node->next != NULL)
      {
        new_node->next = target_node->next;
        target_node->next = new_node;
      }
      else
      {
        new_node->next = NULL;
        target_node->next = new_node;
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
        target_node->next = target_node->next->next;
      }
      else
      {
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

#endif // SLIST_H_
