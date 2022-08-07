#ifndef SET_H
#define SET_H

#include<iostream>
#include<ostream>

using namespace std;

template <typename T>

class Set{
private:
    int capacity;
    int size;
    T* element;
public:
    Set(){
        size = 0;
        capacity = 10;
        element = new T[capacity]();
    }

    Set(int cap, int siz){
        size = siz;
        capacity = cap;
        element = new T[cap];
    }

    Set(int cap, int siz, T* elem){
        delete [] element;

        size = siz;
        capacity = cap;
        element = new T[cap];

        for(int i=0; i<siz; i++){
            element[i] = elem[i];
        }
    }

    Set(const Set& nev){

        element = new T[nev.capacity];
        size = nev.size;
        capacity = nev.capacity;

        for(int i=0; i<size; i++){
            element[i] = nev.element[i];
        }
    }

    ~Set(){
        delete [] element;
    }

//---------------------------- Functions For Class

    void addElement(T nev){
        // Variable to check if nev is on the list
        int here = 0;
        if(size < capacity){
            // Checks if nev is already on the list
            for(int i=0; (i<size) && (here == 0); i++){
                if(element[i] == nev)
                    here = 1;
            }

            // if here variable is not toggled, there is no nev element in this array
            if(!here){
                element[size] = nev;
                size++;
            }
        }
        else    cout << "Size error!";
    }

    void removeElement(T thatOne){
        // Control variable to check if element array has thatOne
        int flag = -1;

        // Searches element array to find thatOne
        for(int i=0; i<size || flag == -1; i++){
            // If there exist thatOne in a array, takes its position and removes one from size
            if( element[i] == thatOne ){
                flag = i;
                size--;
            }
        }

        // Actual removing is here.
        // Flag value does not change means thatOne does not in the array
        if(flag == -1)  cout << "Not found!";
        else{
            // Moves every element left to remove thatOne from element array
            for(int i=flag; i<size; i++){
                element[i] = element[i+1];
            }
        }
    }


//---------------------------- Operator Overloadings

    Set& operator+(const Set& nev){
        // In case default capacity not enough, sums both arrays capacities
        int cap = capacity + nev.capacity;
        // Creates new Set to fill and return at the end
        Set *elem = new Set(cap,0);

        // Starts to add elements Set from left hand side of the equation
        for(int i=0; i<size; i++){
            elem->addElement( element[i] );
        }

        // Continues to add elements Set from right hand side of the equation
        for(int i=0; i<nev.size; i++){
            elem->addElement(nev.element[i]);
        }
        return *elem;
    }

    Set& operator-(const Set& nev){
        // Creates a new Set to collect different elements and return it.
        Set *diff = new Set(capacity, size, element);

        // Travest arrays to find element differences
        for(int i =0; i<size; i++){
            for(int j=0; j<nev.size; j++){
                // If element from both array are not same, add them to new Set
                if(element[i] == nev.element[j]){
                    diff->removeElement(element[i]);
                }
            }
        }
        return *diff;
    }

    bool operator==(const Set& nev){
        // our flag variable to check and return the result
        bool temp = true;

        // Create new pointers to sort so that comparision would be easy.
        T* t1 = sort(element,size);
        T* t2 = sort(nev.element, nev.size);

        // If size is different, no need to check elements for equality
        if(size != nev.size)    temp = false;
        else{
            // Checks equality
            for(int i = 0; (i<size) && (temp == true); i++){
                if(t1[i] != t2[i])
                    temp = false;
            }
        }

        return temp;
    }

    bool operator!=(const Set& nev){
        /*bool temp = false;

        T* t1 = sort(element,size);
        T* t2 = sort(nev.element, nev.size);

        if(size != nev.size)    temp = true;
        else{
            for(int i = 0; i<size; i++){
                if(t1[i] != t2[i])
                    temp = false;
            }
        }

        return temp;
        */
        return !(*this == nev);     // Result would be same as that. No need to code extra lines
    }

    Set operator=(const Set& nev){
        if(*this != nev){
            element = new T[nev.capacity]();

            size = nev.size;
            capacity = nev.capacity;

            for(int i =0; i<nev.size; i++){
                element[i] = nev.element[i];
            }
        }

        return *this;
    }

    Set& operator+=(const Set& nev){

        int cap = capacity + nev.capacity;

        Set *elem = new Set(cap,0);     // Set to return
        Set *same = new Set(cap,0);     // Set to collect common elements
        Set *diff = new Set(cap,0);     // Set to collect different elements

        for(int i =0; i<size; i++){
            for(int j=0; j<nev.size; j++){
                if(element[i] == nev.element[j]){   // To common different elements
                    same->addElement(element[i]);
                }
                else{                               // To collect different elements
                    diff->addElement(element[i]);
                    diff->addElement(nev.element[j]);
                }
            }
        }

        // for loops to fill elem in a corretr order to return
        for(int i=0; i<same->size; i++){
            elem->addElement( same->element[i] );
        }

        for(int i=0; i<diff->size; i++){
            elem->addElement(diff->element[i]);
        }

        return *elem;
    }

    bool operator<(const Set& nev){
        // Our control variable to check
        int count = 0;

        // Checks if there is nev has *this inside it
        for(int i =0; i<size; i++){
            for(int j =0; j<nev.size; j++){
                if(element[i] == nev.element[j]){
                    count++;
                }
            }
        }

        if(count == size)   return true;
        else                return false;
    }

    friend ostream& operator<<(ostream& os, Set nev){
        os << "{";

        // If size = 0, prints " }" and return that
        if(nev.size == 0)   os << " }";
        else{
            // If size is bigger than 0, prints all elements with comma between
            for(int i=0; i<nev.size; i++){
                os << nev.element[i];

                // If i is last element, prints "}" otherwise contunie with comma
                if(i == (nev.size-1) )  os << "}";
                else                    os << ", ";
            }
        }
        return os;
    }

    friend istream& operator>>(istream& is, Set& nev){
        // Our value that taken from user to be added in nev.element
        T added;

        // For loop to fill nev.element with user inputs
        for(int i=nev.size; i<nev.capacity; i++){
            cout << i+1 << ". element: ";
            is >> added;
            nev.addElement(added);
        }
        return is;
    }

//---------------------------- EXTRA
    // One of the easiest way to sorl a array is a selection sort
    // Use that to sort element array of the class to ease tha operations
    T* sort(T arr[], int siz) {
        T min, temp;
        for (int i = 0; i < siz - 1; i++) {
            min = i;
            for (int j = i + 1; j < siz; j++){
                if (arr[j] < arr[min]){
                    min = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        return arr;
    }
};

#endif // SET_H
