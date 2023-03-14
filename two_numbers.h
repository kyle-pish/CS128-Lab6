//Kyle Pish & Josh Reed
//Date: 2/10/2022

#ifndef TWO_NUMBERS_H_
#define TWO_NUMBERS_H_

class TwoNumbers{
  public:
    //public methods
    TwoNumbers();
    TwoNumbers(int num1, int num2);
    ~TwoNumbers();

    int GetSum();
    int GetDifference();
    int GetProduct();
    bool GuessNumbers(int num1, int num2);
    void randomize();

  private:
    //private variales
    int number1_;
    int number2_;
    int guess_;
    int guesses_;

};

void TwoNumbers_main();

#endif
