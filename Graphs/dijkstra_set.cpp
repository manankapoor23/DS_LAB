#include <iostream>
#include <set>

using namespace std;

vector<int> dijkstra(int N , vector<vector<pair<int,int>>> &adj , int S){
    vector<int> dist(N);
    for(int i =0;i<N;i++){
        dist[i]=INT_MAX;
    }
    dist[S]=0;

    set<pair<int,int>> st;
    st.insert({0,S});

    while(!st.empty()){
        auto it = *(st.begin());
        st.erase(st.begin());

        int distance = it.first;
        int node = it.second;

        for(auto &it2 : adj[node]){
            int adjNode = it2.first;
            int edgeWeight = it2.second;

            if(distance+edgeWeight<dist[adjNode]){
                dist[adjNode]=distance+edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }else{
                st.erase({dist[adjNode],adjNode});
            }
        }


    }
    return dist;

}

int main() {
    int n = 5;
    
    vector<vector<pair<int, int>>> adj(n);

    // Example graph (undirected)
    adj[0].push_back({1, 2});
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