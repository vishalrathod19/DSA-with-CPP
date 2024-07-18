#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // Create an adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create a map to track visited nodes and their parents
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Perform BFS
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto i : adj[front]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                parent[i] = front;
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    while (currentNode != s) {
        if (parent.find(currentNode) == parent.end()) {
            cout << "Path not found!" << endl;
            return {}; // Return empty if there is no path
        }
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Test cases
    vector<pair<int, int>> edges1 = {{1, 4}, {1, 2}, {2, 3}, {3, 4}};
    int n1 = 4, m1 = 4, s1 = 1, t1 = 3;
    vector<int> ans1 = shortestPath(edges1, n1, m1, s1, t1);
    cout << "( ";
    for (auto i : ans1) {
        cout << i << " ";
    }
    cout << ")" << endl;

    vector<pair<int, int>> edges2 = {{1, 8}, {1, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 8}, {3, 8}, {4, 6}, {6, 7}, {7, 8}};
    int n2 = 8, m2 = 9, s2 = 1, t2 = 3;
    vector<int> ans2 = shortestPath(edges2, n2, m2, s2, t2);
    cout << "( ";
    for (auto i : ans2) {
        cout << i << " ";
    }
    cout << ")" << endl;

    return 0;
}
