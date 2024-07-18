#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class graph{
    public:
        unordered_map<int, list<int>> adj;
        void addEdge(int u, int v,bool direction){
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(direction==0){
                adj[v].push_back(u);
            }     
        }
        void print(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};

int main (){
    int n;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    int m ;
    cout<<"Enter the nuber of edges"<<endl;
    cin>>m; 
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter the vertices of the edge: "<<endl;
        cin>>m>>u>>v;
        bool direction;
        cout<<"Enter 1 if the edge is directed else 0"<<endl;
        cin>>direction;
        g.addEdge(u,v,direction);
    }
    g.print();
    return 0;
}