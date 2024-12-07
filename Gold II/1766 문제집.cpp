#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 32000
using namespace std;
typedef pair<int,int> pi;
int main()
{
    vector <int> graph[MAX+1];
    priority_queue <int> pq;
    bool visit[MAX+1]={0,};
    int degree[MAX+1]={0,};
    int N,M;
    cin>>N>>M;
    for(int i=0,a,b;i<M;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        degree[b]++;
    }

    for(int i=1;i<=N;i++){
        if(!degree[i]){
            pq.push(-i);
        }
    }

    while(!pq.empty()){
        int now = -pq.top();
        pq.pop();
        if(visit[now]) continue;
        if(degree[now]==0){
            cout<<now<<" ";
        }
        visit[now]=true;
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];
            degree[next]--;
            if(degree[next]==0){
                pq.push(-next);
            }
        }
    }

    return 0;
}