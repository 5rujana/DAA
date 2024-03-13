/*The algorithm starts with an empty spanning tree. 
The idea is to maintain two sets of vertices. 
The first set contains the vertices already included in the MST,
 and the other set contains the vertices not yet included.
At every step, it considers all the edges that connect the two sets
and picks the minimum weight edge from these edges.
After picking the edge, it moves the other endpoint of the edge to the set containing MST. */



/* A group of edges that connects two sets of vertices in a graph is called cut in graph theory.
 So, at every step of Prim’s algorithm, find a cut, pick the minimum weight edge from the cut, 
 and include this vertex in MST Set (the set that contains already included vertices). */


#include <iostream>
#include <climits>
using namespace std;

#define V 6

//vertex with minimum key value,from set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index;
    for(int v = 0; v<V; v++){
        if(!mstSet[v]&& key[v]<min){
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}


//function to print the constructed MST stored in parent[]
// "parent" of a vertex refers to another vertex in the tree that is directly connected to the current vertex.
void printMst(int parent[], int graph[V][V]){
    cout << "Edge \t Weight" << endl;
    for( int i = 1 ;i<V;i++){
        cout<<parent[i] << " - " << i<< " \t" <<graph[i][parent[i]]<<endl;
    }
}

void primMST(int graph[V][V]){
    int parent[V];//array to store constructed MST
    int key[V];//key values used to pick minimum weight edge in cut
    bool mstSet[V];//to represent set of vertices not yet included in MST

    //initialize all keys as infinite
    for(int i = 0; i<V ;i++){
        key[i]=INT_MAX; 
        mstSet[i]=false;
    }

    key[0]=0;

    parent[0]=-1; //first node is always root of MST
    for(int count = 0;count < V-1;count++){
         //wht count<V-1? because there are V-1 edges in MST
         int u = minKey(key,mstSet);
         //why u = minKey(key,mstSet)? because we want to find the vertex with minimum key value
            mstSet[u]=true; //add the picked vertex to the MST set

        for(int v = 0; v<V;v++){
            //update key value and parent index of the adjacent vertices of the picked vertex
            //the vertices that are not yet included in the MST
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
            //why graph[u][v] && mstSet[v]==false && graph[u][v]<key[v]?
            //because we want to update the key value of the vertex if it is not in the MST set
            //and the weight of the edge is less than the key value of the vertex
            //and there is an edge between u and v
            //why parent[v]=u? because we want to update the parent of the vertex to u
            //why key[v]=graph[u][v]? because we want to update the key value of the vertex to the weight of the edge
        }

    }
    printMst(parent,graph);
}

int main(){
    int graph[V][V];
    cout << "Enter the adjacency matrix for the graph (size " << V << "x" << V << "):" << endl;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
    }
    primMST(graph);
    return 0;
}