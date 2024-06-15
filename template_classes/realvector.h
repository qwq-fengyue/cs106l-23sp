#ifndef RealVector_H
#define RealVector_H

#include <string>
#include <algorithm>
#include <stdexcept>


template<typename T> 
class RealVector {
public:
    using iterator = T*;
    using const_iterator = const T*;

    const int kInitialSize = 2;

     RealVector();
     RealVector(size_t n, const T& value);

     ~RealVector();



    // size empty [] at push_back
    size_t size() const;
    bool empty() const;

    T& operator[] (size_t index);
    T& at (size_t index);

    void push_back(const T& elem);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    
private:
    void grow();
    T* elems;
    size_t logical_size;
    size_t array_size;
  
};

// Important: For template classes, include the .cpp at the bottom of the .h instead of including the .h in the top of the .cpp
#include "realvector.cpp"

#endif // RealVector_H