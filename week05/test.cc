#include<iostream>
#include<fstream>
#include<vector>
#include "week5_SCC.hh"
using namespace std;

int main(){
  ifstream testFile;
  testFile.open("SCC_small.txt");
  int v, w;
  DiGraph G;
  while (testFile >> v >> w) {
    G.addEdge(v,w);
  }

  testFile.close();
  G.showGraph();
  cout<<endl;
  G.reverse();
  G.reverse();
  G.showGraph();

  
  /*
  DiGraph G(V);
  
  for(int i = 0; i < edge_num; i++){
    //read and add edge
    G.addEdge(v, w);
  }
  
  SCC scc(G);
  scc.printResult();
  */
  return 0;
}
