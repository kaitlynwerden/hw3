#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  smaller = nullptr;
  larger = nullptr;
  llpivotHelper(head, smaller, larger, pivot);
  head = nullptr;
}

void llpivotHelper (Node*& head, Node*& smaller, Node*& larger, int pivot)
{

//take the input linked list and separate into smaller and larger linked list
	
//base case: when the head node points to null, return
  if (head==NULL)
  { 
    return;
  }

//do the work: put the head node in the smaller or larger list
  Node* nextHead = head->next;
  head->next = nullptr;
  if (head->val <= pivot)
  {
    if(smaller == nullptr)
    {
      smaller = head;
      llpivotHelper(nextHead, smaller, larger, pivot);
    }
    else
    {
      smaller->next = head;
      llpivotHelper(nextHead, smaller->next, larger, pivot);
    }
  }
  else
  {
    if(larger == nullptr)
    {
      larger = head;
      llpivotHelper(nextHead, smaller, larger, pivot);
    }
    else
    {
      larger->next = head;
      llpivotHelper(nextHead, smaller, larger->next, pivot);
    }
  }
  
}


