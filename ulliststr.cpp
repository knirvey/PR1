#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if(tail_ == NULL || tail_->last == ARRSIZE){ //if tail is null or full
    Item* newItem = new Item(); //create new item

    newItem->prev = tail_;
    newItem->first = 0;
    newItem->last = 0;

    if(tail_){ //if there is tail, link with new item
      tail_->next = newItem;
    }
    tail_ = newItem;
    if(!head_){ //if list is empty
    head_ = newItem;
  }}
  tail_->val[tail_->last++] = val; //setting value at open position
  size_++;
  
  
}


void ULListStr::pop_back(){
  if(empty()){
    throw std::invalid_argument("Empty list");
    return;
  }

  tail_->last--; //decrement number of elements
  size_--; 

  if(tail_->first == tail_->last){ //if current item is empty
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_){
      tail_->next = nullptr;
    }else{ //tail is empty, list is empty
      head_ = nullptr;
    }
    delete temp;
  }
}

void ULListStr::push_front(const std::string& val){
  if(!head_ || head_->first == 0){ //if list is empty or current head is full

    Item* newItem = new Item();

    newItem->next = head_;
    newItem->first = ARRSIZE; //first available space is end
    newItem->last = ARRSIZE; //if first = last => means empty item

    if(head_){ //if there is an item on list
      head_->prev = newItem;
    }
    head_ = newItem;
  if(!tail_){ //if list was empty
    tail_ = newItem;
  }

  }
  head_->val[--head_->first] = val; //add value
  size_ ++;
}

void ULListStr::pop_front(){
  if(empty()){
    throw std::invalid_argument("Bad location");
    return;
  }
  head_->first++;
  size_ --;

  if(head_->first == head_->last){ //if current item is empty
    Item* temp = head_;
    head_ = head_->next;
    if(head_){
      head_->prev = nullptr;
    }else{
      tail_ = nullptr;
    }
    delete temp;
  }
}



std::string const & ULListStr::back() const{
  if(empty()){
    std::cout<<"empty list" <<std::endl;
    return 0;
  }
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const{
  if(empty()){
    std::cout<<"empty list" <<std::endl;
    return 0;
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc>=size_){ //invalid location
    return nullptr;
  }
  Item* current = head_;
  while(current){ //trails the list
    size_t elements = current->last - current->first; //number of elements in the current item
    if(loc <elements){

      return &current->val[current->first + loc]; //return the requested item
    }
    loc -= elements; //if not found, go to next item
    current = current->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

