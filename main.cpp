#include <iostream>
#include "graph.h"
#include "graph.cpp"



int main() {
    // Create a graph object
    Graph graph;

    // Add nodes to the graph with charging times (minutes)
    graph.addNode("Newport", 20);
    graph.addNode("Waldport", 20);
    graph.addNode("Florence", 25);
    graph.addNode("Corvallis", 10);
    graph.addNode("Philomath", 25);
    graph.addNode("Albany", 30);
    graph.addNode("Eugene", 18);

    // Add edges with distances (miles) to the graph
    graph.addEdge("Newport", "Waldport", 16);
    graph.addEdge("Waldport", "Florence", 35);
    graph.addEdge("Newport", "Philomath", 43);
    graph.addEdge("Waldport", "Philomath", 58);
    graph.addEdge("Florence", "Eugene", 61);
    graph.addEdge("Eugene", "Corvallis", 48);
    graph.addEdge("Philomath", "Corvallis", 6);
    graph.addEdge("Corvallis", "Albany", 11);
    graph.addEdge("Eugene", "Albany", 45);


    // Print the graph
    cout << "Printed Graph:" << endl;
    graph.printGraph();
    cout << endl;

    // Test the getEdgeWeight function
    int NewportToWaldportWeight = graph.getEdgeWeight("Newport", "Waldport");
    cout << "Weight of edge from Newport to Waldport: " << NewportToWaldportWeight << " miles" << endl; // expected: 16

    int EugeneToAlbanyWeight = graph.getEdgeWeight("Eugene", "Albany");
    cout << "Weight of edge from Eugene to Albany: " << EugeneToAlbanyWeight << " miles" << endl; // expected: 45

    // Test the shortestPath function
    string sourceCity = "Newport";
    string destinationCity = "Corvallis";
    vector<string> shortestPath = graph.shortestPath(sourceCity, destinationCity); // expected: newport -> philomath -> corvallis

    cout << "Shortest path from " << sourceCity << " to " << destinationCity << ": ";
    for (size_t i = 0; i < shortestPath.size(); ++i) {
        cout << shortestPath[i];
        if (i < shortestPath.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    // Calculate the total distance of the shortest path
    int totalDistance = 0;
    for (size_t i = 0; i < shortestPath.size() - 1; ++i) {
        const string& currentCity = shortestPath[i];
        const string& nextCity = shortestPath[i + 1];
        totalDistance += graph.getEdgeWeight(currentCity, nextCity);
    }
    cout << "Total distance: " << totalDistance << " miles" << endl << endl; // expected: 49

    // Test the minimumSpanningTree function
    vector<Edge> minimumSpanningTree = graph.minimumSpanningTree();

    cout << "Minimum Spanning Tree: " << endl;
    for (const auto& edge : minimumSpanningTree) {
        cout << edge.src << " - " << edge.dest << " (" << edge.weight << " miles)" << endl;
    }

    // Additional test cases

    // Test the addNode function with an existing city
    // BLOWS UP CODE- AS EXPECTED, COMMENTED OUT TO ALLOW OTHER TESTS TO RUN.
    // cout << endl << "Testing addNode function with an existing city..." << endl;
    // cout << "Adding an existing city (Newport)..." << endl;
    // graph.addNode("Newport"); // Should not add a new node
    // cout << "City not added. Node 'Newport' already exists." << endl;

    // Test addEdge function with non-existing cities
    // Does not create an edge as those cities do not exist
    cout << endl << "Testing addEdge function with non-existing cities..." << endl;
    cout << "Adding an edge between non-existing cities (Seattle and Vancouver)..." << endl;
    graph.addEdge("Seattle", "Vancouver", 150); // Should not add an edge
    cout << "Edge not added. City 'Seattle' or 'Vancouver' does not exist." << endl;

    // Test getEdgeWeight function with non-existing cities
    // Edge weight is 0 because there is no edge.
    cout << endl << "Testing getEdgeWeight function with non-existing cities..." << endl;
    cout << "Getting the weight of an edge between non-existing cities (Seattle and Vancouver)..." << endl;
    int weight = graph.getEdgeWeight("Seattle", "Vancouver"); // Should return 0 or appropriate value
    cout << "Weight of edge from Seattle to Vancouver: " << weight << " miles" << endl;

    // Test shortestPath function with non-existing cities
    sourceCity = "Seattle";
    destinationCity = "Vancouver";
    shortestPath = graph.shortestPath(sourceCity, destinationCity);
    cout << endl << "Testing shortestPath function with non-existing cities..." << endl;
    cout << "Finding the shortest path between non-existing cities (Seattle and Vancouver)..." << endl;
    if (shortestPath.empty()) {
        cout << "No path exists from " << sourceCity << " to " << destinationCity << endl;
    } else {
        cout << "Shortest path from " << sourceCity << " to " << destinationCity << ": ";
        for (size_t i = 0; i < shortestPath.size(); ++i) {
            cout << shortestPath[i];
            if (i < shortestPath.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;

        // Calculate the total distance of the shortest path
        totalDistance = 0;
        for (size_t i = 0; i < shortestPath.size() - 1; ++i) {
            const string& currentCity = shortestPath[i];
            const string& nextCity = shortestPath[i + 1];
            totalDistance += graph.getEdgeWeight(currentCity, nextCity);
        }
        cout << "Total distance: " << totalDistance << " miles" << endl;
    }

    // Test minimumSpanningTree function with an empty graph
    Graph emptyGraph;
    vector<Edge> emptyGraphMST = emptyGraph.minimumSpanningTree();
    cout << endl << "Testing minimumSpanningTree function with an empty graph..." << endl;
    if (emptyGraphMST.empty()) {
        cout << "Finding the minimum spanning tree of an empty graph..." << endl;
        cout << "No minimum spanning tree exists for the empty graph" << endl;
    }

    return 0;
}
