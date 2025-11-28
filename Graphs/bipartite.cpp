#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> colour(n,-1);
    queue<int> q;
    q.push(0);
    colour[0]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:graph[node]){
            if(colour[it]==-1){
                colour[it]= !colour[node];
                q.push(it);
            }
            else if(colour[it]==colour[node]){
                return false;
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