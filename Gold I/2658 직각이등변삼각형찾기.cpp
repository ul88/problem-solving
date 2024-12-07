#include<iostream>
#define MAX 10
using namespace std;
int arr[MAX+1][MAX+1]={0,};
pair<int,int> ans[3]={};
bool check(int n,int m){
    ans[0]={n,m};
    int i=n,j=m;

    while(arr[i][j] != 0){
        if(j+1 >= 10 || arr[i][j+1] == 0){
            i++;
            if(i >= 10 || arr[i][j] == 0){
                break;
            }
        }

    }
}
int main()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(!arr[i][j]) continue;

            if(check(i,j)){
                break;
            }
        }
    }
    return 0;
}