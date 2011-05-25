#ifndef BAG_H_INCLUDED
#define BAG_H_INCLUDED

#include <cstdlib>   //provided std:size_t
#include <iostream>  //provides ostream

class Bag {

 public:
  typedef int value_type;
  typedef std::size_t size_type;
  
  static const size_type DEFAULT_CAPACITY = 30;

  //Constructor
  Bag () {used_ = 0;}

  //Constant member functions
  size_type size () const {return used_;}

  size_type count (const value_type& target) const;

  //Modification member functions
  bool eraseOne (const value_type& target);

  size_type erase (const value_type& target);

  bool insert (const value_type& target);

  void operator += (const Bag& other);

  //friend functions
  friend std::ostream& operator << (std::ostream& outs, const Bag& bag);

 private:
  value_type array_[DEFAULT_CAPACITY];
  size_type  used_;
};

//NON member functions for bag class
Bag operator + (const Bag& b1, const Bag& b2);

#endif
