//
// Created by Akiva on 2019-11-25.
//

#ifndef DATASTRUCTURESWETHW1_ARRAY_H
#define DATASTRUCTURESWETHW1_ARRAY_H

#include <iostream>
template<typename T>
class Array {
private:
    unsigned int size;
    T *arr;

public:
    //ctor
    explicit Array(unsigned int size);

    //dtor
    virtual ~Array();

    //copy ctor
    Array(const Array &original);

    //operator=
    Array &operator=(const Array &original);

    //operator[]
    T &operator[](unsigned int index);

    //get Array's size
    unsigned int getSize() const {
        return size;
    }

    //copies array to a newly allocated one.
    T *toCArray() const;

    //merges 2 Arrays of pointers based on content of pointers, sorting
    // smallest to largest
    Array<T> merge(Array<T> source);
};


//-------IMPLEMENTATIONS-------

template<typename T>
Array<T>::Array(unsigned int size):size(size) {
    arr = new T[size];
}

template<typename T>
Array<T>::~Array() {
    delete[] (arr);
}

template<typename T>
Array<T>::Array(const Array &original): size(original.size), arr(new T[size]){
    //arr = new T[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = original.arr[i];

    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &original) {
    delete[] arr;
    size = original.size;
    arr = new T[original.size];
    for (int i = 0; i < original.size; ++i) {
        arr[i] = original.arr[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
    return arr[index];
}

template<typename T>
T *Array<T>::toCArray() const {
    T *result = new T[size];
    for (int i = 0; i < size; ++i) {
        result[i] = (*this)[i];
    }
    return result;
}

template<typename T>
Array<T> Array<T>::merge(Array<T> source) {
    Array<T> output = Array(this->getSize() + source.getSize());
    unsigned int index1 = 0, index2 = 0; //start at beginning of both Arrays
    for (int i = 0; i < output.getSize(); ++i) {
        if (index1 == this->getSize() ||
            (index2 < source.getSize() &&
             (*((*this)[index1]) > *(source[index2])))) {

            output[i] = source[index2++];
        } else {
            output[i] = (*this)[index1++];
        }
    }

    return output;
}


#endif //DATASTRUCTURESWETHW1_ARRAY_H
