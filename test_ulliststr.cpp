#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
ULListStr list;

list.push_back("Apple");
list.push_back("Bananna");
list.push_back("Cinammon");
list.push_back("Dounuts");

std::cout<<"Initial Size:" << list.size() << std::endl;
std::cout <<"Front: " << list.front() << std::endl;
std::cout <<"Back: " << list.back() << std::endl;

std::cout<<"Push_fronting..." << std::endl;
list.push_front("Rice");
list.push_front("Crossaint");
std::cout <<"Front: " << list.front() << std::endl;


list.pop_back();
std::cout<<"Pop_backed! Now Back:" <<list.back()<< std::endl;

std::cout<<"eliminating list"<<std::endl;
list.pop_back();
list.pop_back();
list.pop_back();
list.pop_back();
list.pop_back();
if(list.empty()){
  std::cout<<"empty now"<<std::endl;
}

}
