#include<iostream>
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
  SSC();
  void dfs1(DiGraph G, int v){
    marked[v] = true;
    for(int w: G.adj[v]){
      if(!marked[w]){
	dfs(G, w);
	//reverse post order
      }
    }
  }
  void dfs2(DiGraph G, int v){
    marked[v] = true;
    for(int w: G.adj[v]){
      if(!marked[w]){
	dfs(G, w);
      }
    }
  }
  void ssc(DiGraph G){
    //init marked
    for(int v = 1; v <= G.getV(); v++)
      dfs1(G.reverse(), v);
    //init marked
    for(int v: reversePostOrder)
      count ++;
      dfs2(G, v);
  }
private:
  int count;
  vector<bool> marked;
  vector<int> reversePostOrder;
  vector<int> id;
};

int main(){
  //read from file and init Directed Graph G

  //calculate SCC

  //calculate first 5 SCC size
}
