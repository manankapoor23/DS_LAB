#include <iostream>
using namespace std;
#define maxl 100

int main(){
    char str[maxl];
    char arr1[maxl];
    char arr2[maxl];
    cout<<"Enter the string : ";
    cin>>str;
    int i =0;
    int top =0;
    while(str[i]!='\0'){
        arr1[top]=str[i];
        top++;
        i++;
    }
    int j =0;
    while(top>0){
        arr2[j]=arr1[top-1];
        top--;
        j++;
    }
    arr2[j]='\0';
    cout<<"reversed string : "<<arr2;
    return 0 ;


}