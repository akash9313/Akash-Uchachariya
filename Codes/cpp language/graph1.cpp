#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple> // We need <tuple> for pair, but will use .first and .second
#include <algorithm>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char d_char[] = {'U', 'D', 'L', 'R'};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<string> grid(n);
    vector<vector<int>> distance_m(n, vector<int>(m, -1));
    vector<vector<int>> distance_a(n, vector<int>(m, -1));
    vector<vector<int>> parent_a(n, vector<int>(m, -1));

    queue<pair<int, int>> q_m; 
    queue<pair<int, int>> q_a; 
    int start_r = -1, start_c = -1;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'M') {
                q_m.push(make_pair(i, j));
                distance_m[i][j] = 0;
            }
        }
    }

    while (!q_m.empty()) {
        // C++11 compatible deconstruction
        pair<int, int> curr = q_m.front();
        int r = curr.first;
        int c = curr.second;
        q_m.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && distance_m[nr][nc] == -1) {
                distance_m[nr][nc] = distance_m[r][c] + 1;
                q_m.push(make_pair(nr, nc));
            }
        }
    }

    q_a.push(make_pair(start_r, start_c));
    distance_a[start_r][start_c] = 0;
    pair<int, int> end_pos = make_pair(-1, -1);

    while (!q_a.empty() && end_pos.first == -1) {
        // C++11 compatible deconstruction
        pair<int, int> curr = q_a.front();
        int r = curr.first;
        int c = curr.second;
        q_a.pop();

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            end_pos = make_pair(r, c);
            break; 
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int next_dist = distance_a[r][c] + 1;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && distance_a[nr][nc] == -1) {
                if (distance_m[nr][nc] == -1 || next_dist < distance_m[nr][nc]) {
                    distance_a[nr][nc] = next_dist;
                    parent_a[nr][nc] = i; 
                    q_a.push(make_pair(nr, nc));
                }
            }
        }
    }

    if (end_pos.first != -1) {
        cout << "YES" << endl;
        int r = end_pos.first;
        int c = end_pos.second;
        string path = "";
        
        while (r != start_r || c != start_c) {
            int prev_dir_idx = parent_a[r][c];
            path += d_char[prev_dir_idx];

            r -= dr[prev_dir_idx];
            c -= dc[prev_dir_idx];
        }
        
        reverse(path.begin(), path.end()); 
        cout << path.length() << endl;
        cout << path << endl;

    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}