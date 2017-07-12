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
  SCC(DiGraph G) {scc(G);}
  void dfs1(DiGraph, int);
  void dfs2(DiGraph, int);
  void scc(DiGraph);
  int getCount() {return count;}
  void printResult(DiGraph);
  
private:
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
  
  for(int v = 0; v < V; v++)
    for(int w:adjacent[v])
      adjacent[w] = aux[w];
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
  for(int w: G.adj(v)){
    if(!marked[w]){
      dfs1(G, w);
      reversePostOrder.push_back(w); //reverse post order
    }
  }
}

void
SCC::dfs2(DiGraph G, int v) {
  marked[v] = true;
  for(int w: G.adj(v)){
    if(!marked[w]){
      dfs2(G, w);
      id[w] = count;
    }
  }
}
  
void
SCC::scc(DiGraph G){
  //init marked
  marked.resize(G.getV()+1, false);
  for(int v = 1; v <= G.getV(); v++)
    dfs1(G.reverse(), v);
    
  //init marked, count
  count = 0;
  marked.resize(G.getV()+1, false);
  for(int v: reversePostOrder) {
    count ++;
    dfs2(G, v);
  }
}

void
SCC::printResult(DiGraph G){
  //print the size of first five SCC.
  vector<int> first5(count);
  for(int i = 1; i < G.getV() + 1; i++){
    first5[id[i]] ++;
  }
  sort(first5.begin(), first5.end());
  for(int i = 0; i < 5; i++)
    cout<<first5[i]<<endl;
}
