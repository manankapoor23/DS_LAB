#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int coins;
    cin>>coins;
    vector<int> a(coins);

    for(int i=0;i<coins;i++){
        cin>>a[i];
    }
    int total_sum = 0;
    for(int coin:a){
        total_sum+=coin;
    }
    sort(a.begin(),a.end(), greater<int>());

    int count = 1;
    int curr_sum = a[0];
    for(int i=1;i<coins;i++){
                curr_sum+=a[i];
        count++;

        if(curr_sum > total_sum - curr_sum){
            cout << count << endl;
            break;
        }

    }


    return 0;

}

