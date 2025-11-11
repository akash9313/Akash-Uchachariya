#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100005; 
vector<int> adj[MAXN]; 
int subtree_size[MAXN]; 

void dfs_size(int u, int p) {
    subtree_size[u] = 1; 
    for (int v : adj[u]) {-
        if (v != p) {
            dfs_size(v, u);
            subtree_size[u] += subtree_size[v]; 
        }
    }
}

int find_centroid(int u, int p, int n) {
    for (int v : adj[u]) {
        if (v != p) {
            if (subtree_size[v] > n / 2) {
                return find_centroid(v, u, n);
            }
        }
    }

    if (p != 0 && n - subtree_size[u] > n / 2) {
        return find_centroid(p, u, n);
    }
    
    return u;
}


vector<int> find_center(int n) {
    if (n == 0) return {};
    if (n == 1) return {1};

    vector<pair<int, int>> bfs(n + 1); 

    auto run_bfs = [&](int start_node) -> pair<int, int> {
        fill(bfs.begin(), bfs.end(), make_pair(-1, 0));
        queue<int> q;
        q.push(start_node);
        bfs[start_node] = {0, 0};
        
        int farthest_node = start_node;
        int max_dist = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (bfs[u].first > max_dist) {
                max_dist = bfs[u].first;
                farthest_node = u;
            }

            for (int v : adj[u]) {
                if (bfs[v].first == -1) {
                    bfs[v] = {bfs[u].first + 1, u};
                    q.push(v);
                }
            }
        }
        return {farthest_node, max_dist};
    };

    int u = run_bfs(1).first; 

    pair<int, int> v_dist = run_bfs(u);
    int v = v_dist.first;
    int diameter = v_dist.second;

    vector<int> path;
    int curr = v;
    while (curr != 0) {
        path.push_back(curr);
        curr = bfs[curr].second;
    }

    vector<int> centers;
    int middle_index_1 = diameter / 2;
    centers.push_back(path[middle_index_1]);

    if (diameter % 2 == 1) { 
        int middle_index_2 = diameter / 2 + 1;
        centers.push_back(path[middle_index_2]);
    }
    
    return centers;
}


void solve_q3() {
    int n; 
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs_size(1, 0); 
    int centroid = find_centroid(1, 0, n);
    
    cout << "Centroid(s): " << centroid;
    cout << endl;

    vector<int> centers = find_center(n);
    cout << "Center(s): ";
    for (int i = 0; i < centers.size(); ++i) {
        cout << centers[i] << (i == centers.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    solve_q3();
    return 0;
}