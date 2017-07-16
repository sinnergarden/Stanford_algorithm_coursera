#include<vector>
#include<algorithm>
using namespace std;

class pqMin{
public:
  pqMin();
  void put(int);
  void swim(int);
  void sink(int);
  int delMin();
  int readMin();
  int count();
  void print();
  bool isEmpty();
private:
  vector<int> pqArray;
};

class pqMax{
public:
  pqMax();
  void put(int);
  void swim(int);
  void sink(int);
  int delMax();
  int readMax();
  int count();
  void print();
  bool isEmpty();
private:
  vector<int> pqArray;
};

pqMin::pqMin() { pqArray.push_back(0); }

void
pqMin::put(int ele) { 
  pqArray.push_back(ele);
  swim(pqArray.size()-1);
}

void
pqMin::swim(int idx) {
  while(idx/2 > 0 && pqArray[idx] < pqArray[idx/2]) {
    swap(pqArray[idx], pqArray[idx/2]);
    idx /= 2;
  }
}

void
pqMin::sink(int idx) {
  while(2*idx <= pqArray.size()-1){
    int j = 2*idx;
    if(j<pqArray.size()-1 && pqArray[j] > pqArray[j+1]) j++;
    if(pqArray[idx] < pqArray[j]) break;
    swap(pqArray[idx], pqArray[j]);
    idx = j;
  }
}

int
pqMin::readMin() { return pqArray[1]; }

int
pqMin::delMin() {
  int min = pqArray[1];
  swap(pqArray[1], pqArray[pqArray.size()-1]);
  pqArray.pop_back();
  sink(1);
  return min;
}

int
pqMin::count() { return pqArray.size()-1; }

void
pqMin::print() {
  cout<<"right pq is :";
  for (int i = 1; i < pqArray.size(); i++)
    cout<< pqArray[i] <<' ';
  cout<<endl;
}

bool
pqMin::isEmpty() {
  return pqArray.size() == 1;
}

pqMax::pqMax() { pqArray.push_back(0); }

void
pqMax::put(int ele) {
  pqArray.push_back(ele);
  swim(pqArray.size()-1);
}

void
pqMax::swim(int idx) {
  while(idx/2 > 0 && pqArray[idx] > pqArray[idx/2]) {
    swap(pqArray[idx], pqArray[idx/2]);
    idx /=2;
  }
}

void
pqMax::sink(int idx) {
  while(2*idx <= pqArray.size()-1){
    int j = 2*idx;
    if(j < pqArray.size()-1 && pqArray[j] < pqArray[j+1]) j++;
    if(pqArray[idx] > pqArray[j]) break;
    swap(pqArray[idx], pqArray[j]);
    idx = j;
  }
}

int
pqMax::readMax() { return pqArray[1]; }

int
pqMax::delMax() {
  int max = pqArray[1];
  swap(pqArray[1], pqArray[pqArray.size()-1]);
  pqArray.pop_back();
  sink(1);
  return max;
}

int
pqMax::count() { return pqArray.size()-1; }

void
pqMax::print() {
  cout<<"left pq is :";
  for (int i = 1; i < pqArray.size(); i++)
    cout<< pqArray[i] <<' ';
  cout<<endl;
}

bool
pqMax::isEmpty() {
  return pqArray.size() == 1;
}
