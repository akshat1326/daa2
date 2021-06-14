/*! \file class_graph.h*/
#include <bits/stdc++.h>
#include "dfs_function.h"
/**
 * This file contains the main section of the code.\n
 * It comprises of the Graph class which contains all the important function to find the strongly connected components.\n
 *
 *
 */
class Graph {
public:
    int v;/*!< This defines the number of vertices's present in the current Graph. */
    unordered_map<int,unordered_set<int>> adj;/*!< This defines the adjacency list for the graph.*/
    unordered_map<int,unordered_set<int>> adjT;/*!< This defines the transposed adjacency list for the graph.*/

    void initialise_graph(int v);/*!< This is the initialization function which acts as a constructor.
                                    @param v : is the number of nodes of in the network.*/
    void add_edge(int a, int b);/*!< This function is used to store the edge from a to b  in the adjacency list and an edge from b to a in the transposed adjacency matrix.
                                    @param a : refers to the first end point of the edge @param a : refers to the second end point of the edge .*/
    int findSCC();/*!< This is the main function which is used to find the strongly connected components in the graph which is called by the main function and it calls all other function to perform the task .*/
};

void Graph:: initialise_graph(int v){
    this->v = v;
}

void Graph::add_edge(int a, int b) {
        adj[a].insert(b);
        adjT[b].insert(a);
}
int Graph::findSCC(){
    int count = 0;
    //declaring a stack will be used for storing vertices
    stack<int> s;
    //boolean array to check status of the nodes
    bool *visited = new bool[v];
    // initializing the visited status of the nodes to false/
    for(int i = 0; i < v; i++)
        visited[i] = false;
    //performing the dfs and storing the visited nodes in the stack declared earlier.
    for(int i = 0; i < v; i++)
        if(visited[i] == false)
            DFS(adj,adjT,i, visited,s,true);
    //Again putting the visited status of all nodes to false.
    for(int i = 0; i < v; i++)
        visited[i] = false;
    //now using the nodes present in the stack to preform the dsf and find strongly connected components.
    while (s.empty() == false) {
        int top = s.top();
        s.pop();

        if (visited[top] == false) {
            max_local=1;
            count++;
            DFS(adj,adjT,top, visited,s,false);
            if(max_local>max_val)
                max_val=max_local;
        }
    }
    return count;
}
