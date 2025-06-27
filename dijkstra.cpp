#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {

    int n, m;
    cin >> n >> m;
    const ll INF = 1e18;

    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<ll> dist(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        adj[a].push_back({b, weight});
        adj[b].push_back({a, weight});  // Undirected
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int a = pq.top().second;
        pq.pop();  // ✅ MUST NOT FORGET THIS

        if (visited[a]) continue;
        visited[a] = true;

        for (auto [b, w] : adj[a]) {
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                pq.push({dist[b], b});
            }
        }
    }

    if (dist[n] == INF) {
        cout << "-1\n";
        return 0;
    }

    vector<int> path;
    for (int i = n; i != -1; i = parent[i])
        path.push_back(i);
    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";
    cout << "\n";

    return 0;
}
