#include<iostream>
#include"week2_countIntervals.hh"
using namespace std;

int main(){
  //readInput("SmallInput.txt");
  readInput("IntegerArray.txt");
  sortAndCount(test_array);

  cout <<"The number of intervals : "<<intervals <<endl;
}
