/*! \file dfs_function.h*/
#include <bits/stdc++.h>
using namespace std;
/**
 * @brief This is a recursive function used to perform  DFS i.e. depth first search .
 *
 *
 * @param adj : is the address of the adjacency list of the graph on which we are working.
 * @param adjT : is the address of the transposed adjacency list of the graph on which we are working.
 * @param v : denotes the number of nodes in the graph
 * @param visited : is the boolean array used to mark the visited vertices.
 * @param s : is the stack on which edges are pushed while parsing the adjacency list and performing dfs.
 * @param  : is the stack on which edges are pushed while parsing the adjacency list and performing dfs.
 * @param  : is the stack on which edges are pushed while parsing the adjacency list and performing dfs.
 * @param  : is a boolean variable which tells whether we are calling dfs for adjacency list and storing in the stack or for the transposed adjacency matrix.
 */
 void DFS(unordered_map<int, unordered_set<int>> &adj,unordered_map<int, unordered_set<int>> &adjT,int v, bool visited[],stack<int>&s,bool flag) {
     //changing status of the visited node to true
    visited[v] = true;
    //flag is truewhen working for the adjacency list
    if(flag){
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                //recursive calling of dfs
                DFS(adj,adjT,*i, visited,s,true);
        //pushing results of dfs into the stack
        s.push(v);
    }
    //flag is false for the transposed adjacency list
    else{
        for (auto i = adjT[v].begin(); i != adjT[v].end(); ++i)
            if (!visited[*i]){
                    // for finding the largest connected component
                    max_local++;
                    //recursive calling of dfs
                    DFS(adj,adjT,*i, visited,s,false);
            }
    }
}
