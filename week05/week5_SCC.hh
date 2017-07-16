#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DiGraph{
public:
  DiGraph();
  DiGraph(int);
  int getV() {return V;}
  int getE() {return E;}
  void addEdge(int, int);
  vector<int> adj(int v) {return adjacent[v];}
  DiGraph reverse();
  void showGraph();
    
private:
  int V;
  int E;
  vector<vector<int>> adjacent;
};


class SCC{
public:
  SCC() { V=0; } //{scc(G);}
  void dfs1(DiGraph, int);
  void dfs2(DiGraph, int);
  void scc_step1(DiGraph);
  void scc_step2(DiGraph);
  int getCount() {return count;}
  void printResult();
  void printReversePostOrder();
  
private:
  int V;
  int count;
  vector<bool> marked;
  vector<int> reversePostOrder;
  vector<int> id;
};

DiGraph::DiGraph() {
  V = 0;
  E = 0;
  adjacent.resize(0);
}

DiGraph::DiGraph(int v) {
  V = v;
  E = 0;
  adjacent.resize(v+1,{});
}

void
DiGraph::addEdge(int v, int w) {
  vector<int> temp = {};
  while(max(v,w) >= adjacent.size()){
    adjacent.push_back(temp);
  }
  adjacent[v].push_back(w);
  E++;
  V = adjacent.size();
}

DiGraph
DiGraph::reverse() {
  vector<vector<int>> aux(V);
  for(int v = 0; v < V; v++)
    for(int w:adjacent[v])
      aux[w].push_back(v);
  
  for(int v = 0; v < V; v++){
    adjacent[v].clear();
    for(int w:aux[v])
      adjacent[v].push_back(w);
  }
  return *this;
}

void
DiGraph::showGraph() {
  for(int v = 0; v < V; v++)
    for(int w = 0; w < adjacent[v].size(); w++)
      cout<<v<<" -> "<<adjacent[v][w]<<endl;
}

void
SCC::dfs1(DiGraph G, int v) {
  marked[v] = true;
  //cout<< "begin dfs1(G,"<<v<<")"<<endl;
  for(int w: G.adj(v)){
    if(!marked[w]){
      dfs1(G, w);
    }
  }
  //cout<< "finish dfs1(G,"<<v<<")"<<endl;
  reversePostOrder.push_back(v);
  // should use stack push, not vector push from back.
  // so I reverse when dfs1 finished.
}

void
SCC::dfs2(DiGraph G, int v) {
  marked[v] = true;
  id[v] = count;
  //cout<< "begin dfs2(G,"<<v<<")"<<endl;
  for(int w: G.adj(v)){
    if(!marked[w]){
      dfs2(G, w);
    }
  }
  //cout<< "finish dfs2(G,"<<v<<")"<<endl;
}
  
void
SCC::scc_step1(DiGraph G){
  
  V = G.getV();
  //DiGraph H = G.reverse();
  marked.resize(V, false); //init marked
  
  for(int v = 0; v < V; v++)
    if(!marked[v]) dfs1(G, v);
  
  reverse(reversePostOrder.begin(), reversePostOrder.end());  
  //G.reverse();
}

void
SCC::scc_step2(DiGraph G) {
  //init marked, count, id
  count = 0;
  marked.clear();
  marked.resize(V, false);
  id.resize(V, -1);
  
  
  for(int v: reversePostOrder) {    
    if(!marked[v]) {
      dfs2(G, v);
      count ++;
    }
  }
}

void
SCC::printResult(){
  //print the size of first five SCC.
  vector<int> first5 (count+1, 0);
  //cout<<"count: "<<count<<endl;
  for(int i = 0; i < V; i++){
    //cout<<i<<' '<<id[i]<<endl;
    first5[id[i]] ++;
  }
  
  sort(first5.begin(), first5.end());
  cout<<"number of SCC : "<<endl;
  for(int i = count; i > count-5; i--)
    cout<<first5[i]<<endl;
}

void
SCC::printReversePostOrder(){
  cout<<"Reverse Post Order: ";
  for(int i: reversePostOrder)
    cout<< i <<' ';
  cout<<endl;
}
