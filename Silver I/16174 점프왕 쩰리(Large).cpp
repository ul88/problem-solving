#include<iostream>
#define MAX 64
using namespace std;
int arr[MAX+1][MAX+1]={0,};
int visit[MAX+1][MAX+1]={0,};
int N;
bool flag = false;
void dfs(int n,int m){
    if(arr[n][m]==0) return;
    if(n == N-1 && m == N-1){
        flag=true;
        return;
    }
    if(n>N-1 || m>N-1) return;
    if(visit[n][m]) return;
    visit[n][m]=1;
    dfs(n+arr[n][m],m);
    dfs(n,m+arr[n][m]);
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    dfs(0,0);
    if(flag){
        cout<<"HaruHaru";
    }else{
        cout<<"Hing";
    }
    return 0;
}