//heap.h
#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> m_vec;
	int m_aryness;
	PComparator m_compare;

};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  m_aryness = m;
  m_compare = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}

// Add implementation of member functions here

//empty function
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return m_vec.empty();
}

//size function
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return m_vec.size();
}
  
  
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::out_of_range("Empty heap");
    // ================================
    // throw the appropriate exception
    // ================================

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return m_vec[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //std::cout<<"pop running"<<std::endl;
  if(empty()){
     throw std::out_of_range("Empty heap");
    // ================================
    // throw the appropriate exception
    // ================================
  }

	//remove top element
  //switch the root with the lowest priority then delete it
   //std::cout << "popping: " << m_vec[0] << std::endl;

  int lastIndex = m_vec.size()-1;
  std::swap(m_vec[0],m_vec[lastIndex]);
  m_vec.pop_back();
  //reorder the heap
  
  //check if root/parent is smaller than children, if not, swap with smaller child                         
  
  //equation to find left child from parent: (m*index)+1
  //equation to find right child from parent: (m*index)+2
  int higherPriorityIndex;
  for (unsigned int i=0; (m_aryness*i)+1<m_vec.size(); i = higherPriorityIndex)  
  {
    //check which child is higher priority
    higherPriorityIndex = (m_aryness*i)+1;
    for(int childNum = 2 ; childNum <= m_aryness && (m_aryness*i)+childNum < m_vec.size() ; childNum++)
    {
      int childIndex = (m_aryness*i)+childNum;
      // if we found a new higher priority child
      if (m_compare(m_vec[childIndex],m_vec[higherPriorityIndex]))
      {
        // this is our new highest priority child
        higherPriorityIndex = childIndex;
        //std::cout<<"highest priority index is"<<higherPriorityIndex<<std::endl;
      }
    }
    
      
    if (m_compare(m_vec[i],m_vec[higherPriorityIndex]))
    {
      break;
    }
    else
    {
      //std::cout<<"swapping"<<(m_vec[i])<<"and"<<(m_vec[higherPriorityIndex])<<std::endl;
      std::swap(m_vec[i],m_vec[higherPriorityIndex]);
    }
                      
  }
  
  
}
                           

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  //add node to last index (lowest priority element)

	m_vec.push_back(item);
  
  //reorder the heap
  
  //compare to parent, if higher priority then swap
  //index of new item will be size of vector-1
  //equation to find parents from child: (index-1)/m
  int parentIndex;
  
  
  for (unsigned int i=m_vec.size()-1; i>0; i = parentIndex)
  {
    parentIndex = (i-1)/m_aryness;
    
    if (m_compare(m_vec[i], m_vec[parentIndex]))
    {
      //std::cout<<"swapping"<<(m_vec[i])<<"and"<<(m_vec[parentIndex])<<std::endl;
      std::swap(m_vec[i], m_vec[parentIndex]);
    
    }
    
    else
    {
      break;
    }
  }
  
}                           



#endif


