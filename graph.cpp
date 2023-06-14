#include "graph.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>

void Graph::addNode(const string& cityName, int chargingTime) {
    // Check if the city already exists in the graph
    if (nodes.find(cityName) == nodes.end()) {
        // Add a new entry for the city in the 'nodes' map
        nodes[cityName] = unordered_map<string, int>();
        // Store the charging time for the city
        nodes[cityName]["chargingTime"] = chargingTime;
    }
}

void Graph::addEdge(const string& sourceCity, const string& destinationCity, int weight) {
    // Check if both source and destination cities exist in the graph
    if (nodes.find(sourceCity) != nodes.end() && nodes.find(destinationCity) != nodes.end()) {
        // Add the edge between the cities in the 'nodes' map
        nodes[sourceCity][destinationCity] = weight;
        nodes[destinationCity][sourceCity] = weight;
        // Add the edge to the 'edges' vector
        edges.push_back(Edge(sourceCity, destinationCity, weight));
    }
}

int Graph::getEdgeWeight(const string& sourceCity, const string& destinationCity) {
    // Check if both source and destination cities exist in the graph and there is an edge between them
    if (nodes.find(sourceCity) != nodes.end() && nodes[sourceCity].find(destinationCity) != nodes[sourceCity].end()) {
        // Return the weight of the edge between the cities
        return nodes[sourceCity][destinationCity];
    }

    // Edge doesn't exist, return a default weight or an appropriate value
    return 0; // Change this to your desired default weight or choose an appropriate return value
}

vector<string> Graph::shortestPath(const string& sourceCity, const string& destinationCity) {
    // Create a priority queue to store the cities to be visited
    priority_queue<Node, vector<Node>, CompareNode> pq;

    // Create a map to track the distance from the source city to each city
    unordered_map<string, int> distance;

    // Create a map to track the previous city in the shortest path
    unordered_map<string, string> previous;

    // Initialize distances and previous cities
    for (const auto& city : nodes) {
        distance[city.first] = numeric_limits<int>::max();
        previous[city.first] = "";
    }

    // Set the distance of the source city to 0 and add it to the priority queue
    distance[sourceCity] = 0;
    pq.push(Node(sourceCity, 0));

    // Dijkstra's algorithm
    while (!pq.empty()) {
        string currentCity = pq.top().city;
        int currentDistance = pq.top().distance;
        pq.pop();

        if (currentDistance > distance[currentCity]) {
            continue;  // Skip if a shorter distance to the city has already been found
        }

        for (const auto& neighbor : nodes[currentCity]) {
            string neighborCity = neighbor.first;
            int weight = neighbor.second;

            int newDistance = distance[currentCity] + weight;

            if (newDistance < distance[neighborCity]) {
                distance[neighborCity] = newDistance;
                previous[neighborCity] = currentCity;
                pq.push(Node(neighborCity, newDistance));
            }
        }
    }

    // Reconstruct the shortest path
    vector<string> shortestPath;
    string currentCity = destinationCity;

    while (currentCity != "") {
        shortestPath.push_back(currentCity);
        currentCity = previous[currentCity];
    }

    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

vector<Edge> Graph::minimumSpanningTree() {
    vector<Edge> minimumSpanningTree;
    unordered_map<string, string> parent;

    // Initialize parent map
    for (const auto& city : nodes) {
        parent[city.first] = city.first;
    }

    // Sort edges in ascending order based on weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    // Perform Kruskal's algorithm
    for (const auto& edge : edges) {
        string srcParent = findParent(parent, edge.src);
        string destParent = findParent(parent, edge.dest);

        if (srcParent != destParent) {
            minimumSpanningTree.push_back(edge);
            unionSets(parent, srcParent, destParent);
        }
    }

    return minimumSpanningTree;
}

void Graph::printGraph() {
    for (const auto& city : nodes) {
        cout << "Edges from " << city.first << ": ";
        for (const auto& neighbor : city.second) {
            if (neighbor.first == "chargingTime") {
                cout << neighbor.first << " (" << neighbor.second << " minutes) ";
            } else {
                cout << neighbor.first << " (" << neighbor.second << " miles) ";
            }
        }
        cout << endl;
    }
}

string Graph::findParent(unordered_map<string, string>& parent, const string& city) {
    if (parent[city] != city) {
        // Path compression optimization - set the parent of the current city to its root parent
        parent[city] = findParent(parent, parent[city]);
    }
    return parent[city];
}

void Graph::unionSets(unordered_map<string, string>& parent, const string& city1, const string& city2) {
    string parent1 = findParent(parent, city1);
    string parent2 = findParent(parent, city2);
    // Merge the sets by setting the parent of one set's root to the parent of the other set's root
    parent[parent2] = parent1;
}
