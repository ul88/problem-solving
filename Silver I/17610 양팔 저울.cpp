#include<iostream>
#include<vector>
#define MAX 200000
using namespace std;
vector <int> v;
int visit[MAX*14]={0,};
int S=0,ans=0;
void dfs(int n,int weight){
    if(weight>=0) visit[weight] = 1;
    if(n<0) return;
    dfs(n-1,weight);
    dfs(n-1,weight+v[n]);
    dfs(n-1,weight-v[n]);
}

int main()
{
    int k;
    cin>>k;

    for(int i=0,a;i<k;i++){
        cin>>a;
        S += a;
        v.push_back(a);
    }

    dfs(k-1,0);

    for(int i=1;i<=S;i++){
        if(!visit[i]) ans++;
    }

    cout<<ans;

    return 0;
}