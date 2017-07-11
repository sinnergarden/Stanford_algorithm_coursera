#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class DiGraph{
public:
  DiGraph();
  DiGraph(int v) {
    this.V = v;
    this.E = 0;
    adj.resize(v+1);
  }
  int getV() {return V;}
  int getE() {return E;}
  void addEdge(int v, int w) {
    adj[v].push_back(w);
    E++;
  }
  vector<int> adj(int v) {return adj[v];}
  void reverse() {
    vector<vector<int>> aux(this.V+1);
    for(int v = 1; v <= this.V; v++)
      for(int w:adj[v])
	aux[w].push_back(v);
    for(int v = 1; v <= this.V; v++)
      for(int w:adj[v])
	adj[w] = aux[w];
  }
  
private:
  int V;
  int E;
  vector<vector<int>> adj;
};


class SCC{
public:
  SSC(DiGraph G){
    ssc(G);
  }
  
  void dfs1(DiGraph G, int v){
    marked[v] = true;
    for(int w: G.adj[v]){
      if(!marked[w]){
	dfs(G, w);
	reversePostOrder.push_back(w); //reverse post order
      }
    }
  }
  
  void dfs2(DiGraph G, int v){
    marked[v] = true;
    for(int w: G.adj[v]){
      if(!marked[w]){
	dfs(G, w);
	id[w] = count;
      }
    }
  }
  
  void ssc(DiGraph G){
    //init marked
    marked.resize(G.getV()+1, false);
    for(int v = 1; v <= G.getV(); v++)
      dfs1(G.reverse(), v);
    
    //init marked, count
    count = 0;
    marked.resize(G.getV()+1, false);
    for(int v: reversePostOrder)
      count ++;
      dfs2(G, v);
  }

  int getCount() {return count;}
  void printResult(){
    //print the size of first five SCC.
    vector<int> first5(count);
    for(int i = 1; i < G.getV()+1; i++){
      first5[id[i]] ++;
    }
    sort(first5.begin(), first5.end());
    for(int i = 0; i < 5; i++)
      cout<<first5[i]<<endl;
  }
  
private:
  int count;
  vector<bool> marked;
  vector<int> reversePostOrder;
  vector<int> id;
};

int main(){
  int V = 0;
  int v = 0, w = 0;
  int edge_num = 0;
  DiGraph G(V);
  
  for(int i = 0; i < edge_num; i++){
    //read and add edge
    G.addEdge(v, w);
  }
  
  SCC scc(G);
  scc.printResult();
}
