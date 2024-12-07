#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000
using namespace std;
struct frog{
    int idx;
    int x1;
    int x2;
};

int N,Q;
int parent[MAX+1]={0,};
vector <frog> v;

bool com(frog a, frog b){
    if(a.x1 == b.x1) return a.x2<b.x2;
    return a.x1 < b.x1;
}

int Find(int n){
    if(parent[n] == n) return n;
    else return parent[n] = Find(parent[n]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x==y) return;

    if(x<y){
        parent[y] = x;
    }else{
        parent[x] = y;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        int x1,x2,y;
        cin>>x1>>x2>>y;
        v.push_back({i,x1,x2});
        parent[i]=i;
    }

    sort(v.begin(),v.end(),com);

    int now = 0;
    for(int i=1;i<N;i++){
        if(v[now].x2 >= v[i].x1){
            Union(v[now].idx, v[i].idx);

            v[now].x2 = max(v[now].x2,v[i].x2);
            v[i].x2 = max(v[now].x2,v[i].x2);
            v[now].x1 = min(v[now].x1,v[i].x1);
            v[i].x1 = min(v[now].x1,v[i].x1);
        }else{
            now = i;
        }
    }

    for(int i=0,a,b;i<Q;i++){
        cin>>a>>b;
        cout<<(Find(a-1) == Find(b-1))<<"\n";
    }
    return 0;
}