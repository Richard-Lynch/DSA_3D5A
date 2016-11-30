/*
Richard Lynch  
12302202
30/11/16

Class demo of graph structure by Anton
*/

#define MAX_NODE_CONNECTIONS 10
#define MAX_NODES 64

//graph vertices are stored in an array of structs 
//because dynamic memory is hard 
//and pointers are scary
//-Anton

#include <stdio.h>

typedef struct Grpah_Node{
    char data;  // 'A', 'B' etc
    
    //storing edges twice for each node pair, not effecient but sure look, could be used for directed - Anton
    int edge[MAX_NODE_CONNECTIONS];//edge is the index of another node or vertex in array of vertices
    int number_of_edges

    //the above array doesnt store weights, so we're gonna do that here
    int weights[MAX_NODE_CONNECTIONS];

    //this is all for Dijkstra
    bool is_permanent;
    int parent_index;
    int shortest_length;
}   Graph_Node;

typedef struct Graph {
    //adjaceny lists stored in nodes, cus sets are stupud cus you have to search so many times to find anything -Anton
    Graph_Node vertices[];  //array which stores each vertices, which in tern stores all edges
    int number_vertices;    //number of vertices in graph
}   Graph;

int add_vertex_to_graph(Graph* graph, char data){//just adds the node unconnected, will need another fucntion to add edges, for simplicity of this fucntion
    assert(graph != NULL);//ensures that you are passed a valid graph, will crash program

}


int main(){
    Graph my_graph

    return 0;
}