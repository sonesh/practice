#include "Bag.h"

#include <iostream>  //provides ostream
#include <cassert>   //provides assert

const Bag::size_type Bag::DEFAULT_CAPACITY;

Bag::size_type Bag::count (const value_type& target) const {

  size_type i;
  size_type count = 0;

  for (i = 0; i < used_; i++)
    if (array_[i] == target)
      count++;

  return count;
}

bool Bag::eraseOne (const value_type& target) {

  size_type i = 0;

  for (i = 0; i < used_; i++)
    if (array_[i] == target) {
      --used_;
      array_[i] = array_[used_];
      return true;
    }

  return false;
}

Bag::size_type Bag::erase (const value_type& target) {

  size_type index = 0;
  size_type itemsRemoved = 0;

  while (index < used_) {
    if (array_[index] == target) {
      --used_;
      array_[index] = array_[used_];
      itemsRemoved++;
    } else
      index++;
  }
  
  return itemsRemoved;
}

bool Bag::insert (const value_type& target) {

  if (used_ >= DEFAULT_CAPACITY)
    return false;

  array_[used_] = target;
  ++used_;

  return true;
}

void Bag::operator += (const Bag& other) {

  size_type otherUsed = other.size(); //in case other is this

  if (used_ + otherUsed > DEFAULT_CAPACITY)
    return;

  for (size_type i = 0; i < otherUsed; i++) {
    array_[used_] = other.array_[i];
    ++used_;
  }

}

//Friend functions
std::ostream& operator << (std::ostream& outs, const Bag& bag) {

  Bag::size_type i;
  
  if (bag.used_ == 0) {
    outs << "Empty Bag!" << std::endl;
    return outs;
  }

  for (i = 0; i < bag.used_ - 1; i++)
    outs << bag.array_[i] << " ";

  outs << bag.array_[i] << std::endl;;

  return outs;
}

//Other non member functions
Bag operator + (const Bag& b1, const Bag& b2) {

  assert(b1.size() + b2.size() <= Bag::DEFAULT_CAPACITY);

  Bag sum;

  sum += b1;
  sum += b2;

  return sum;
}




