#ifndef LABELED_GRAPH_H
#define LABELED_GRAPH_H

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

class LabeledGraph {
public:

    // CONSTRUCTOR
    LabeledGraph()  {nedges = 0; }
    LabeledGraph(std::string fileName);

    // MODIFICATION MEMBER FUNCTIONS
    //adds a vertex with a specifc label
    void add_vertex(std::string vlabel); // it has parameters now becuase we need to provide a label and label for are new vertex.

    //adds an edge from vertex with source label to vertex with target label
    void add_edge(std::string source, std::string target); // parameters of add_edge has change from numberical value to string value for labeling.

    // CONSTANT MEMBER FUNCTIONS
    int V( ) const { return vertices.size(); } //number of vertices
    int E( ) const { return nedges; }       //number of edges
    bool contains(std::string vlabel) const;     //does graph contain vertex with label vlabel?
    std::set<int> neighbors(int v) const;  //returns the vertices adjacent to vertex v
    std::string label(int v) const;     //returns the label of vertex v
    int index(std::string vlabel);           //returns the index of the vertex with label vlabel

    // breath first search algorithm
    std::map<int, int> breathFirstSearch(int v);

    std::vector<int> pathTo(map<int, int> & parent_map, int target);


    // OVERLOADED OUTPUT OPERATOR
    friend std::ostream& operator<< (std::ostream &out, const LabeledGraph &g);

private:
  int nedges;
  std::vector<std::set<int> > vertices; // adjacency list that represents the graph.
  std::vector<std::string> labels; // this variable is used to store the names of the actors/actress and the movie titles.
  std::map<std::string, int> indexedLabels; // This is a key value pair that maps the names of actors/actress and movie titles and gives a numerical  index to used look up in the vertices data structure.
};

#endif