#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    string city;
    int distance;

    Node(const string& c, int d) : city(c), distance(d) {}
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

struct Edge {
    string src, dest;
    int weight;

    Edge(const string& s, const string& d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
private:
    unordered_map<string, unordered_map<string, int>> nodes; // Stores the nodes and their neighbors with distances
    vector<Edge> edges; // Stores the edges of the graph

public:
    // Function to add a new node to the graph
    void addNode(const string& cityName, int chargingTime);

    // Function to add a new edge between two cities in the graph
    void addEdge(const string& sourceCity, const string& destinationCity, int distance);

    // Function to get the weight of an edge between two cities
    int getEdgeWeight(const string& sourceCity, const string& destinationCity);

    // Function to find the shortest path between two cities using Dijkstra's algorithm
    vector<string> shortestPath(const string& sourceCity, const string& destinationCity);

    // Function to find the minimum spanning tree of the graph using Kruskal's algorithm
    vector<Edge> minimumSpanningTree();

    // Function to print the graph
    void printGraph();

private:
    // Helper function to find the parent of a city in the disjoint-set
    string findParent(unordered_map<string, string>& parent, const string& city);

    // Helper function to perform union operation on two sets in the disjoint-set
    void unionSets(unordered_map<string, string>& parent, const string& city1, const string& city2);
};

#endif
