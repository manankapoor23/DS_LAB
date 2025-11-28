#include <vector>
#include <iostream>
using namespace std;
bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> colour(n,-1);

    for(int start = 0; start < n; start++) {
        if(colour[start] == -1) {

            queue<int> q;
            q.push(start);
            colour[start] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int it : graph[node]) {
                    if(colour[it] == -1) {
                        colour[it] = !colour[node];
                        q.push(it);
                    }
                    else if(colour[it] == colour[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(){

    vector<vector<int>> graph = {
    {1, 4},     // 0
    {0, 2},     // 1
    {1, 3},     // 2
    {2, 4},     // 3
    {0, 3}      // 4
};


    cout<<(isBipartite(graph)?"YES":"NO")<<endl;


}