#include<iostream>
#define MAX 100
using namespace std;
int arr[MAX+1][MAX+1]={0, };
int visit[MAX+1][MAX+1]={0, };
int dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};
int N;
void dfs(int n,int m,int height){
    if(n >= N || m >= N || n < 0 || m < 0) return;
    if(arr[n][m] <= height) return;
    if(visit[n][m]) return;
    visit[n][m] = 1;
    for(int i=0;i<4;i++){
        dfs(n+dy[i],m+dx[i],height);
    }
}
int main()
{
    int maxHeight=-1,ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            maxHeight = max(maxHeight,arr[i][j]);
        }
    }

    for(int i=0;i<maxHeight;i++){
        int cnt = 0;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(!visit[j][k] && arr[j][k] > i){
                    cnt++;
                    dfs(j,k,i);
                }
            }
        }
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                visit[j][k] = 0;
            }
        }
        ans = max(ans,cnt);
    }
    cout<<ans;
    return 0;
}