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
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Grpah_Node{
    char data;  // 'A', 'B' etc
    
    //storing edges twice for each node pair, not effecient but sure look, could be used for directed - Anton
    int edge[MAX_NODE_CONNECTIONS];//edge is the index of another node or vertex in array of vertices
    int number_of_edges;

    //the above array doesnt store weights, so we're gonna do that here
    int weights[MAX_NODE_CONNECTIONS];

    //this is all for Dijkstra
    bool is_permanent;
    int parent_index;
    int shortest_length;
} Graph_Node;

typedef struct Graph {
    //adjaceny lists stored in nodes, cus sets are stupud cus you have to search so many times to find anything -Anton
    Graph_Node vertices[MAX_NODES];  //array which stores each vertices, which in tern stores all edges
    int number_vertices;    //number of vertices in graph
} Graph;

int add_vertex_to_graph(Graph* graph, char data){//just adds the node unconnected, will need another fucntion to add edges, for simplicity of this fucntion
    assert(graph != NULL);//ensures that you are passed a valid graph, will crash program
    assert(graph->number_vertices < MAX_NODES);//ensure there is room still in the array

    int index = graph->number_vertices;
    graph->vertices[index].data = data;
    graph->vertices[index].number_of_edges = 0;
    graph->vertices[index].is_permanent = false;
    graph->vertices[index].parent_index = -1;
    graph->vertices[index].shortest_length = 999999;

    graph->number_vertices++;

    return index;
}

// add an edge in both directions - to-from and also from-to
void add_edge_undirected(Graph* graph, int start_vertex_index,
    int end_vertex_index, int weight){
        assert(graph);
        assert(start_vertex_index > -1 && start_vertex_index < graph->number_vertices);
        assert(end_vertex_index > -1 && end_vertex_index < graph->number_vertices);

        {
        //  go to start vertex, add an edge to it if there is space left, 
        //  and add weight
        int first_ver_index_count = graph->vertices[start_vertex_index].number_of_edges;
        assert(first_ver_index_count < MAX_NODE_CONNECTIONS);
        graph->vertices[start_vertex_index].edge[first_ver_index_count] = end_vertex_index;
        graph->vertices[start_vertex_index].weights[first_ver_index_count] = weight;
        }

        
        {
        //repeat for second vertex
        int second_ver_index_count = graph->vertices[end_vertex_index].number_of_edges;
        assert(second_ver_index_count < MAX_NODE_CONNECTIONS);
        graph->vertices[end_vertex_index].edge[second_ver_index_count] = start_vertex_index;
        graph->vertices[end_vertex_index].weights[second_ver_index_count] = weight;
        }
    }


int main(){
    Graph my_graph;
    my_graph.number_vertices = 0;

    int letter_indices[150];
    memset(letter_indices, -1, sizeof(int)*36);

    for (int i = 'A'; i <= 'L'; i++)
    {
        letter_indices[i] = add_vertex_to_graph(&my_graph, (char)i);

    }
    add_edge_undirected(&my_graph, letter_indices[(int)'A'], letter_indices[(int)'B'], 1);


    return 0;
}