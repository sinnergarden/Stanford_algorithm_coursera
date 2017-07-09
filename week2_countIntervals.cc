#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<cstdlib>
using namespace std;

inline bool isLess(int,int);
void init(int);
void readInput();
void printResult(const vector<int> &);

void merge(vector<int>&, int, int, int, int);
void sortAndCount(vector<int> &);
void mergeSort(vector<int>&, int, int);

vector<int> test_array;
int intervals = 0;

int main(){
  //readInput();
  init(20);
  printResult(test_array);
  sortAndCount(test_array);
  //mergeSort(test_array);
  printResult(test_array);
  cout <<"The number of intervals : "<<intervals <<endl;
}


inline bool isLess(int a, int b){
  return a<b ? 1 : 0;
}

void init(int length){
  test_array.clear();
  srand(time(NULL));
  for (int i=0; i<length; i++){
    test_array.push_back(random()%100);
  }
}

void readInput(){
  int temp;
  test_array.clear();
  while(cin>>temp) test_array.push_back(temp); 
}

void printResult(const vector<int> &test_array){
  cout << " The current array is :" << endl;
  for(int i = 0; i < test_array.size(); i++) {
    cout<< test_array[i] << ' ';
  }
  cout << endl;
}

void sortAndCount(vector<int> &array){
  mergeSort(array, 0, array.size()-1);
}

void merge(vector<int>&array, int begin1, int end1, int begin2, int end2){
  int i = begin1, j = begin2;
  vector<int> temp;
  while(i <= end1 || j <= end2){
    if (isLess(array[i],array[j]) && i<=end1 && j<=end2){
      temp.push_back(array[i]);
      i++;
    } else if (i<=end1 && j<=end2){
      temp.push_back(array[j]);
      j++;
      intervals += (end1-i+1);
    } else if (i>end1){
      temp.push_back(array[j]);
      j++;
    } else {
      temp.push_back(array[i]); 
      i++;
    }
  }
  for(int i = 0; i < temp.size(); i++){
    array[begin1+i] = temp[i];
  }
}

void mergeSort(vector<int> &array, int begin, int end){
  int mid = (begin+end)/2;
  if (mid > begin) mergeSort(array, begin, mid);
  if (end > mid+1) mergeSort(array, mid+1, end);
  merge(array, begin, mid, mid+1, end);
}
