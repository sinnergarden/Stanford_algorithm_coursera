#include<iostream>
#include<vector>
using namespace std;

class DiGraph{
public:
  DiGraph();
  int getV() {return V;}
  int getE() {return E;}
  void addEdge(int v, int w) {adj[v].push_back(w);}
  vector<int> adj(int v) {return adj[v];}
  void reverse();
private:
  int V;
  int E;
  vector<vector<int>> adj;
};


class SCC{
public:
  SSC();
  void dfs(DiGraph G, int v){
    marked[v]=true;
    for(int w: G.adj[v]){
      if(!marked[w]){
	dfs(G, w);
      }
    }
  }
  void ssc();
private:
  vector<bool> marked;
};

int main(){
  
}
