#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> dijkstra(int N , vector<vector<pair<int,int>>> &adj , int S){
    // here N is number of nodes and S is the starting node
    
    // make a visited array but of infinite distances
    // vector<int> dist(N,INT_MAX);
    // dist[S]=0;

    // set<pair<int,int>> st;
    // st.insert({0,S}); // set of distance , node

    // while(!st.empty()){

    //     auto it = *(st.begin());
    //     st.erase(st.begin());

    //     int distance = it.first;
    //     int node = it.second;

    //     for(auto &it2 : adj[node]){
    //         int adjNode = it2.first;
    //         int edgeWeight = it2.second;

    //         if(distance + edgeWeight<dist[adjNode]){
    //             if(dist[adjNode]!=INT_MAX){
    //                 st.erase({dist[adjNode],adjNode});
    //             }
    //             dist[adjNode]=distance+edgeWeight;
    //             st.insert({dist[adjNode],adjNode});
    //         }

    //     }
    // }
    // return dist;
    vector<int> dist(N,INT_MAX);
    set<pair<int,int>> st;

    st.insert({0,S});
    dist[S]=0;

    while(!st.empty()){
        auto it = *(st.begin());
        st.erase(it);
        int distance = it.first;
        int node = it.second;

        for(auto &it : adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(distance+edgeWeight<dist[adjNode]){
                if(dist[adjNode]!=INT_MAX){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=distance+edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    
    vector<vector<pair<int, int>>> adj(n);

    // Example graph (undirected)
    adj[0].push_back({1, 2}); // what is 1 and 2 here 
    // 1 is the adjacent node and 2 is the weight of edge
    // what is 0 here ? 0 is the current node and it means from 0 to 1 weight is 2
    // can i keep the format same ? like for it.second i can keep weight and for it.first i can keep node
    adj[1].push_back({0, 2});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 7});
    adj[3].push_back({1, 7});

    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    vector<int> dist = dijkstra(n, adj, 0);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < n; ++i)
        cout << "Node " << i << ": " << dist[i] << "\n";
}