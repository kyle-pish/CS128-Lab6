//Kyle Pish & Josh Reed
//Date: 2/10/2022

#ifndef PARTIALLY_FILLED_ARRAY_H_
#define PARTIALLY_FILLED_ARRAY_H_

class PartiallyFilledArray {
  public:
    // One constructor that lets you set the capacity
    PartiallyFilledArray(int capacity);
    //This constructor takes an int array and its size, then constructs a PFA out of it with twice the capacity of the original
    PartiallyFilledArray(int int_array[], int size);
    ~PartiallyFilledArray();

    // Public methods
    void Append(int new_int);
    int Get(int index);
    int GetSize();
    int GetCapacity();
    bool IsFull();
    void Set(int value, int index);

    void Print();
    bool Contains(int value);
    int Count(int value);
    int Index(int value);
    int Pop();
    int PopAt(int i);
    int Insert(int value, int i);
    void Remove(int value);

  private:
    int size_;
    int capacity_;
    
    // This is the array that is backing this PFA.
    // It will be heap-allocated, so it's a pointer.
    int* contents_;
};

void PartiallyFilledArray_main();

#endif