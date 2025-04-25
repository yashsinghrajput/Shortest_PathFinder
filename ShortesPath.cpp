#include <bits/stdc++.h>
using namespace std;

void ShortestPath(vector<vector<pair<int, int>>>& graph, int source, int destination) {
    int numNodes = graph.size();
    vector<int> distances(numNodes, INT_MAX);
    vector<int> parents(numNodes, -1);
    vector<bool> visited(numNodes, false);

    priority_queue<pair<int, int>> pq;

    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node]) {
            continue;
        }

        visited[current_node] = true;

        for (auto& neighbor : graph[current_node]) {
            int node = neighbor.first;
            int edge_weight = neighbor.second;

            if (distances[current_node] + edge_weight < distances[node]) {
                distances[node] = distances[current_node] + edge_weight;
                parents[node] = current_node;
                pq.push({distances[node], node});
            }
        }
    }

    
    if (distances[destination] == INT_MAX) {
        cout << "There is no path from " << source << " to " << destination << "." << endl;
        return;
    }

    
    vector<int> path;
    int current_node = destination;
    while (current_node != -1) {
        path.insert(path.begin(), current_node);
        current_node = parents[current_node];
    }

   
    cout << "The shortest path from " << source << " to " << destination << " is: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
    }
    cout << endl;

   
    cout << "The total distance is: " << distances[destination] << endl;
}

int main() {
    int numNodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;

    vector<vector<pair<int, int>>> graph(numNodes);

    int numEdges;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the edges and weights in the format 'node1 node2 weight':\n";
    for (int i = 0; i < numEdges; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        graph[node1].push_back({node2, weight});
        graph[node2].push_back({node1, weight});
    }

    int source_node;
    cout << "Enter the Source Node: ";
    cin >> source_node;

    int destination_node;
    cout << "Enter the Destination Node: ";
    cin >> destination_node;

    ShortestPath(graph, source_node, destination_node);

    return 0;
}
