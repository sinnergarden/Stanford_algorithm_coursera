#include<iostream>
#include<fstream>
#include"week7_median.hh"
using namespace std;

int main(){
  int count = 0;
  double sum = 0;
  double curMedian = 0;
  int temp;
  ifstream testFile;
  pqMin min;
  pqMax max;
  
  //testFile.open("SmallInput.txt");
  testFile.open("Median.txt");
  
  while(testFile >> temp){

    if (temp > curMedian) min.put(temp);
    else max.put(temp);
    
    count ++;
    //cout<<"round: "<< count <<endl;
    
    while(min.count() > max.count()) //min + 1 = max or min == max
      max.put(min.delMin());

    while(max.count() > min.count() + 1) 
      min.put(max.delMax());

    if (min.count() + 1 == max.count())
      curMedian = max.readMax();
      
    if (min.count() == max.count())
      curMedian = (min.readMin() + max.readMax())/2.0;

    //cout<<"left Max :"<<max.count()<<endl;
    //cout<<"right Min :"<<min.count()<<endl;
    //max.print();
    //min.print();
    //cout<<"Median is: "<< curMedian << endl;
    sum += curMedian;

  }

  testFile.close();

  cout<<endl;
  cout<<"count result: "<< count<<endl;
  cout<<"sum result: "<<sum<<endl;
  cout<<"average median result: " << sum/count << endl;
  return 0;
}
