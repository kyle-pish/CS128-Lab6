#include <iostream>
#include "partially_filled_array.h"

// Create an empty PartiallyFilledArray with the specified capacity.
PartiallyFilledArray::PartiallyFilledArray(int capacity) {
  // Note that we do not bother initializing the array values, since the PFA is empty.
  this->contents_ = new int[capacity];   // heap-allocation
  this->size_ = 0;
  this->capacity_ = capacity;
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

  //for (int i=0; i<pfa1.GetSize(); i++) {     // When GetSize() is finished, uncomment this line
  for (int i=0; i<6; i++) {                    // and comment out this line instead.
    std::cout << pfa1.Get(i) << std::endl;
  }

  //std::cout << "Is there still room in my PFA? " << (pfa1.GetSize() < pfa1.GetCapacity()) << std::endl;

  pfa1.Append(67);
  pfa1.Append(77);
  pfa1.Append(87);
  pfa1.Append(97);

  //std::cout << "Is my PFA full? " << pfa1.IsFull() << std::endl;
  pfa1.Append(107);

  //for (int i=0; i<pfa1.GetSize(); i++) {     // When GetSize() is finished, uncomment this line
  for (int i=0; i<10; i++) {                    // and comment this line instead.
    std::cout << pfa1.Get(i) << std::endl;
  }  

  //pfa1.Print();  // Uncomment this line when Print() is finished.
}