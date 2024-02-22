#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const ll INF = 1e18;
const int MAX = 1e5 + 5;
int s, e, n, m;
 
 
vector<pair<ll, ll>> adj[MAX];
ll dist[MAX];
bool visited[MAX];
 
void dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.emplace(0, s);
    dist[s] = 0;
 
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
 
        if (visited[u]) continue;
        visited[u] = true;
 
        for (auto &edge : adj[u]) {
            int v = edge.second;
            ll w = edge.first;
 
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[e] == INF)
        cout << -1 << "\n";
    else
        cout << dist[e] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // Input the number of nodes and edges
    cin >> n >> m;
 
    // Input edges and their weights
    for (int i = 0; i < m; i++) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        adj[u].push_back({t, v});
        adj[v].push_back({t, u});
    }
 
    // Source and destination nodes
    cin >> s >> e;
 
    // Initialize distances
    for (int i = 1; i <= n; i++) dist[i] = INF;
 
    // Apply Dijkstra's algorithm
    dijkstra();
 
 
 
    return 0;
}