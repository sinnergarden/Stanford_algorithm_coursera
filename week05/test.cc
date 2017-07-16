#include<iostream>
#include<fstream>
#include<vector>
#include "week5_SCC.hh"
using namespace std;

int main(){
  ifstream testFile;
  testFile.open("SCC.txt");
  int v, w;
  DiGraph G;
  while (testFile >> v >> w) {
    G.addEdge(v,w);
  }
  
  testFile.close();

  cout<<"Finish reading input..."<<endl;

  DiGraph H = G.reverse();
  cout<<"Finish creating H..."<<endl;

  G.reverse();
  cout<<"Finish reversing back G..."<<endl;
      
  SCC scc;
  scc.scc_step1(H);
  cout<<"Finish first dfs..."<<endl;

  scc.scc_step2(G);
  cout<<"Finish second dfs..."<<endl;
  //scc.printReversePostOrder();
  scc.printResult();
  
  return 0;
}
