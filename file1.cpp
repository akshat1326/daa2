/*! \file file1.cpp*/
/*! @author Akshat Gupta(2017A7PS1669H)*/
/*!
@brief This code implements the implementation of finding the strongly connected compopnents using  Kosarajus algorithm. The input is taken by .txt file in the function which creates an instance of the graph and finds strongly connected components using graph class functions.
*/

/*!
@mainpage
The algorithm we are typing to implement is as follows:\n
1) Create an empty stack S and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. In the above graph.\n
2) Reverse directions of all arcs to obtain the transpose graph(we have used adjT for this purpose).\n
3) One by one pop a vertex from S while S is not empty. Let the popped vertex be v. Take v as source and do DFS. The DFS starting from v prints strongly connected component of v.\n

*/
#include <bits/stdc++.h>
#include <iostream>
#include "class_graph.h"

int max_val=0;
int max_local=0;

int main(int argc, char *argv[]) {
    // declaring an instance of class Graph
    Graph g;
    //taking input from txt file
    ifstream fin;
    fin.open(agrv[1], ios::in);
    int n,m,a,b;
    fin >> n >>m;
    g.initialise_graph(n);
    //fin >>a>>b;
    cout<<n<<"   "<<m<<endl;
    int n1=n;
    int fromEdge, toEdge;
    fin >> fromEdge >> toEdge;
    g.add_edge(fromEdge, toEdge);
    // each line entry in txt file shows a edge hence storing then in an adjacency list.
    while(!fin.eof()){
        fin >> fromEdge >> toEdge;
        if(fromEdge>n)
            n = fromEdge;
        if(toEdge>n)
            n = toEdge;
        g.add_edge(fromEdge, toEdge);
    }
    g.v =n;
     vector<vector<int>> result;
    // using clock to find exection time.
    clock_t start, end;
    start = clock();
    cout << "Following are strongly connected components in given graph "<<endl;
    int noOfComponents = g.findSCC();
    //stop the clock
    end = clock();
    int diff = n-n1;
    n=n1;
    //producing results.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<< "Number of nodes = "<<n<<endl;
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5)<<endl;

    cout <<"number of components : "<< noOfComponents-diff<<endl;
    cout <<"nodes in largest connected component : "<< max_val<<endl;
    return 0;
}
