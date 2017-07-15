#include<iostream>
#include<fstream>
#include"week7_median.hh"
using namespace std;

int main(){
  int count = 0;
  double sum = 0;
  int curMedian;
  int temp;
  ifstream testFile;
  pqMin min;
  pqMax max;
  
  testFile.open("SmallInput.txt");

  while(testFile >> temp){
    cout<<"round: "<< count+1 <<endl;
    if (min.count() >= max.count()) {
      max.put(temp);
      count ++;
      sum += min.getMin();
      cout<<"median is: "<< min.getMin() <<endl<<endl; 
    }
    else {
      min.put(temp);
      count ++;
      sum += (min.getMin()+max.getMax())/2.0;
      cout<<"median is: "<< (min.getMin()+max.getMax())/2.0 <<endl<<endl; 
    }
  }

  testFile.close();
  
  cout<<"count result: "<< count<<endl;
  cout<<"sum result: "<<sum<<endl;
  cout<<"average median result: " << sum/count << endl;
  return 0;
}
