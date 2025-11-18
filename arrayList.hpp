#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <iostream>

template <typename T> class ArrayList {
private:
    int length=0;
    T *array;

    void overflowError(int index){
        std::cout << "Index " << index << " is too big for ArrayList of size of " << length << "." << std::endl;
        throw std::runtime_error("ArrayList overflow");
        exit;
    }

public:
    /**Get the item from the given index
     *   @param index The index to get the item from
     *   @return The item from the array.*/
    T get(int index){
        if(index>length){
            overflowError(index);
            //return NULL;//just in case the program continues after exit
        }
        return array[index];
    }
    /**Returns the size of the array as an int.
     *   @return The size of the array*/
    int size(){
        return length;
    }
    /**Adds an item to the array at the end.
     *   @param item item to add to the array*/
    void add(T item){
        if(length==0){
            array = new T[1];
            array[0]=item;
            length=1;
            return;
        }
        T* newArray;
        newArray = new T[length+1];
        for(int i=0;i<length;i++){
            newArray[i]=array[i];
        }
        newArray[length]=item;
        array=newArray;
        length++;
    }

    void add(int index, T item){
        //bool passedItem=false;
        T* newArray;
        newArray = new T[length+1];
        for(int i=0;i<length;i++){
            if(i<index)
                newArray[i]=array[i];
            else if(i==index){
                newArray[i]=item;
                newArray[i+1]=item;
            } else{
                newArray[i+1]=item;
            }
        }
        length++;
    }

    /**Adds an item to the array at the given location
     *   @param index The place in the array to place the item
     *   @param item The item to be added to the array*/
    //void add(int index, T item);
    /**Removes an item from the array from the given index.
     *   @param index Where to remove the item from*/
    void remove(int index){
        if(index>length){
            overflowError(index);
            return;
        }
        T* newArray;
        newArray = new T[length-1];
        int pastRemove=0;
        for(int i=0;i<length;i++){
            if(!(i==index))
                newArray[i+pastRemove]=array[i];
            else
                pastRemove=-1;
        }
        array=newArray;
        length--;
    }//end remove

    void remove(T item){//The bool is here so that the compiler does not claim that I am overloading with the exact same function
        for(int i=0;i<length;i++){
            if(array[i]==item){
                remove(i);
                return;
            }
        }
    }//end remove

    /**Gets the array for use*/
    T* toArray(){
        return array;
    }
    /**Sets an item of the array
     *   @param index Where to set the item*/
    void set(int index, T item){
        array[index] = item;
    }
    /**Clears the array.*/
    void clear(){
        length=0;
        array= new T[0];
    }//end clear

    int indexOf(T item){
        for(int i=0;i<length;i++){
            if(array[i]==item)
                return i;
        }
        return -1;
    }//end indexOf

    bool contains(T item){
        for(int i=0;i<length;i++){
            if(array[i]==item)
                return true;
        }
        return false;
    }//end contains

    bool isEmpty(){
        if(length<1)
            return true;
        return false;
    }//end isEmpty


    void test();

};

template <> class ArrayList<int> {
private:
    int length=0;
    int *array;

    void overflowError(int index){
        std::cout << "Index " << index << " is too big for ArrayList of size of " << length << "." << std::endl;
        throw std::runtime_error("ArrayList overflow");
        exit;
    }

public:
    /**Get the item from the given index
     *   @param index The index to get the item from
     *   @return The item from the array.*/
    int get(int index){
        if(index>length){
            overflowError(index);
            //return NULL;//just in case the program continues after exit
        }
        return array[index];
    }
    /**Returns the size of the array as an int.
     *   @return The size of the array*/
    int size(){
        return length;
    }
    /**Adds an item to the array at the end.
     *   @param item item to add to the array*/
    void add(int item){
        if(length==0){
            array = new int[1];
            array[0]=item;
            length=1;
            return;
        }
        int* newArray;
        newArray = new int[length+1];
        for(int i=0;i<length;i++){
            newArray[i]=array[i];
        }
        newArray[length]=item;
        array=newArray;
        length++;
    }

    void add(int index, int item){
        //bool passedItem=false;
        int* newArray;
        newArray = new int[length+1];
        for(int i=0;i<length;i++){
            if(i<index)
                newArray[i]=array[i];
            else if(i==index){
                newArray[i]=item;
                newArray[i+1]=item;
            } else{
                newArray[i+1]=item;
            }
        }
        length++;
    }

    /**Adds an item to the array at the given location
     *   @param index The place in the array to place the item
     *   @param item The item to be added to the array*/
    //void add(int index, T item);
    /**Removes an item from the array from the given index.
     *   @param index Where to remove the item from*/
    void remove(int index){
        if(index>length){
            overflowError(index);
            return;
        }
        int* newArray;
        newArray = new int[length-1];
        int pastRemove=0;
        for(int i=0;i<length;i++){
            if(!(i==index))
                newArray[i+pastRemove]=array[i];
            else
                pastRemove=-1;
        }
        array=newArray;
        length--;
    }//end remove

    /**Gets the array for use*/
    int* toArray(){
        return array;
    }
    /**Sets an item of the array
     *   @param index Where to set the item*/
    void set(int index, int item){
        array[index] = item;
    }
    /**Clears the array.*/
    void clear(){
        length=0;
        array= new int[0];
    }//end clear

    int indexOf(int item){
        for(int i=0;i<length;i++){
            if(array[i]==item)
                return i;
        }
        return -1;
    }//end indexOf

    bool contains(int item){
        for(int i=0;i<length;i++){
            if(array[i]==item)
                return true;
        }
        return false;
    }//end contains

    bool isEmpty(){
        if(length<1)
            return true;
        return false;
    }//end isEmpty


    void test();

};

template <typename T> std::ostream& operator<<(std::ostream &out, ArrayList<T> &data) {
    out << "[";
    T* array = data.toArray();
    for(int i=0;i<data.size();i++){
        if(i!=0)
            out << ", ";
        out << array[i];
    }
    out << "]";
    return out;
}

#endif
