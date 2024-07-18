#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

void dfs(int node, int parent, vector<int>& disc, vector<int>& low, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adj, vector<bool>& apn, int& timer) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int children = 0;

    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }

        if (!vis[nbr]) {
            dfs(nbr, node, disc, low, vis, adj, apn, timer);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= disc[node] && parent != -1) {
                apn[node] = true;
            }
            children++;
        } else {
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent == -1 && children > 1) {
        apn[node] = true;
    }
}

int main() {
    int n = 5; // Number of nodes
    int e = 5; // Number of edges
    vector<pair<int, int>> edges = {
        {0, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}
    };

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;
    vector<bool> apn(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, apn, timer);
        }
    }

    cout << "Articulation points are as follows:" << endl;
    for (int i = 0; i < n; i++) {
        if (apn[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
