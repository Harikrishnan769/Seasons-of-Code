#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int INF = 1e9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir[] = {'D', 'U', 'R', 'L'};

int n, m;
vector<string> grid;
vector<vector<int>> monster_time;
vector<vector<int>> player_time;
vector<vector<pair<int, int>>> parent;
pair<int, int> start;

bool is_boundary(int x, int y) {
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}

bool in_bounds(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs_monsters(queue<pair<int, int>>& q) {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (in_bounds(nx, ny) && grid[nx][ny] != '#' && monster_time[nx][ny] == INF) {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void bfs_player() {
    queue<pair<int, int>> q;
    q.push(start);
    player_time[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (is_boundary(x, y)) {
            // Reached boundary, reconstruct path
            string path;
            while (make_pair(x, y) != start) {
                auto [px, py] = parent[x][y];
                for (int d = 0; d < 4; ++d) {
                    if (x - dx[d] == px && y - dy[d] == py) {
                        path.push_back(dir[d]);
                        break;
                    }
                }
                x = px; y = py;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << '\n' << path << '\n';
            exit(0);
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (in_bounds(nx, ny) && grid[nx][ny] != '#' && player_time[nx][ny] == -1) {
                int nt = player_time[x][y] + 1;
                if (nt < monster_time[nx][ny]) {
                    player_time[nx][ny] = nt;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monster_time.assign(n, vector<int>(m, INF));
    player_time.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> monsters;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                monsters.push({i, j});
                monster_time[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    bfs_monsters(monsters);
    bfs_player();

    return 0;
}
