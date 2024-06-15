#include<stdexcept>
#include <algorithm>
template<class T>
RealVector<T>::RealVector() : logical_size(0), array_size(kInitialSize)
{
  elems = new T[array_size];
}

template<class T>
RealVector<T>::RealVector(size_t n, const T& value) : logical_size(n), array_size(2 * n)
{
  elems = new T[array_size];
  std::fill(begin(), end(), value);
}

template<class T>
RealVector<T>::~RealVector()
{
  delete [] elems;
}

template<class T>
size_t RealVector<T>::size() const
{
  return logical_size;
}

template<class T>
bool RealVector<T>::empty() const
{
  return logical_size == 0;
}

template<class T>
typename RealVector<T>::iterator RealVector<T>::begin()
{
  return elems;
}

template<class T>
typename RealVector<T>::iterator RealVector<T>::end()
{
  return begin() + size();
}

template<class T>
typename RealVector<T>::const_iterator RealVector<T>::begin() const
{
  return static_cast<const_iterator>(const_cast<RealVector<T>*>(this)->begin());
}

template<class T>
typename RealVector<T>::const_iterator RealVector<T>::end() const
{
  return static_cast<const_iterator>(const_cast<RealVector<T>*>(this)->end());
}

template<class T>
T& RealVector<T>::operator[](size_t index)
{
  return *(begin() + index);
}

template<class T>
T& RealVector<T>::at(size_t index)
{
  if (index >= logical_size)
    throw std::out_of_range("Out of range.");
  
  return operator[](index);
}

template<class T>
void RealVector<T>::grow()
{
  T* newElems = new T[2 * array_size];
  std::copy(begin(), end(), newElems);
  delete [] elems;
  elems = newElems;
  array_size *= 2;
}

template<class T>
void RealVector<T>::push_back(const T& elem)
{
  if (logical_size == array_size)
    grow();
  
  *end() = elem;
  logical_size++;
}