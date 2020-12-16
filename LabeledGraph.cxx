#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <queue>
#include "LabeledGraph.h"
//https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
using namespace std;

//Constructor
LabeledGraph::LabeledGraph(std::string fileName){

std::ifstream file(fileName);

std::string line;

std::vector<std::string> tokens;

while(std::getline(file, line)) {     // '\n' is the default delimiter
    //(std::getline(file, line));
    std::istringstream iss(line);
    std::string token;
    while(std::getline(iss, token, '/'))   // but we can specify a different one
      tokens.push_back(token);
    //cout << tokens[0] << endl;
    for(int i = 1; i < tokens.size(); i++){
      add_edge(tokens[0],tokens[i]);
    }
    tokens.clear();
}
  //myFile.close();
}



void LabeledGraph::add_vertex(string vlabel){
  labels.push_back(vlabel);
  indexedLabels.insert(pair<string, int>(vlabel, V()));
  set<int> s;
  vertices.push_back(s);
}


void LabeledGraph::add_edge(string source, string target){
    if (!contains(source))
      add_vertex(source);
    if (!contains(target))
      add_vertex(target);
    vertices[indexedLabels[source]].insert(indexedLabels[target]);
    vertices[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
  return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const{
    return vertices[v];
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    //return indexedLabels[vlabel];
    int temp = indexedLabels[vlabel];
    if(vlabel == labels[temp]){
      return temp;
    }else{
      return -1;
    }
    //return indexedLabels.at(vlabel);
}

std::map<int,int> LabeledGraph::breathFirstSearch(int v){
  if(v < 0 || v >= vertices.size()){
    cout << "Not a valid name" << endl; 
    exit (EXIT_FAILURE);
  }
  std::queue<int> open_set;
  std::set<int> visited;
  std::map<int,int> parent_map; //child -> parent map
  parent_map[v] = -1;
  open_set.push(v);
  visited.insert(v);
  while (!open_set.empty()){
    int parent_state = open_set.front();
    open_set.pop();
    for (int child_state : neighbors(parent_state)){
      if (visited.find(child_state) == visited.end()){
        parent_map[child_state] = parent_state;
        open_set.push(child_state);
        visited.insert(child_state);
      }
    }
  }
  return parent_map;
}

vector<int> LabeledGraph:: pathTo(map<int, int> & parent_map, int target){
  if(target < 0 || target >= vertices.size()){
    cout << "Not a valid name" << endl; 
    exit (EXIT_FAILURE);
  }

  std::vector<int> result;
  result.insert(result.begin(),target);
  
  int index = target;
    
  while( parent_map[index] != -1){
    index = parent_map[index];
    result.insert(result.begin(),index);
  }   
  return result;
}


ostream& operator<< (ostream &out, const LabeledGraph &g) {

  cout << "======================================" << endl;
  cout << "Graph Summary: " << g.V() << " vertices"<< "," << " " << g.E() << " edges" << endl;
  cout << "======================================" << endl;

  for(int i = 0; i < g.V(); i++)
  {
    out << g.labels[i] << "\n";
    for(const auto& b: g.neighbors(i))
    {
      out << "\t" << g.labels[b] << "\n";
    }
  }
  return out;
}