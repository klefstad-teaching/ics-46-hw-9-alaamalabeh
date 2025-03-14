#include "dijkstras.h"

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    distances[source] = 0;
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        int dist_u = pq.top().second;
        pq.pop();

        if (dist_u > distances[u]) continue;

        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({v, distances[v]});
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    if (distances[destination] == INF) {
        cout << "No path found to vertex " << destination << endl;
        return path;
    }

    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    if (path.empty()) {
        cout << "No path available\n";
        return;
    }

    cout << "Shortest path (cost " << total << "): ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
}
