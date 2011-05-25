#include "Bag.h"

#include <iostream>  //provides ostream
#include <cassert>   //provides assert

#include <algorithm> //provides copy

const Bag::size_type Bag::DEFAULT_CAPACITY;
const Bag::size_type Bag::DEFAULT_INCREMENT_FACTOR;

Bag::Bag (int initialCapacity) {
  array_           = new value_type[initialCapacity];
  currentSize_     = 0;
  currentCapacity_ = initialCapacity;
}

Bag::Bag (const Bag& other) {

  array_           = new value_type[other.capacity()];
  currentSize_     = other.size();
  currentCapacity_ = other.capacity();

  for (size_type i = 0; i < currentSize_; i++)
    array_[i] = other.array_[i];
}

Bag::~Bag () {
  delete [] array_;
}

Bag::size_type Bag::count (const value_type& target) const {

  size_type itemsFound = 0;

  for (size_type i = 0; i < currentSize_; i++)
    if (array_[i] == target)
      itemsFound++;

  return itemsFound;
}

Bag::size_type Bag::erase (const value_type& target) {

  size_type currentIndex = 0;
  size_type itemsErased  = 0;

  while (currentIndex < currentSize_) {
    if (array_[currentIndex] == target) {
      array_[currentIndex] = array_[--currentSize_];
      itemsErased++;
    } else
      currentIndex++;
  }
    
  return itemsErased;
}

bool Bag::eraseOne (const value_type& target) {

  for (size_type i = 0; i < currentSize_; i++)
    if (array_[i] == target) {
      array_[i] = array_[--currentSize_];
      return true;
    }

  return false;
}

void Bag::reserve (const size_type& newCapacity) {

  value_type *largerArray = NULL;

  if (newCapacity <= currentCapacity_)
    return;

  largerArray = new value_type[newCapacity];

  for (size_type i = 0; i < currentSize_; i++)
    largerArray[i] = array_[i];

  delete [] array_;
  array_ = largerArray;
  currentCapacity_ = newCapacity;
}

bool Bag::insert (const value_type& target) {

  assert (currentSize_ <= currentCapacity_);

  if (currentSize_ == currentCapacity_)
    reserve (DEFAULT_INCREMENT_FACTOR * currentCapacity_);

  array_[currentSize_] = target;
  currentSize_++;
}

void Bag::operator += (const Bag& other) {

  size_type mySize       = currentSize_;
  size_type otherSize    = other.currentSize_;
  size_type newTotalSize = mySize + otherSize;

  if (newTotalSize > currentCapacity_)
    reserve(newTotalSize);

  for (size_type i = 0; i < otherSize; i++) {
    array_[i + mySize] = other.array_[i];
    ++currentSize_;
  }
  
  //copy (other.array_, other.array_ + otherSize; array_ + mySize);
  //currentSize_ += otherSize;
}

void Bag::operator = (const Bag& other) {

  if (this == &other)
    return;

  if (currentCapacity_ != other.currentCapacity_) {
    value_type *largerArray = new value_type[other.currentCapacity_];
    delete [] array_;
    array_ = largerArray;
    currentCapacity_ = other.currentCapacity_;
  }
  
  for (size_type i = 0; i < other.currentSize_; i++)
    array_[i] = other.array_[i];

  currentSize_ = other.currentSize_;
}

std::ostream& operator << (std::ostream& outs, const Bag& bag) {

  if (bag.currentSize_ == 0) {
    outs << "Empty Bag" << std::endl;
    return outs;
  }

  Bag::size_type index = 0;
  Bag::size_type limit = bag.currentSize_ - 1;;

  for (index = 0; index < limit; index++)
    outs << bag.array_[index] << " ";

  outs << bag.array_[index] << std::endl;

  return outs;
}

Bag operator + (const Bag& b1, const Bag& b2) {

  Bag sum (b1.capacity() + b2.capacity());

  sum += b1;
  sum += b2;

  return sum;
}

