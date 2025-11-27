#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(int start,vector<int> adj[],int n){
    // we use a stack here
    stack<int> st;
    // this is a visited array to keep a check of the nodes that we have visited
    vector<bool> visited(n,false);

    //push the first node into the stack
    st.push(start);

    cout<<"DFS TRAVERSAL: ";
    while(!st.empty()){ // iterate till the stack is not empty
        int node = st.top(); // node is currently the first one
        st.pop();
        if(!visited[node]){ // if that node is not visited then print it and visit it
            cout<<node<<" ";
            visited[node]=true;
        }
        for(int i = adj[node].size()-1;i>=0;i--){// loop from the adj list uve made for that specific node 
            int neighbour = adj[node][i];// lastest neighbour to nearest one but all
            if(!visited[neighbour]){ // if that neighbour is not visited
                st.push(neighbour);// push it 
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