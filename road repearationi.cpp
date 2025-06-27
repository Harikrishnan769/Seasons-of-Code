#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 1});  // {cost, node}

    ll total_cost = 0;
    int edges_used = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        total_cost += cost;
        edges_used++;

        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    if (edges_used == n) {
        cout << total_cost << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
