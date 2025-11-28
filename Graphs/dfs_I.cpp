#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsIterative(int start, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
        }

        // Push all unvisited neighbours
        // Reverse order to match recursive DFS order
        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neigh = adj[node][i];
            if (!visited[neigh]) {
                st.push(neigh);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<int> adj[n];

    cout << "Enter edges:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }

    cout << "DFS starting from node 0: ";
    dfsIterative(0, adj, n);

    return 0;
}
