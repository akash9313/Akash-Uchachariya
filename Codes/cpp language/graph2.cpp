#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

void solve_q2() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start_node = 1; 
    int end_node = n;   

    vector<int> parent(n + 1, 0); 
    vector<int> dist(n + 1, -1); 
    queue<int> q;

    q.push(start_node);
    dist[start_node] = 1; 

    int path_length = -1;
    bool found = false;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end_node) {
            path_length = dist[u];
            found = true;
            break; 
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                parent[v] = u; 
                q.push(v);
            }
        }
    }

    if (found) {
        cout << path_length << endl;
        
        vector<int> path;
        int curr = end_node;
        while (curr != 0) {
            path.push_back(curr);
            curr = parent[curr];
        }
        
        reverse(path.begin(), path.end()); 

        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;

    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    solve_q2();
    return 0;
}