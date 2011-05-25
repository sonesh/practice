#ifndef BAG_H_INCLUDED
#define BAG_H_INCLUDED

#include <iostream> //provides ostream
#include <cstdlib>  //provides std:size_t

class Bag {

 public:
  typedef int value_type;
  typedef std::size_t size_type;

  static const size_type DEFAULT_CAPACITY = 30;
  static const size_type DEFAULT_INCREMENT_FACTOR = 2;

  //Constructors
  Bag (int initialCapacity = DEFAULT_CAPACITY);
  Bag (const Bag& other);

  //Destructor
  ~Bag ();

  //Constant member functions
  size_type size () const {return currentSize_;}
  size_type capacity () const {return currentCapacity_;}
  size_type count (const value_type& target) const;

  //Modification member functions
  size_type erase (const value_type& target);
  bool eraseOne (const value_type& target);
  void reserve (const size_type& newCapacity);
  bool insert (const value_type& target);

  //Overloaded operator member functions
  void operator += (const Bag& other);
  void operator =  (const Bag& other);

  //Friend functions
  friend std::ostream& operator << (std::ostream& outs, const Bag& bag);

 private:
  value_type *array_;
  size_type  currentCapacity_;
  size_type  currentSize_;

};

//Non member functions for bag class
Bag operator + (const Bag& other);

#endif
