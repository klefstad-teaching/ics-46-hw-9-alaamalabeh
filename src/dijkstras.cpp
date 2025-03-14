#include "dijkstras.h"
#include <algorithm>


// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
//     int n = G.numVertices;
//     vector<int> distances(n, INF);
//     vector<bool> visited(n, false);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

//     distances[source] = 0;
//     pq.push({0, source});

//     auto process_node = [&](int u, auto& self) -> void {
//         if (pq.empty()) return;

//         u = pq.top().second;
//         pq.pop();

//         if (visited[u]) {
//             self(u, self);
//             return;
//         }

//         visited[u] = true;

//         for (const Edge& edge : G[u]) {
//             int v = edge.dst;
//             int weight = edge.weight;

//             if (!visited[v] && distances[u] + weight < distances[v]) {
//                 distances[v] = distances[u] + weight;
//                 previous[v] = u;
//                 pq.push({distances[v], v});
//             }
//         }

//         self(u, self);
//     };

//     process_node(source, process_node);
//     return distances;
// }

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    // Initialize distances and previous
    distances[source] = 0;
    previous.resize(n, -1);  // Initialize previous with -1
    
    pq.push({0, source});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;  // Skip if already processed
        
        visited[u] = true;
        
        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            
            if (distances[u] + weight < distances[v]) {
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
        cout << "No path found to vertex " << destination << endl;
        return path;
    }

    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
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