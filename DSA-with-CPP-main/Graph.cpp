#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto &i : adj) {
            cout << i.first << " -> ";
            // Copy the list to a vector and sort it
            for (auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    Graph<int> g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // Assuming undirected graph
    }

    g.print();
    return 0;
}
