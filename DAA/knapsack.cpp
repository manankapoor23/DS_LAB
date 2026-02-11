// fractional
// item can be added in fraction
// greedy approach mai kahi na kahi sorting to lagegi
#include <iostream>
using namespace std;

int knapsack_frac(vector<pair<int,int>> &ans){
    sort(ans.begin(),ans.end(),[](auto &a,auto &b){
        double r1 = (double)a.first/a.second;
        double r2 = (double)b.first/b.second;
        return r1>r2;
    });
    int W; // capacity of knapsack
    cout<<"Enter the capacity of knapsack: ";
    cin>>W;
    int final_value =0;
    for(int i =0;i<ans.size();i++){
        if(W==0)
            break; 
        if(ans[i].second<=W){
            final_value+=ans[i].first;
            W-=ans[i].second;
        }
        else{
            final_value+=ans[i].first*((double)W/ans[i].second);
            W=0;
        }
}
    return final_value;
}

int main(){
    vector<pair<int,int>> ans = {{3,10},{3,15},{2,10},{5,12},{1,8}};
    int max_value = knapsack_frac(ans);
    cout<<"Maximum value in Knapsack = "<<max_value;
    



}