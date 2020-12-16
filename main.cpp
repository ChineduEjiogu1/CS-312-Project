#include <iostream>
#include <string> 
#include <set>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;
#include "LabeledGraph.cxx"



int main() {
  /* Testing breath first search

  0 -1 
  1 3 
  2 0 
  3 4 // I believe its the same result as 3,5 path
  4 2 
  5 2 
  
  // -1 is null value, my output was almost similar to the          output in the pdf.

  
  */
  // LabeledGraph g;
  // g.add_vertex("Avatar");
  // g.add_vertex("Zoe Saldana");
  // g.add_vertex("Sam Worthington");
  // g.add_vertex("Michelle Rodriguez");
  // g.add_vertex("Guardians of the Galaxy");
  // g.add_vertex("Chris Pratt");
  // g.add_vertex("Vin Diesel");
  // g.add_vertex("The Fate of the Furious");

  // g.add_edge("Avatar", "Zoe Saldana");
  // g.add_edge("Avatar","Sam Worthington");
  // g.add_edge("Avatar","Michelle Rodriguez");
  // g.add_edge("Zoe Saldana","Guardians of the Galaxy");
  // g.add_edge("Michelle Rodriguez","The Fate of the Furious");
  // g.add_edge("Guardians of the Galaxy","Chris Pratt");
  // g.add_edge("Guardians of the Galaxy","Vin Diesel");
  // g.add_edge("Vin Diesel","The Fate of the Furious");
  //cout << g << endl;
  
  LabeledGraph g("movies_short.txt");
  //cout << g;
  
  // Testing task 8
  
  
  

  // cout << "\n";

  cout << "Please enter source vertex: " << endl;
  
  string sourceVextex = "";
  string target = "";

  getline(cin,sourceVextex);

  
  std::map<int,int> m = g.breathFirstSearch(g.index(sourceVextex));

  for(auto elem : m)
  {
   std::cout << g.label(elem.first) << " " << g.label(elem.second) << " " << "\n";
  }
  
  cout << "All (shortest) paths from " << sourceVextex << " to other vertices have been created." << endl;
  
  while(true){
    cout << "Enter a target vertex and I will display the shortest path from " << sourceVextex << " to that vertex (-1 to exit): " << endl;
    
    getline(cin,target);

    if(target == "-1"){
      cout << "Goodbye" << endl;
      exit(EXIT_SUCCESS);
    }
    
    std::vector<int> vec = g.pathTo(m,g.index(target));
  
    for(auto elem : vec)
    {
      std::cout << g.label(elem) << " ";
      if(elem != vec.at(vec.size() - 1)){
        cout << " --> ";
      }
    }
    cout << "\n";
    cout << "\n";
  }
  cout << "\n";
 

  // cout << "Please enter movie name or actor/actress name" << endl;
  // string name = "";
  // getline(cin, name);
  // //call index on name
  // int index = g.index(name);
  // if(index != -1){
  //   //call neighbors on index on previous line
  //   set<int>neighbors = g.neighbors(index);
  //   // iterate over given set (numberical) from previous line
  //     for (auto it = neighbors.begin(); it != neighbors.end(); ++it){
  //       // in body of iteration print the label that corresponds to the index; 
  //       cout << ' ' << *it << " " << g.label(*it) << endl;
  //     }
  // }else{
  //   bool found = false;
  //   name = delimiterOfWords(name);
  //   cout << "Oops!" << endl;
  //   for(int i = 0; i < g.V(); i++ ){
  //     //if(g.label(i).find(name) != string::npos){
  //       if(findStringIC(g.label(i), name)){
  //       cout << g.label(i) << endl;
  //       found = true;
  //     }
  //   }
  //   if(found){
  //     cout << "\n" << "Not sure what you meant, try searching for one of the above results." << endl;
  //   }
  //   cout << "Sorry the exact movie or actor/actress is not found" << endl; 
  // }

}