#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100
using namespace std;
int cnt = 0,N,M;
int visit[MAX+1][MAX+1]={0,};
int arr[MAX+1][MAX+1]={0,};
int dy[4]={0,-1,0,1}, dx[4] = {-1,0,1,0};
void dfs(int n,int m){
    if(n < 0 || n >= N || m < 0 || m >= M) return;
    if(arr[n][m]) return;
    if(visit[n][m]) return;
    visit[n][m] = 1;
    cnt++;
    for(int i=0;i<4;i++){
        dfs(n+dy[i],m+dx[i]);
    }

}
int main()
{
    int K;
    vector<int> v;
    cin>>N>>M>>K;
    for(int i=0,a,b,c,d;i<K;i++){
        cin>>a>>b>>c>>d;
        for(int j=b;j<d;j++){
            for(int k=a;k<c;k++){
                arr[j][k] = 1;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cnt = 0;
            dfs(i,j);
            if(cnt != 0) v.push_back(cnt);
            cnt = 0;
        }
    }

    sort(v.begin(),v.end());

    cout<<v.size()<<"\n";

    for(auto iter : v){
        cout<<iter<<" ";
    }

    return 0;
}