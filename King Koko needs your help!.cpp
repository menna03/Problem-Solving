#include <iostream>
#include <algorithm>
#include <vector>
 
typedef long long ll; 
 
using namespace std;
ll numBuildings, numRoads;
 
class Edge {
public:
    ll from, to;
    ll cost;
};
 
bool compareEdges(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}
 
ll findParent(vector<ll> &parent, ll node) {
    if (parent[node] == node)
        return node;
    return (parent[node] = findParent(parent, parent[node]));
}
 
void mergeSets(vector<ll> &parent, vector<ll> &rank, ll u, ll v) {
    ll rootU = findParent(parent, u);
    ll rootV = findParent(parent, v);
 
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            swap(rootU, rootV);
        parent[rootV] = rootU;
        if (rank[rootU] == rank[rootV])
            rank[rootU]++;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
 
    cin >> numBuildings >> numRoads;
 
    vector<Edge> edges(numRoads);
    for (ll i = 0; i < numRoads; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
 
    sort(edges.begin(), edges.end(), compareEdges);
 
    vector<ll> parent(numBuildings + 1), rank(numBuildings + 1, 0);
    for (ll i = 1; i <= numBuildings; ++i)
        parent[i] = i;
 
    ll minTotalCost = 0;
    for (ll i = 0; i < numRoads; ++i) {
        ll u = edges[i].from;
        ll v = edges[i].to;
        ll roadCost = edges[i].cost;
 
        if (findParent(parent, u) != findParent(parent, v)) {
            minTotalCost += roadCost;
            mergeSets(parent, rank, u, v);
        }
    }
    cout << minTotalCost << endl;
 
    return 0;
}