#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int node , vector<int> adj[],vector<bool> &vis,vector<int> &ls){
    vis[node]=true;
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!vis[it]){
            DFS(it,adj,vis,ls);
        }
    }

}

int main(){
    int n;
    cout<<"Enter Number of Nodes: ";
    cin>>n;
    int m;
    cout<<"Enter Number of edges: ";
    cin>>m;
    vector<int> adj[100];
    cout<<"enter edges (u v): \n";
    for(int i =0;i<m;i++){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n,false);

    int start;
    cout<<"Enter starting node :";
    cin>>start;
    vector<int> mi;
    DFS(start,adj,vis,mi);
}