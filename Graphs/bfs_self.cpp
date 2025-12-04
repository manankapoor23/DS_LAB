#include <iostream>
#include <queue>
using namespace std;

void bfs(int start , vector<vector<int>>&graph,int n){
    vector<bool> visited(n,false);
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    cout<<endl;
}


int main(){
    // int n,m;
    // cout<<"enter number of nodes : ";
    // cin >> n;
    // cout <<"enter number of edges: ";
    // cin>>m;
    // vector<int> adj[100];
    // cout<<"enter the edges u ,v :";
    // for(int i =0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);

    // }
    // int start;
    // cout<<"enter the starting : ";
    // cin>>start;
    // bfs(start,adj,n);
    vector<vector<int>> graph = {
        {1, 2},     // neighbors of 0
        {0, 3, 4},  // neighbors of 1
        {0},        // neighbors of 2
        {1},        // neighbors of 3
        {1}         // neighbors of 4
    };

    int start = 0; // starting node

    bfs(start, graph,graph.size());
    
}
