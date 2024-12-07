//가장 기본 로직은 생각해냈지만 트리와 그래프의 차이 / 최대값+두번째 큰 값 또 고려해야한다는 것을 생각하지 못함
#include<iostream>
#include<vector>
#include<queue>
#define MAX 200000
using namespace std;
vector <int> graph[MAX+1];
vector <int> tree[MAX+1];
int visit[MAX+1]={0,};
int N,k,dist[MAX+1]={0,},ans=0;
void makeTree(int n){ // 1이 루트인 트리라는 보장이 없기 때문에 양방향 그래프로 받아야함
    for(int i=0;i<graph[n].size();i++){
        if(visit[graph[n][i]]) continue;
        visit[graph[n][i]]=1;
        tree[n].push_back(graph[n][i]);
        makeTree(graph[n][i]);
    }
}
void dfs(int n){
    priority_queue <int> pq;
    for(int i=0;i<tree[n].size();i++){
        dfs(tree[n][i]);
        dist[n] = max(dist[n],dist[tree[n][i]]+1);
        pq.push(dist[tree[n][i]]+1);
    }
    int cnt=0;
    if(pq.size() > 1 ){
        cnt=pq.top();
        pq.pop();
    }
    if(pq.size()>=1 && cnt+pq.top() >= k){
        ans++;
        dist[n]=-1;
    }
}
int main()
{
    cin>>N>>k;
    for(int i=0,a,b;i<N-1;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visit[1]=1;
    makeTree(1);

    dfs(1);

    cout<<ans;
    return 0;
}