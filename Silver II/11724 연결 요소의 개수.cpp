#include<iostream>
#include<vector>
#define MAX 1000
using namespace std;
vector<int> graph[MAX+1];
int visit[MAX+1];
void dfs(int n){
    if(visit[n]) return;
    visit[n] = 1;
    for(int i=0;i<graph[n].size();i++){
        dfs(graph[n][i]);
    }
}
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        if(visit[i]) continue;
        dfs(i);
        ans++;
    }

    cout<<ans;
    return 0;
}