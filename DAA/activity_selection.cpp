#include <iostream>
using namespace std;
#include <vector>

int activity_count(vector<pair<int,int>> &ans){
    int count =1;
    vector<pair<int,int>> v ;
    for(int i =0;i<ans.size();i++){
        pair<int,int> p = make_pair(ans[i].first, ans[i].second);
        v.push_back(p);

    }

    // sorting the vector
    sort(v.begin(),v.end(),[](auto &a,auto &b){
        return a.second<b.second;
    });

    int ans_end = v[0].second;
    for(int i =1;i<v.size();i++){
        if(ans_end<=v[i].first){
            count++;
            ans_end=v[i].second;
        }
    }

    return count;
    
}

int main(){
    vector<pair<int,int>> ans = {{1,3},{3,5},{2,4},{5,7},{0,6}};
    int count = activity_count(ans);
    cout<<count;
}