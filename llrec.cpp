#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{

//take the input linked list and separate into smaller and larger linked list
	
//base case: when the head node points to null, return
  if (head==NULL)
  {
    return;
  }

//do the work: put the head node in the smaller or larger list
  Node* oldHead = head;
  if (head->val <= pivot)
  {
    Node* temp = smaller;
    smaller = head;
    smaller->next = temp;
  
  }
  
  else
  {
    Node* temp = larger;
    larger = head;
    larger->next = temp;
  }

//recursive step: go to next head node
  head = oldHead;
  llpivot(head, smaller, larger, pivot);
}
