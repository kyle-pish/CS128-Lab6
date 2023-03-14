//Kyle Pish & Josh Reed
//Date: 2/10/2022

#include <iostream>
#include "two_numbers.h"
#include <random>

//default constructor to call random
TwoNumbers::TwoNumbers() {
  TwoNumbers::randomize();
}

//assigns the input numbers to variables in the class
TwoNumbers::TwoNumbers(int num1, int num2) {
  this->number1_ = num1;
  this->number2_ = num2;
  guesses_ = 0;
}


TwoNumbers::~TwoNumbers() {
  
}

//calculate sum of the numbers of this object
int TwoNumbers::GetSum(){
  return this->number1_ + this->number2_;
}

//calculate difference of the numbers of this object
int TwoNumbers::GetDifference(){
  return this->number1_ / this->number2_;
}

//calculate producct of the numbers of this object
int TwoNumbers::GetProduct(){
  return this->number1_ * this->number2_;
}

//take the input numbers and compare them to the randomized numbeers
bool TwoNumbers::GuessNumbers(int num1, int num2){

  //if the numbers are guessed correctly, regaurdless of order, it tells the user they are correct
  //and outputs how many guesses it took and rereandomizes
  if ((num1 == this->number1_ || num1 == this->number2_) && (num2 == this->number1_ || num2 == this->number2_)){
    std::cout<<"Good guess! This puzzle took you " << this->guesses_ << " guesses!" << std::endl;
    randomize();
    return true;
  }

    //if guess is wrong it tells the user and adds to the count of how many guesses
    else{
      std::cout<<"Incorrect" << std::endl;
      this->guesses_++;
      return false;
    }
}

//Code segment copied from Lab 2 to assign random values to the variables
void TwoNumbers::randomize(){
  std::mt19937 generator(std::random_device{}());

  std::uniform_int_distribution<int> distribution(0, 100);


  this->number1_ = distribution(generator); 
  this->number2_ = distribution(generator);
  //TwoNumbers::number1_ = distribution(generator); 
  //TwoNumbers::number2_ = distribution(generator); 

  std::cout << TwoNumbers::number1_ << std::endl;
  std::cout << TwoNumbers::number2_ << std::endl;

  TwoNumbers::guess_ = 0;
}


void TwoNumbers_main() {

  //testing to make sure the sum, difference, and product methods work properly
  TwoNumbers test_tn = TwoNumbers(10, 20);
  std::cout << test_tn.GetSum() << std::endl;
  std::cout << test_tn.GetDifference() << std::endl;
  std::cout << test_tn.GetProduct() << std::endl;

  TwoNumbers test_tn2 = TwoNumbers(50, 10);
  std::cout << test_tn2.GetSum() << std::endl;
  std::cout << test_tn2.GetDifference() << std::endl;
  std::cout << test_tn2.GetProduct() << std::endl;

  //call TwoNumbers method to run the random method
  TwoNumbers();

  //following code copied from two_numbers_main.txt provided by Mark Liffiton
  TwoNumbers my_two_numbers = TwoNumbers(7, 13);
  int guess1;
  int guess2;

  //gives user hints by outputing calculations using the randomly assigned numbers
  std::cout << "Sum: " << my_two_numbers.GetSum() << std::endl;
  std::cout << "Difference: " << my_two_numbers.GetDifference() << std::endl;
  std::cout << "Product: " << my_two_numbers.GetProduct() << std::endl;

  //while the user still has not guessed the numbers, it will keep asking the user to guess
  while (true) {
    std::cout << std::endl << "Guess the numbers!" << std::endl;

    std::cin >> guess1;
    std::cin >> guess2;

    //once the user guesses the corret numers it will tell them that new numbers have been generated
    if (my_two_numbers.GuessNumbers(guess1, guess2)) {
      std::cout << std::endl << "New numbers generated!" << std::endl;
      std::cout << "Sum: " << my_two_numbers.GetSum() << std::endl;
      std::cout << "Difference: " << my_two_numbers.GetDifference() << std::endl;
      std::cout << "Product: " << my_two_numbers.GetProduct() << std::endl;
    }
  }

}