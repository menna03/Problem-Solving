#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
int numberOfVertices, numberOfEdges;
int startingVertex, endingVertex;
 
vector<pair<int, int>> edges;
 
bool isValid(int vertex, const vector<int>& path, int currentPosition, const vector<vector<int>>& adjacencyMatrix) {
    if (adjacencyMatrix[path[currentPosition - 1]][vertex] == 0) {
        return false;
    }
    if (find(path.begin(), path.end(), vertex) != path.end()) {
        return false;
    }
    return true;
}
 
bool hamiltonianCircuitUtil(int currentVertex, vector<int>& path, int currentPosition, const vector<vector<int>>& adjacencyMatrix) {
    if (currentPosition == numberOfVertices) {
        if (adjacencyMatrix[path[currentPosition - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }
 
    for (int nextVertex = 1; nextVertex < numberOfVertices; ++nextVertex) {
        if (isValid(nextVertex, path, currentPosition, adjacencyMatrix)) {
            path[currentPosition] = nextVertex;
            if (hamiltonianCircuitUtil(nextVertex, path, currentPosition + 1, adjacencyMatrix)) {
                return true;
            }
            path[currentPosition] = -1;
        }
    }
    return false;
}
 
vector<int> findHamiltonianCircuit(const vector<vector<int>>& adjacencyMatrix, int n) {
    vector<int> path(n + 1, -1);
    path[0] = 0;
 
    if (!hamiltonianCircuitUtil(0, path, 1, adjacencyMatrix)) {
        return {-1};
    }
 
    path[n] = 0;
    for (int i = 0; i <= n; ++i) {
        path[i]++;
    }
    return path;
}
 
vector<int> solve() {
    vector<vector<int>> adjacencyMatrix(numberOfVertices, vector<int>(numberOfVertices, 0));
 
    for (const auto& edge : edges) {
        adjacencyMatrix[edge.first - 1][edge.second - 1] = 1;
        adjacencyMatrix[edge.second - 1][edge.first - 1] = 1;
    }
 
    vector<int> path = findHamiltonianCircuit(adjacencyMatrix, numberOfVertices);
    if (path[0] == -1) {
        return {-1};
    }
    return path;
}
 
int main() {
    cin >> numberOfVertices >> numberOfEdges;
 
    for (int i = 0; i < numberOfEdges; ++i) {
        cin >> startingVertex >> endingVertex;
        edges.push_back({startingVertex, endingVertex});
    }
 
    vector<int> result = solve();
    if (result[0] == -1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i <= numberOfVertices; ++i) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}