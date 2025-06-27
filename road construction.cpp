#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll find(ll x, vector<ll> &parent) {
    if (parent[x] != x) parent[x] = find(parent[x], parent);
    return parent[x];
}

void unite(ll a, ll b, vector<ll> &parent, vector<ll> &size, ll &components, ll &max_size) {
    a = find(a, parent);
    b = find(b, parent);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    max_size = max(max_size, size[a]);
    components--;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> parent(n + 1), size(n + 1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    ll components = n, max_size = 1;

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        unite(a, b, parent, size, components, max_size);
        cout << components << " " << max_size << "\n";
    }

    return 0;
}
