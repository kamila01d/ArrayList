#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>// assert()
#include <stdexcept>

template <typename T>
class ArrayList {
    T* tab;  // the pointer to array
    int msize; // max number of elements in array
    int last; // the first empty position in array
public:
    ArrayList(int s = 10) : msize(s), last(0) {
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    ~ArrayList() { delete [] tab; }
    ArrayList(const ArrayList& other)
    {
        last = other.last;
        msize = other.msize;
        tab = new T[msize];

       for(int  i = 0; i < msize; ++i)
            tab[i] = other.tab[i];

    }// copy constructor
    // usage:   ArrayList<int> list2(list1);
    ArrayList(ArrayList&& other)// move constructor
    {
        last = other.last;
        msize = other.last;
        tab = other.tab;

        other.last = 0;
        other.msize = 0;
        other.tab = nullptr;
    }
    // usage:   ArrayList<int> list2(std::move(list1));
    ArrayList& operator=(const ArrayList& other)// copy assignment operator, return *this
    {
        delete [] tab;
        last = other.last;
        msize = other.msize;

        tab = new T[msize];

        for(int  i = 0; i < msize; ++i)
            tab[i] = other.tab[i];

        return *this;

    }
    // usage:   list2 = list1;
    ArrayList& operator=(ArrayList&& other) // move assignment operator, return *this
    {
        delete tab;

        last = other.last;
        msize = other.last;
        tab = other.tab;

        other.last = 0;
        other.msize = 0;
        other.tab = nullptr;

        return *this;


    }
    // usage:   list2 = std::move(list1);
    bool empty() const { return last == 0; } // checks if the container has no elements
    bool full() const { return last == msize; } // *///checks if the container is full
    int size() const { return last; } // returns number of elements in array
    int max_size() const { return msize; } // returns max number of elements in array
    void push_front(const T& item); // adds an element at the front
    void push_front(T&& item); //adds an element at the front
    void push_back(const T& item); // adds an item to the end
    void push_back(T&& item); //  adds an item to the end
    T& front(); // returns the first element, does not delete, error if array is empty
    T& back(); // returns the last element, does not delete, error if array is empty
    void pop_front(); // delete first element, error if array is empty
    void pop_back(); // delete last element, error if array is empty
    void clear(); // deletes array from all elements
    void reverse(); // reverse the order of array 
    void sort(); // sorts array
    void merge(ArrayList& other); //  merges two sorted lists into one
    
    int erase(int pos); // return Iterator following the last removed element, removes element tab[pos]
    T& operator[](int pos); //  L[pos]=item
    const T& operator[](int pos) const; // L[pos]
    int index(const T& item); // return index of element in array (-1 when does not ocurr)
    int insert(int pos, const T& item); //inserts item before pos
  
    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        os << "[";
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        os << "]";
        return os;
    }
    // usage:   std::cout << L << std::endl;
};

template <typename T>
void ArrayList<T>::push_front(const T& item) {
    if(last+1 > msize)
    {
        std::cout<< "Array list is full. Cannot add new element.";
        return;
    }
    if (last == 0){
        tab[last] = item;
        ++last;
        return;
    }
   else {
        for (int i = last; i >= 0; i--) {
            tab[i + 1] = tab[i];

        }
        tab[0] = item;
        ++last;
    }
}
template <typename T>
void ArrayList<T>::push_front(T&& item){
    if(last+1 > msize)
    {
        std::cout<< "Array list is full. Cannot add new element.";
        return;
    }
    if (last == 0){
        tab[last] = item;
        ++last;

        return;
    }
    else {
        for (int i = last; i >= 0; i--) {
            tab[i + 1] = tab[i];

        }
        tab[0] = item;
        ++last;
    }
}
template <typename T>
void ArrayList<T>::push_back(const T& item)
{
    if(last+1 > msize)
    {
        std::cout<< "Array list is full. Cannot add new element.";
        return;
    }
    if (last == 0){
        tab[last] = item;
        last++;

        return;
    }
    tab[last] = item;
    last++;
}
template <typename T>
void ArrayList<T>::push_back(T &&item) {
    if(last+1 > msize)
    {
        std::cout<< "Array list is full. Cannot add new element.";
        return;
    }
    if (last == 0){
        tab[last] = item;
        last++;
        return;
    }
    tab[last] = item;
    last++;
}
template <typename T>
void ArrayList<T>::pop_front()
{
    if(empty())
        std::cout<<"Array list is empty!"<<std::endl;

    else
    {
        for(int i = 1; i < last; i++)
            tab[i-1] = tab[i];

        last--;
    }
}
template <typename T>
void ArrayList<T>::pop_back() {
    if(empty())
        std::cout<<"Array list is empty!"<<std::endl;
    else
    {
        last --;
    }
}
template <typename T>
void ArrayList<T>::clear() {
    if(empty())
        std::cout<<"Array list is empty!"<<std::endl;

    else
    {
        last = 0;
    }
}
template <typename T>
void ArrayList<T>::reverse() {
    if(empty())
        std::cout<<"Array list is empty!"<<std::endl;
    else if(size()==1)
        return;

    else {
        T *temp= new T[size()];

        for(int i = 0; i < last; i++ )
        {
            temp[i] = tab[last-1-i];

        }
        tab = temp;
    }

}
template <typename T>
void ArrayList<T>::sort() {

    if(empty()) {
        std::cout << "Array list is empty!" << std::endl;
        return;
    }
    else {
        int i;
        int min;

        for (i = 0; i < last; i++) {
            min = i;

            for (int j = i + 1; j < last; j++)
                if (tab[min] > tab[j])
                    min = j;
            std::swap(tab[min], tab[i]);
        }
    }
}
template <typename T>
int ArrayList<T>::erase(int pos) {
    if (size() == 0)
        return -1;

    else if (pos == last - 1) {
        last--;
        return -1;
    } else {
        int i = pos;
        int j = 1;
        while (i != last) {

            tab[i] = tab[pos + j];
            j++;
            i++;
        }
        last --;
        return pos;

    }
}
template <typename T>
int ArrayList<T>::index(const T &item) {

    for(int i = 0; i < last; i++)
    {
        if(tab[i] == item)
            return i;
    }
    return -1;
}
template <typename T>
int ArrayList<T>::insert(int pos, const T& item){


    if(pos > size())
        return -1;

    else if(pos == 0) {
        for (int i = last; i >= 0; i--) {
            tab[i + 1] = tab[i];

        }
        tab[0] = item;
        ++last;
        return pos;
    }
     else if(pos == size())
    {
        tab[last] = item;
        last++;
        return pos;
    }
    else {
        for (int i = last; i >= pos; i--) {
            tab[i + 1] = tab[i];

        }
        last++;
        tab[pos] = item;

        return pos;
    }
}
template <typename T>
T& ArrayList<T>::front()
{
    if( empty()) {

        int ret = -1;
        T& rett = static_cast<T&>(ret);
        return rett;
    }
    else {

        return tab[0];
    }



}
template <typename T>
T& ArrayList<T>::back()
{
    if( empty()) {
        int ret = -1;
        T& rett = static_cast<T&>(ret);
        return rett;
    } else {

        return tab[last - 1];
    }
}
template <typename T>
void ArrayList<T>::merge(ArrayList<T> &other) {
    int i = 0, j = 0, k = 0;

    T *arr = new T[max_size()+other.max_size()];
    int oLast = other.size();
    while (i<last && j <oLast)
    {

        if (tab[i] < other[j])
            arr[k++] = tab[i++];
        else
            arr[k++] = other[j++];
    }
    while (i < last)
        arr[k++] = tab[i++];


    while (j < other.last)
        arr[k++] = other.tab[j++];
    
    tab = new T[msize+other.max_size()];
    tab = arr;
    msize = msize + other.max_size();
    last = last + other.size();
    this->sort();
}
template <typename T>
T& ArrayList<T>::operator[](int pos)
{
    if (pos >= last){
        int ret = -1;
        T& rett = static_cast<T&>(ret);
        return rett;
    }
    T& ret = tab[pos];
    return ret;
}
template <typename T>
const T& ArrayList<T>::operator[](int pos) const{
    if (pos >= last){
        int ret = -1;
        const T& rett = static_cast<const T&>(ret);
        return rett;
    }
    return &tab[pos];
}
#endif

// EOF
