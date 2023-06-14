# graphFinal
Final Project
I have decided to create a graph that acts as a map, and can help locate EV Charging Stations within a town or city. The vertices have a value of city name and charging time (minutes)
while the edges have a source, destination, and distance (miles). I have used Dijkstra's algorithm to find the shortest path and have used Kruskal's algorithm for the minimum spanning tree. 

(20%) Create a design before you start coding that describes or shows how a graph structure could be used to store some kinds of data and attempt to solve some kind of problem (yes, this can be a game that needs a graph to represent a map!):
  My design has been done in OneNote and I have shared screenshots of my design work. I have also added extensive comments and drew diagrams to help illustrate my thought process and
  the full design steps. designsc_1, designsc_2, and designsc_3 are the names of the design files.

(20%) Create some tests (at least two for each piece of functionality) before you start coding...
  I have created 2 tests for each function: these tests can be found in designsc_3 which was created before I began coding,
  and they can be found in my main.cpp file as I tested each of my functions twice within the main. 
  
  A brief overview of my tests are: 
  addNode test = create a node, then print graph and make sure the node is in the graph
  
  addEdge test = add an edge between 2 nodes then print the graph and make sure the node was added.
  
  printGraph test = it is tested twice while printing the edge and the graph.
 
  minimumSpanningTree test = ask for the min spanning tree then compare it to the one I found.
  
  shortestPath test = Call the function for the shortest path from Newport to Corvallis and compare it to the expected value.
  
(40%) Implement a graph class with at least (this category effectively combines implementation and specification, partly to emphasize getting the algorithms working!):
(5%) a function to add a new vertex to the graph (perhaps add_vertex(vertex_name)),

  I have implemented this function as the addNode(city, charging time). This can be seen in the graph.h and graph.cpp files and  the functionality/test can be found in the main.cpp file.

(5%) a function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination)),

  I have implemented this function as the addEdge(source, destination, distance (miles)) This can be seen in the graph.h and graph.cpp files and  the functionality/test can be found in the main.cpp file.

(15%) a function for a shortest path algorithm (perhaps shortest_path(source, destination)),

  I have implemented this function using Dijkstra's algorithm as shortestPath(sourceCity, destinationCity) This can be seen in the graph.h and graph.cpp files and  the 
  functionality/test can be found in the main.cpp file.

(15%) a function for a minimum spanning tree algorithm (example min_span_tree()).

  I have used Kruskal's algorithm to implement this function and it is called as minimumSpanningTree() This can be seen in the graph.h and graph.cpp files 
  and  the functionality/test can be found in the main.cpp file.
  I also have a getEdgeWeight function that I added after the design phase: this function takes in source, destination and retrieves the weight between the 2 nodes.

(10%) Analyze the complexity of all of your graph behaviors (effectively a part of our documentation for grading purposes)
  
  addNode(cityName, int chargingTime): The complexity is O(1) because it involves inserting a new entry into an unordered map.

  addEdge(sourceCity, destinationCity, int distance): The complexity is O(1) since it involves inserting entries into two unordered maps and adding an edge to a vector.

  getEdgeWeight(sourceCity, destinationCity): This function retrieves the weight of an edge between two cities. The complexity is O(1) since it involves a constant-time lookup in an unordered map.

  shortestPath(sourceCity, destinationCity): The worst-case complexity is O((K + E) log V), where K is the number of cities (nodes) and E is the number of edges. This complexity arises from the use of a priority     queue and the need to look through the edges and compare their edge weight.

  minimumSpanningTree(): The complexity is O(E log E), where E is the number of edges. This complexity arises from sorting the edges and performing union-find operations.

  printGraph(): This function prints the graph. The complexity is O(K + E), where K is the number of cities (nodes) and E is the number of edges. This complexity arises from iterating over the nodes and their         neighbors.

(10%) Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).

ALL TESTS CAN BE FOUND IN main.cpp and within the designsc_3 file that is also in the repo.

addNode function can be found in graph.cpp file from line 7 to line 15.

addEdge function can be found in graph.cpp file from line 17 to 26.

getEdgeWeight function can be found in graph.cpp file from line 28 to 37.

shortestPath function can be found in graph.cpp file from line 31 to 95.

minimumSpanningTree function can be found in graph.cpp file from line 97 to 123.

printGraph function can be found in graph.cpp file from line 125 to 137









