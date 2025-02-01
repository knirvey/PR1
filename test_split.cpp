/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
int main(int argc, char* argv[])
{
  Node* head = nullptr;
  Node* tail = nullptr;

  for(int i=1; i<=6; i++){
    Node* newNode = new Node(i, nullptr);
    if(head == nullptr){
      head = newNode;
      tail = head;
    }else{
      tail->next = newNode;
      tail = newNode;

    }

  }

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(head, odds, evens);
  std::cout<<"Splitted! Odds: ";
  for(Node* current = odds; current; current = current->next){
    std::cout << current->value << ", ";
  }
  std::cout<<"Splitted! Evens: ";
  for(Node* current = evens; current; current = current->next){
    std::cout << current->value << ", ";
  }
  
  while(odds){
    Node* tmp = odds;
    odds = odds->next;
    delete tmp;
  }
  while(evens){
    Node* tmp = evens;
    evens = evens->next;
    delete tmp;
  }

  std::cout<<std::endl;
}
