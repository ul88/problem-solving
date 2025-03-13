#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define MAX 250000
using namespace std;
using ll = long long;
vector<int> parentNode;
vector<int> visit;
vector<int> parent;
vector<int> graph[MAX+1];
int Find(int n){
    if(parent[n] == n) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int n,int m){
    n = Find(n);
    m = Find(m);
    if(n < m){
        parent[m] = n;
    }else if(n > m){
        parent[n] = m;
    }
}

void searchParent(int n){
    for(auto i : graph[n]){
        if(visit[i]) continue;
        visit[i] = 1;
        parentNode[i] = n;
        searchParent(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    parentNode.resize(N+1);
    parent.resize(N+1);
    visit.resize(N+1);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visit[1] = 1;
    searchParent(1);
    
    cout<<"parent node:\n";
    for(int i=1;i<=N;i++){
        cout<<i<<" "<<parentNode[i]<<"\n";
    }
    cout<<"_________________\n";

    int Q;
    cin>>Q;
    while(Q--){
        int n;
        cin>>n;
        for(int i=1;i<=N;i++) parent[i] = 0;
        cout<<n<<":\n";
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            parent[a] = a;
            if(a == 1) continue;
            if(parent[parentNode[a]] == 0){
                continue;
            }else{
                cout<<a<<", "<<parentNode[a]<<" Union\n";
                Union(a, parentNode[a]);
            }
        }

        map<int, ll> m;
        for(int i=1;i<=N;i++){
            if(Find(i) != 0){
                m[Find(i)]++;
            }
            cout<<Find(i)<<" ";
        }

        ll ans = 0;
        for(auto iter : m){
            ans += iter.second*(iter.second-1)/2;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}