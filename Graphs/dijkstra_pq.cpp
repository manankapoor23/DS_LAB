#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> dijkstra(int N , vector<vector<pair<int,int>>> &adj,int S){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // minHeap;
    vector<int> dist(N); // here N is the number of nodes or vertices
    // push all infinite values into that vector 
    for(int i =0;i<N;i++){
        dist[i]=INT_MAX; // 
    }
    dist[S]=0; // make wtvr we give the starting vertice as 0 bcs dist is always 0 in start

    pq.push({0,S}); // push {0,start}

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        for(auto &it:adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(distance+edgeWeight<dist[adjNode]){
                dist[adjNode]=distance+edgeWeight;
                pq.push({dist[adjNode],adjNode});
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