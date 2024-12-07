#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10000
using namespace std;
typedef pair<int,pair<int,int> > p;
int parent[MAX+1]={0,};
int Find(int n){
    if(parent[n]==n) return n;
    return parent[n]=Find(parent[n]);
}
void Union(int n,int m){
    n=Find(n);
    m=Find(m);
    if(n!=m) parent[m]=n;
}
int main()
{
    vector <p> graph;
    int V,E,ans=0;
    cin>>V>>E;
    for(int i=0,a,b,c;i<E;i++){
        cin>>a>>b>>c;
        graph.push_back({c,{a,b}});
    }
    
    for(int i=0;i<V;i++) parent[i+1]=i+1;

    sort(graph.begin(),graph.end());

    for(int i=0;i<E;i++){
        if(Find(graph[i].second.first)!=Find(graph[i].second.second)){
            Union(graph[i].second.first,graph[i].second.second);
            ans+=graph[i].first;
        }
    }
    cout<<ans;
    return 0;
}