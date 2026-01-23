#include <iostream>
using namespace std;

int main(){
    const int rows = 6, cols = 6;
    int s[100][3];
    int arr[rows][cols] = {
        {0, 0, 3, 0, 4, 0},
        {0, 0, 5, 7, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 9, 8, 0}
    };

    int k = 1 ;
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j]!=0){
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=arr[i][j];
                k++;

            }
        }
    }
    //printing the sparse matrix 
    cout << "Row\tColumn\tValue\n";
    for(int i = 1; i < k; i++){
        cout << s[i][0] << "\t" << s[i][1] << "\t" << s[i][2] << endl;
    }
    cout << "Total non-zero elements: " << k - 1 << endl;
}