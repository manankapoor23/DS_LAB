#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(int start,vector<int> adj[],int n){
    stack<int> st;
    vector<bool> visited(n,false);

    st.push(start);

    cout<<"DFS TRAVERSAL: ";
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            cout<<node<<" ";
            visited[node]=true;
        }
        for(int i = adj[node].size()-1;i>=0;i--){
            int neighbour = adj[node][i];
            if(!visited[neighbour]){
                st.push(neighbour);
            }
        }
    }
    cout<<endl;
}

int main(){
    int n,m;
    cout<<"enter number of nodes : ";
    cin>>n;
    cout<<"enter number of edges";
    cin>>m;

    vector<int> adj[100];
    cout<<"enter eedges (u v): \n";
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout<<"which node to start from: ";
    cin>>start;

    DFS(start,adj,n);
}