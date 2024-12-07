#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
#define INF INT32_MAX
using namespace std;
int ans = INF;
int dist[MAX+1]={0,},visit[MAX+1]={0,};
int dfs(int n,vector <pair<int,int> > tree[]){
    
}
int main()
{
    int T;
    int N,M;
    cin>>T;
    while(T--){
        vector <pair<int,int> > tree[MAX+1];
        cin>>N>>M;
        for(int i=0;i<N;i++) dist[i] = INF;
        for(int i=0,a,b,c;i<M;i++){
            cin>>a>>b>>c;
            tree[a].push_back({b,c});
            tree[b].push_back({a,c});
        }

        dfs(1,tree);

        cout<<dist[1];
    }
    return 0;
}