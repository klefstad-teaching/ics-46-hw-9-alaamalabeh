#include "dijkstras.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    string filename = "small.txt";

    try {
        file_to_graph(filename, G);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    int source = 0;
    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    cout << "Testing " << source << ":" << endl;
    for (int i = 1; i < G.numVertices; i++) {
        vector<int> path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]);
    }

    return 0;
}
