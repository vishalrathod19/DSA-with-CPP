#include<iostream>
#include<unordered_map>
#include<list>
#include<stack> 
#include<vector>
#include<climits>
using namespace std;

class Graph{
      public:
      unordered_map<int,list<pair<int,int>>> adj;

      void addEdges(int u, int v, int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
      } 
      
      void printAdjList(){
        for(auto i: adj){
           cout<<i.first<<"->";
              for(auto j: i.second){
                 cout<<"("<<j.first<<","<<j.second<<")";
              }
                cout<<endl;
        }
      }
      
      void dfs(int node, unordered_map<int,bool> &visited, stack<int> &s){
        visited[node] = true;
        for(auto i: adj[node]){
           if(!visited[i.first]){
              dfs(i.first,visited,s);
           }
        }
        s.push(node);
      }
    
    void getShortestPath(int src, vector<int> &dist, stack<int> &s){

        dist[src]=0;
        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top]!=INT_MAX){
                for(auto i: adj[top]){
                    if(dist[i.first]>dist[top]+i.second){
                        dist[i.first] = dist[top]+i.second;
                    }
                }
            }
        } 
    }


};

int main(){
    Graph g;
    g.addEdges(0,1,5);
    g.addEdges(0,2,3);
    g.addEdges(1,2,2);
    g.addEdges(1,3,6);
    g.addEdges(2,3,7);
    g.addEdges(2,4,4);
    g.addEdges(2,5,2);
    g.addEdges(3,4,-1);
    g.addEdges(3,4,-1);
    g.addEdges(4,5,-2);

    g.printAdjList();
    //topological sort
    int n= 6;
    unordered_map<int,bool> visited;
    stack<int> s;

    for (int i = 0; i<n; i++){
       if(!visited[i]){
         g.dfs(i,visited,s);
       }
    }
    int src = 1;
    vector<int> dist(n);
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }
    
    g.getShortestPath(src,dist,s);
    cout<<"answer is :"<<endl;
    for (int i = 0; i < dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}