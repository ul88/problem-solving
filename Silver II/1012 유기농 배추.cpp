#include<iostream>
#define MAX 50
using namespace std;
int arr[MAX+1][MAX+1]={0,};
int visit[MAX+1][MAX+1]={0,};
int dy[] = {-1,0,1,0}, dx[] = {0,-1,0,1};
int N,M,K;
void dfs(int n,int m){
    if(n>=N || m>=M || n<0 || m<0) return;
    if(!arr[n][m]) return;
    if(visit[n][m]) return;
    visit[n][m] = 1;
    for(int i=0;i<4;i++){
        dfs(n+dy[i],m+dx[i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>N>>M>>K;
        for(int i=0,a,b;i<K;i++){
            cin>>a>>b;
            arr[a][b] = 1;
        }

        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(visit[i][j]) continue;
                if(!arr[i][j]) continue;

                cnt++;
                dfs(i,j);
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                arr[i][j] = 0;
                visit[i][j] = 0;
            }
        }

        cout<<cnt<<"\n";
    }
    return 0;
}