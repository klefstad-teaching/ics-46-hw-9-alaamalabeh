#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    vector<int> distances(G.numVertices, INF);
    previous.resize(G.numVertices, -1);

    distances[source] = 0;

    vector<bool> visited(G.numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (visited[current_vertex]) {
            continue;
        }

        visited[current_vertex] = true;

        for (const Edge& edge : G[current_vertex]) {
            int neighbor = edge.dst;
            int weight = edge.weight;

            if (!visited[neighbor] && distances[current_vertex] != INF && 
                distances[current_vertex] + weight < distances[neighbor]) {
                distances[neighbor] = distances[current_vertex] + weight;
                previous[neighbor] = current_vertex;

                pq.push({distances[neighbor], neighbor});
            }
        }
    }
    
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    if (distances[destination] == INF) {
        return {};
    }

    stack<int> path_stack;

    for (int vertex = destination; vertex != -1; vertex = previous[vertex]) {
        path_stack.push(vertex);
    }

    vector<int> path;
    while (!path_stack.empty()) {
        path.push_back(path_stack.top());
        path_stack.pop();
    }
    
    return path;
}

void print_path(const vector<int>& v, int total) {
    if (v.empty()) {
        cout << "No path exists." << endl;
        return;
    }
    
    cout << "Path: ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << " -> ";
        }
    }
    
    if (total == INF) {
        cout << ", Total distance: INFINITY" << endl;
    } else {
        cout << ", Total distance: " << total << endl;
    }
}
