#include<iostream>
#include<vector>
#include<queue>
#define MAX 1000
using namespace std;
vector<int> v[MAX+1];
int degree[MAX+1]={0,};
int N,M;
int visit[MAX+1]={0,};
void topologicalSort(){
    priority_queue <pair<int,int> > pq;
    queue <int> ans;
    for(int i=1;i<=N;i++){
        if(degree[i] == 0){
            pq.push({0,i});
        }
    }
    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop();
        degree[now]--;
        if(degree[now]<=0){
            ans.push(now);
            for(int i=0;i<v[now].size();i++){
                int next = v[now][i];
                pq.push({-degree[next],next});
            }
        }
    }
    
    if(ans.empty() || ans.size() != N){
        cout<<0;
    }else{
        while(!ans.empty()){
            cout<<ans.front()<<"\n";
            ans.pop();
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0,a;i<M;i++){
        cin>>a;
        int temp = 0;
        for(int j=0,b;j<a;j++){
            cin>>b;
            if(j!=0){
                v[temp].push_back(b);
                degree[b]++;
            }
            temp = b;
        }
    }

    topologicalSort();

    return 0;
}