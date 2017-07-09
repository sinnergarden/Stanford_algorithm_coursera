#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<cstdlib>
using namespace std;

//vector<int> merge(vector<int>, vector<int>);
inline bool Less(int,int);
void init(int);
void read_input();
void print_result(const vector<int> &);
void merge(vector<int>&, int, int, int, int);
void sort_and_count(vector<int> &);
void mergesort(vector<int>&, int, int);

vector<int> test_array;
int intervals = 0;

int  main(){
  //read_input();
  init(20);
  print_result(test_array);
  sort_and_count(test_array);
  //mergesort(test_array);
  print_result(test_array);
  cout <<"The number of intervals : "<<intervals <<endl;
}


inline bool Less(int a, int b){
  return a<b ? 1 : 0;
}

void init(int length){
  test_array.clear();
  srand(time(NULL));
  for (int i=0; i<length; i++){
    test_array.push_back(random()%100);
  }
}

void read_input(){
  int temp;
  test_array.clear();
  while(cin>>temp) test_array.push_back(temp); 
}

void print_result(const vector<int> &test_array){
  cout << " The current array is :" << endl;
  for(int i = 0; i < test_array.size(); i++) {
    cout<< test_array[i] << ' ';
  }
  cout << endl;
}

void sort_and_count(vector<int> &array){
  mergesort(array, 0, array.size()-1);
}

void merge(vector<int>&array, int begin1, int end1, int begin2, int end2){
  int i = begin1, j = begin2;
  vector<int> temp;
  while(i <= end1 || j <= end2){
    if (Less(array[i],array[j]) && i<=end1 && j<=end2){
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

void mergesort(vector<int> &array, int begin, int end){
  int mid = (begin+end)/2;
  if (mid > begin) mergesort(array, begin, mid);
  if (end > mid+1) mergesort(array, mid+1, end);
  merge(array, begin, mid, mid+1, end);
}
