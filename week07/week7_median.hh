#include<vector>
#include<algorithm>
using namespace std;

class pqMin{
public:
  pqMin();
  void put(int);
  void swim(int);
  int getMin();
  int count();
private:
  vector<int> pqArray;
};

class pqMax{
public:
  pqMax();
  void put(int);
  void swim(int);
  int getMax();
  int count();
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
  }
}

int
pqMin::getMin() { return pqArray[1]; }

int
pqMin::count() { return pqArray.size()-1; }

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
  }
}

int
pqMax::getMax() { return pqArray[1]; }

int
pqMax::count() { return pqArray.size()-1; }





