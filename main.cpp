#include <iostream>
#include "array.h"
#include <cassert>
#include <stdexcept>

int main() {

  ArrayList<int> a(16);
  ArrayList<int> b(8);
  ArrayList<int> c(20);
  ArrayList<int> d(20);
    std::cout<<"Utworzono 4 tablice:\n\ta o maksymalnym rozmiarze "<<a.max_size()<<"\n\tb o maksymalnym rozmiarze "<<b.max_size()<<"\n\tc o maksymalnym rozmiarze "<<c.max_size()<<"\n\td o maksymalnym rozmiarze "<<d.max_size()<<std::endl<<std::endl;
    b.push_back(5);
    b.push_front(14);
    b.push_back(0);
    b.push_front(17);



for(int i =0; i <5; i++)
       a.push_back(i); //dodanie elementu na koniec listy, push_back(const T& item)
std::cout <<"Po operacji push_back(const T& item)na tablicy a:\n\n\t" << a << std::endl<<std::endl;

a.push_back(4);
a.push_back(10);
a.push_back(7); // dodanie elementu na koniec listy, push_back(T&& item)

std::cout << "Po operacji push_back(T&& item) na tablicy a:\n\n\t" << a << std::endl<<std::endl;

int x = 9;
a.push_front(x);  //dodanie elementu na poczatek listy, push_front(const T& item)

a.push_front(12); //dodanie elementu na poczatek listy, push_front(T&& item)
std::cout << "Po operacjach push_front(const T& item) oraz push_front(T&& item):\n\n\t" <<  a << std::endl<<std::endl;

std::cout << "Poczatek listy a: " << a.front() << std::endl <<std::endl; // zwraca poczatek listy

std::cout << "Koniec listy a: " << a.back() << std::endl <<std::endl; // zwraca koniec listy

a.reverse(); // odwraca kolejnosc listy;
std::cout << "Po operacji reverse() na liscie a:\n\n\t" << a << std::endl<<std::endl;

a.sort();
std::cout << "Po operacji sort() na liscie a:\n\n\t" << a << std::endl<<std::endl;

a.merge(b); // scala dwie posortowane listy w jedna
std::cout << "Po opercji merge na liscie a:\n\n\t" <<  a << std::endl <<std::endl;

a.erase(3); //usuwa element na 3 indeksie w liscie
std::cout << "Po opercji erase(3) na liscie a:\n\n\t" << a << std::endl<<std::endl;

std::cout << "Zwracanie indeksu szukanej wartosci(9) w liscie a: " <<  a.index(9) << std::endl<<std::endl;

a.insert(2, 50);
std::cout << "Po operacji insert(2, 50):\n\n\t" << a << std::endl<<std::endl;

a[4] = 100;
std::cout << "Po podstawieniu a[4] = 100:\n\n\t" << a << std::endl<<std::endl;
std::cout << "Odczyt wybranego elementu a[2]:\n\n\t" << a[2] << std::endl<<std::endl;
//std::cout << a << std::endl;


ArrayList<int> list2(a); // konstruktor kopiujacy
std::cout <<"Po wywolaniu konstruktora kopiujacego ArrayList<int> list2(a):\n\n\t" <<list2 << std::endl<<std::endl;

ArrayList<int> list3(std::move(a)); //konstruktor przenoszacy
std::cout <<"Po wywolaniu konstruktora przenoszacego ArrayList<int> list3(std::move(a)):\n\n\t"  <<list3 << std::endl<<std::endl;

    c = list2;
std::cout << "Po wywolaniu kopiujacego operatora przypisania c = list2;:\n\n\t"  <<c << std::endl<<std::endl;

d = std::move(list2);
std::cout << "Po wywolaniu kopiujacego operatora przypisania d = std::move(list2):\n\n\t"  <<d << std::endl<<std::endl;

d.clear();
std::cout << "Lista d po operacji clear: " << d << std::endl;



}
