#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 1000
#define INF INT32_MAX
using namespace std;
vector<pair<int,int> > graph[MAX+1];
int dist[MAX+1]={0,};
int degree[MAX+1]={0,};
int parent[MAX+1]={0,};
void topological(int n){
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto iter : graph[now]){
            degree[iter.first]--;
            if(dist[iter.first] < dist[now] + iter.second){
                dist[iter.first] = dist[now] + iter.second;
                parent[iter.first] = now;
            }
            if(iter.first == 1) continue;
            
            if(!degree[iter.first]) q.push(iter.first);
        }
    }
}

void find(int n){
    if(parent[n] == 1) return;
    find(parent[n]);
    cout<<parent[n]<<" ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0,a,b,c;i<M;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        degree[b]++;
    }

    topological(1);

    cout<<dist[1]<<"\n";
    cout<<"1 ";
    find(1);
    cout<<"1";

    return 0;
}