#include "dijkstras.h"
#include <algorithm>


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    distances[source] = 0;
    previous.assign(n, -1);
    
    pq.push({0, source});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distances[u]) {
            continue;
        }
        
        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;

    if (distances[destination] == INF) {
        return path;
    }

    int max_iterations = previous.size();
    int iterations = 0;
    
    for (int at = destination; at != -1 && iterations < max_iterations; at = previous[at], iterations++) {
        path.push_back(at);

        if (path.size() > 1 && path.back() == path[path.size() - 2]) {
            break;
        }
    }

    reverse(path.begin(), path.end());
    
    return path;
}

void print_path(const vector<int>& path, int total) {
    if (path.empty()) {
        cout << "\nTotal cost is " << total << endl;
        return;
    }
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " ";
    }
    cout << " \nTotal cost is " << total << endl;
}