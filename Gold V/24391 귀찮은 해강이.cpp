#include<iostream>
#include<vector>
#define MAX 100000
using namespace std;
vector<int> parent(MAX+1);
int find(int n){
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin>>N>>M;

    for(int i=1;i<=N;i++) parent[i] = i;

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        if(find(a) != find(b)) Union(a,b);
    }

    int ans = 0;
    int prev = -1;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(i != 0){
            if(find(prev) != find(a)) ans++;
        }
        prev = a;
    }
    cout<<ans;
    return 0;
}