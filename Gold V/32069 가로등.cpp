#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
using ll = long long;
vector <ll> v;
ll L;
int N,K;
void bfs(){
    ll cnt = 0;
    queue<pair<ll,int>> q;
    set <ll> visit;
    for(int i=0;i<v.size();i++){
        q.push({v[i],0});
    }
    while(!q.empty()){
        ll now = q.front().first;
        ll cost = q.front().second;
        q.pop();
        if(cnt == K) break;
        if(now < 0 || now >= L+1) continue;
        if(visit.count(now)) continue;
        visit.insert(now);
        cnt++;
        cout<<cost<<"\n";
        q.push({now+1,cost+1});
        q.push({now-1,cost+1});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>L>>N>>K;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }

    bfs();
    return 0;
}