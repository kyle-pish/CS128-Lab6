//Kyle Pish & Josh Reed
//Date: 2/10/2022

#include <iostream>
#include "partially_filled_array.h"

// Create an empty PartiallyFilledArray with the specified capacity.
PartiallyFilledArray::PartiallyFilledArray(int capacity) {
  // Note that we do not bother initializing the array values, since the PFA is empty.
  this->contents_ = new int[capacity];   // heap-allocation
  this->size_ = 0;
  this->capacity_ = capacity;
}

//Create a PartiallyFilledArray containing the values in the input array and capacity equal to twice the size of the input array.
PartiallyFilledArray::PartiallyFilledArray(int int_array[], int size) {

  this->contents_ = new int[size * 2];
  for (int i = 0; i < size; i++) {
    this->contents_[i] = int_array[i]; //Intializig the heap PFA to the values of the input array
  }
}

// Destroy this PFA and deallocate its heap data.
// Notice that we need to delete[] the array
// because it is heap-allocated.
PartiallyFilledArray::~PartiallyFilledArray() {
  delete[] this->contents_;
}

// Add new_int to the end of this PFA if there's capacity for it. Otherwise, do nothing.
void PartiallyFilledArray::Append(int new_int) {
  if (this->size_ < this->capacity_) {
    this->contents_[this->size_] = new_int;
    this->size_++;
  }
}

// Return the int at the specified index. Otherwise, return -1.
int PartiallyFilledArray::Get(int index) {
  if (index >= 0 && index < this->size_) {
    return this->contents_[index];
  }
  else {
    // To be safe here, we ideally would throw an error or an exception.
    return -1;
  }
}

int PartiallyFilledArray::GetSize() {
  return this->size_;
}

int PartiallyFilledArray::GetCapacity() {
  return this->capacity_;
}

bool PartiallyFilledArray::IsFull() {
  if (this->size_ == this->capacity_) {
    return true;
  }

  else {
    return false;
  }
}

void PartiallyFilledArray::Set(int value, int index) {
  this->contents_[index] = value;
}

//Output to console every value in the array, surrounded by brackets and separated by spaces.
void PartiallyFilledArray::Print() {
  std::cout << "[";
  for (int i = 0; i < this->size_; i++) {
    std::cout << this->contents_[i] << " ";
    }
  std::cout << "]" << std::endl;
}

//Returns true if a specified value is in the array, and false otherwise.
bool PartiallyFilledArray::Contains(int value) {
  for (int i = 0; i < this->size_; i++) {
    if (this->contents_[i] == value) {
      return true;
    }
  }

  return false;
}

//Returns the number of times a given value is in the array as an int.
int PartiallyFilledArray::Count(int value) {
  int output = 0;
  for (int i = 0; i < this->size_; i++) {
    if (this->contents_[i] == value) {
      output++;
    }
  }

  return output;
}

//Returns the index of the first instance of the specified value in the array as an int; if the value is not present, returns -1.
int PartiallyFilledArray::Index(int value) {
  for (int i = 0; i < this->size_; i++) {
    if (this->contents_[i] == value) {
      return i;
    }
  }

  return -1;
}

//Removes and returns the last element in a given array. Takes as input an int partially-filled array, and its size, which is taken as a reference.
int PartiallyFilledArray::Pop() {
  this->size_--;
  return this->contents_[this->size_];
}

//Removes and returns the element at index i in the array. If i is an invalid index, returns -1.
int PartiallyFilledArray::PopAt(int i) {
  if (i > this->size_) {
    return -1;
  }
  int output = this->contents_[i];
  for (int j = i; j < this->size_; j++) {
    this->contents_[j] = this->contents_[j + 1];
  }
  this->size_--;
  return output;
}

//Adds a given value into the array at a given index, provided there's sufficient capacity for it. If there is, returns 0, otherwise returns -1. Takes as input the desired index and the desired value.
int PartiallyFilledArray::Insert(int value, int i) {
  if (i > this->size_) {
    return -1;
  }
  if (!this->IsFull()) {
    for (int j = this->size_; j > i; j--) {
      this->contents_[j] = this->contents_[j - 1];
    }

    this->contents_[i] = value;
    this->size_++;

  }

  return 0;
}

void PartiallyFilledArray::Remove(int value) {
  int index = this->Index(value);
  this->PopAt(index);
}


//These are tests for the PFA methods
void PFA_testing() {
  PartiallyFilledArray PFA = PartiallyFilledArray(10);

  PFA.Append(2);
  PFA.Append(4);
  PFA.Append(6);
  PFA.Append(8);
  PFA.Append(6);
  PFA.Append(4);
  PFA.Append(2);
  
  PFA.Print();
  std::cout << PFA.Contains(4) << std::endl;
  std::cout << PFA.Contains(5) << std::endl;

  std::cout << PFA.Count(6) << std::endl;
  std::cout << PFA.Count(7) << std::endl;

  std::cout << PFA.Index(8) << std::endl;

  std::cout << PFA.Pop() << std::endl;
  PFA.Print();

  std::cout << PFA.PopAt(2) << std::endl;
  PFA.Print();

  PFA.Append(12);
  PFA.Print();

  PFA.Insert(-9, 3);
  PFA.Print();

  PFA.Remove(2);
  PFA.Print();

  for (int i = 0; i < 10; i++) {
    PFA.Append(99);
  }

  PFA.Print();
 
}

// This main function exercises the PartiallyFilledArray class.
void PartiallyFilledArray_main() {
  std::cout << "This is PartiallyFilledArray_main()." << std::endl << std::endl;

  PartiallyFilledArray pfa1 = PartiallyFilledArray(10);

  pfa1.Append(7);
  pfa1.Append(17);
  pfa1.Append(27);
  pfa1.Append(37);
  pfa1.Append(47);
  pfa1.Append(57);

  for (int i=0; i<pfa1.GetSize(); i++) {     // When GetSize() is finished, uncomment this line
  //for (int i=0; i<6; i++) {                    // and comment out this line instead.
    std::cout << pfa1.Get(i) << std::endl;
  }

  std::cout << "Is there still room in my PFA? " << (pfa1.GetSize() < pfa1.GetCapacity()) << std::endl;

  pfa1.Append(67);
  pfa1.Append(77);
  pfa1.Append(87);
  pfa1.Append(97);

  std::cout << "Is my PFA full? " << pfa1.IsFull() << std::endl;
  pfa1.Append(107);

  for (int i=0; i<pfa1.GetSize(); i++) {     // When GetSize() is finished, uncomment this line
  //for (int i=0; i<10; i++) {                    // and comment this line instead.
    std::cout << pfa1.Get(i) << std::endl;
  }  

  pfa1.Print();  // Uncomment this line when Print() is finished.


  std::cout << "Some PFA Tests:" << std::endl;

  PFA_testing();
}