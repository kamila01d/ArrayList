#include <iostream>
#include "array.h"
#include <cassert>
#include <stdexcept>

int main() {

  ArrayList<int> a(16);
  ArrayList<int> b(8);
  ArrayList<int> c(20);
  ArrayList<int> d(20);
    std::cout<<"Created 4 array lists:\n\array lists b max size "<<a.max_size()<<"\n\tb max size "<<b.max_size()<<"\n\tc max size  "<<c.max_size()<<"\n\td max size "<<d.max_size()<<std::endl<<std::endl;
    b.push_back(5);
    b.push_front(14);
    b.push_back(0);
    b.push_front(17);



for(int i =0; i <5; i++)
       a.push_back(i); 
std::cout <<"After a.push_back(const T& item) :\n\n\t" << a << std::endl<<std::endl;

a.push_back(4);
a.push_back(10);
a.push_back(7); 

std::cout << "Po operacji a.push_back(T&& item) :\n\n\t" << a << std::endl<<std::endl;

int x = 9;
a.push_front(x); 

a.push_front(12); 
std::cout << "After a.push_front(const T& item) oraz push_front(T&& item):\n\n\t" <<  a << std::endl<<std::endl;

std::cout << "First element of list a: " << a.front() << std::endl <<std::endl; // zwraca poczatek listy

std::cout << "Last element of list a: " << a.back() << std::endl <<std::endl; // zwraca koniec listy

a.reverse(); // odwraca kolejnosc listy;
std::cout << "After a.reverse() :\n\n\t" << a << std::endl<<std::endl;

a.sort();
std::cout << "After a.sort() :\n\n\t" << a << std::endl<<std::endl;

a.merge(b); 
std::cout << "After  a.merge(b) :\n\n\t" <<  a << std::endl <<std::endl;

a.erase(3); 
std::cout << "After  a.erase(3) :\n\n\t" << a << std::endl<<std::endl;

std::cout << "Element 9 in array list a has index: " <<  a.index(9) << std::endl<<std::endl;

a.insert(2, 50);
std::cout << "After a.insert(2, 50):\n\n\t" << a << std::endl<<std::endl;

a[4] = 100;
std::cout << "a[4] = 100:\n\n\t" << a << std::endl<<std::endl;
std::cout << "a[2]:\n\n\t" << a[2] << std::endl<<std::endl;



ArrayList<int> list2(a); // 
std::cout <<"Copy constructor ArrayList<int> list2(a):\n\n\t" <<list2 << std::endl<<std::endl;

ArrayList<int> list3(std::move(a)); //konstruktor przenoszacy
std::cout <<"Move constructor ArrayList<int> list3(std::move(a)):\n\n\t"  <<list3 << std::endl<<std::endl;

    c = list2;
std::cout << "c = list2;:\n\n\t"  <<c << std::endl<<std::endl;

d = std::move(list2);
std::cout << "d = std::move(list2):\n\n\t"  <<d << std::endl<<std::endl;

d.clear();
std::cout << "After d.clear: " << d << std::endl;



}
