#include<iostream>
#include<vector>
#include<queue>
#define MAX 10000
using namespace std;
typedef long long ll;
vector <pair<int,int> > graph[MAX+1];
void bfs(){
    int visit[MAX+1]={0,};
    ll ans=0;
    priority_queue <pair<int,int> > pq;
    pq.push({0,1});
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(!visit[now]) ans+=cost;
        visit[now]=1;
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int nCost = graph[now][i].second;
            if(visit[next]) continue;
            pq.push({-nCost,next});
        }
    }
    cout<<ans;
}
int main()
{
    int V,E;
    cin>>V>>E;
    for(int i=0,a,b,c;i<E;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    bfs();
    return 0;
}