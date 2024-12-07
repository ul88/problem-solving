#include<iostream>
#include<string>
#include<queue>
#define MAX 50
using namespace std;
using pii = pair<int,int>;
int N;
string str[MAX+1];
int bfs(int n){
    int visit[MAX+1]={0,};
    queue<pii> q;
    int cnt = 0;
    q.push({n,0});
    visit[n] = 1;
    while(!q.empty()){
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(depth > 1) continue;
        for(int i=0;i<N;i++){
            if(str[now][i] == 'Y' && visit[i] == 0){
                visit[i] = 1;
                cnt++;
                q.push({i,depth+1});
            }
        }
    }
    return cnt;
}
int main()
{
    int ans = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str[i];
    }

    for(int i=0;i<N;i++){
        ans = max(ans,bfs(i));
    }
    cout<<ans;
    return 0;
}