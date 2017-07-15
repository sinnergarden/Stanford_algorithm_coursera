#include<iostream>
#include"week3_quickSort.hh"
using namespace std;

int main(){
  //init(20);
  readInput(".txt");  
  //Three different ways of choosing pivot.
  quick_sort_compare = 0;
  myQuickSort(test_array);
  cout << "The comparation made by QuickSort(1st) is : "
       <<quick_sort_compare <<endl;

  quick_sort_compare = 0;
  myQuickSort(test_array);
  cout << "The comparation made by QuickSort(final) is : "
       <<quick_sort_compare <<endl;

  quick_sort_compare = 0;
  myQuickSort(test_array);
  cout << "The comparation made by QuickSort(median of 3) is : "
       <<quick_sort_compare <<endl;

  // cout << "The 5th smallest number is : "
  //      << myQuickFind(test_array, 5) <<endl;
}
