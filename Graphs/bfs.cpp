#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// BFS ON GRAPH using queue and adjacency list

void BFS(int start,vector<int> adj[],int n){
    vector<bool> visited(n,false); // vector of n size with all values of not visited
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        // now we have to explore this node 
        for(int neighbour :adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    cout<<endl;

    // runs on all of its degrees , runs for number of degrees of that node 
    // TC -> O(n)+O(2E) , E is edges

}


int main(){
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<int> adj[100];
    cout<<"enter edges (u v):\n";
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout<<"enter starting node :";
    cin>>start;

    BFS(start,adj,n);

}