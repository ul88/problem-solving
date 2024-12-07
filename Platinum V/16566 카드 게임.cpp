#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 4000000
using namespace std;
int parent[MAX+1]={0,};
int Find(int n){
    if(parent[n]==n) return n;
    else{
        return parent[n] = Find(parent[n]);
    }
}
void Union(int x,int y){
    if(x!=y) parent[x] = y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int N,M,K;
    vector <int> v;
    cin>>N>>M>>K;
    for(int i=0;i<M;i++) parent[i+1]=i+1;
    for(int i=0,a;i<M;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0,a;i<K;i++){
        cin>>a;
        int idx = upper_bound(v.begin(),v.end(),a)-v.begin();
        idx = Find(idx);

        cout<<v[idx]<<"\n";
        Union(Find(idx),Find(idx+1));
    }
    return 0;
}