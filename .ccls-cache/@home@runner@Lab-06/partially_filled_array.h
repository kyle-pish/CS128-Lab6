#ifndef PARTIALLY_FILLED_ARRAY_H_
#define PARTIALLY_FILLED_ARRAY_H_

class PartiallyFilledArray {
  public:
    // One constructor that lets you set the capacity
    PartiallyFilledArray(int capacity);
    ~PartiallyFilledArray();

    // Public methods
    void Append(int new_int);
    int Get(int index);

  private:
    int size_;
    int capacity_;
    
    // This is the array that is backing this PFA.
    // It will be heap-allocated, so it's a pointer.
    int* contents_;
};

void PartiallyFilledArray_main();

#endif