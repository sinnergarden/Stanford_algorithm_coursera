#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<random>
#include<algorithm>
using namespace std;

inline bool isLess(int,int);
void exchange(vector<int> &, int, int);
void init(int);
void readInput(string);
void printResult(const vector<int> &);

void myQuickSort(vector<int> &, int);
void quickSort(vector<int> &, int, int, function pointer);
int myPartition1(vector<int> &, int, int); // 1st element as pivot
int myPartition2(vector<int> &, int, int); // final 
int myPartition3(vector<int> &, int, int); // median of 3

int myQuickFind(vector<int> &, int);
int quickFind(vector<int> &, int, int, int);

vector<int> test_array;
int quick_sort_compare = 0;


inline bool isLess(int a, int b){
  return a<b ? 1 : 0;
}

void exchange(vector<int> &test_array, int i, int j){
  int temp = test_array[i];
  test_array[i] = test_array[j];
  test_array[j] = temp;
}

void init(int length){
  test_array.clear();
  srand(time(NULL));
  for (int i=0; i<length; i++){
    test_array.push_back(random()%100);
  }
}

void readInput(string inputFileName){
  int temp;
  ifstream test_file;
  test_file.open(inputFileName);
  test_array.clear();
  while(test_file>>temp) 
    test_array.push_back(temp);
  test_file.close();
}

void printResult(const vector<int> &test_array){
  cout << " The current array is :" << endl;
  for(int i = 0; i < test_array.size(); i++) {
    cout<< test_array[i] << ' ';
  }
  cout << endl;
}
//1
int myPartition1(vector<int> &test_array, int begin, int end){
  int i = begin + 1;
  for (int j = begin+1; j<=end; j++){
    quick_sort_compare ++; //comparation made by quick sort
    if (isLess(test_array[j], test_array[begin])){
      exchange(test_array, i, j);
      i++;
    }
  }
  exchange(test_array, begin, i-1);
  return i-1;
}
//2
//3

void quickSort(vector<int> & test_array,  int begin, int end, function ptr){
  if (begin >= end) return;
  //printResult(test_array);
  int mid = myPartition(test_array, begin, end);
  quickSort(test_array, begin, mid-1);
  quickSort(test_array, mid+1, end);
}

void myQuickSort(vector<int> & test_array, int type){
  if (type == 1)
    quickSort(test_array, 0, test_array.size()-1, );
  if (type == 2)
    quickSort(test_array, 0, test_array.size()-1, );
  if (type == 3)
    quickSort(test_array, 0, test_array.size()-1, );
}

int quickFind(vector<int> & test_array, int begin, int end, int k){
  if (begin == end && begin!= k) return -1;
  int mid = myPartition(test_array, begin, end);
  if (mid == k) return test_array[k];
  if (mid > k) return quickFind(test_array, begin, mid-1, k);
  if (mid < k) return quickFind(test_array, mid+1, end, k);
}

int myQuickFind(vector<int> & test_array, int k){
  //input k is kth, k-1 is kth element's index.
  return quickFind(test_array, 0, test_array.size()-1, k-1);
}

