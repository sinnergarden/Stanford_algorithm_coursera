#include<iostream>
#include<vector>
using namespace std;

void exchange(int &, int &);
void myquicksort(vector<int> &);
void quicksort(vector<int> &, int, int, int);
int partitioning(vector<int> &, int, int, int);
int quick_find(const vector<int> &, int);

int partitioning(vector<int> &test_array, int idx, int begin, int end){
  int p = begin, q = end;
  while(p<=q){
    if (test_array[p] < test_array[idx]){
      exchange(test_array[p], test_array[idx]);
      idx = p;
      p += 1;
    } else {
      p += 1;
    }
    if (test_array[q] > test_array[idx]){
      exchange(test_array[q], test_array[idx]);
      idx = q;
      q -= 1;
    } else {
      q -= 1;
    }
  }
  return idx;
}

void exchange(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void quicksort(vector<int> & test_array, int idx, int begin, int end){
  int mid = partitioning(test_array, idx, begin, end);
  if (mid-1 > begin) quicksort(test_array,begin-1,begin,mid-1);
  if (end > mid+2) quicksort(test_array,mid+1,mid+2,end);
}

void myquicksort(vector<int> & test_array){
  quicksort(test_array, 0, 1, test_array.size());
}

void quick_find(const vector<int> & test_array, int k){
  int mid = partitioning(test_array,0,1,test_array.size());
  if (mid == k) return test_array[];
  if (mid > k)
  if (mid < k)
}
