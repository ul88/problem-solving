#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int ans = 0;
void dfs(int n, int N){
    if(n > N) return;
    ans = max(ans,n);
    for(int i=0;i<v.size();i++){
        if(n == 0) dfs(v[i],N);
        else dfs(n*10+v[i],N);
    }
}
int main()
{
    int N,K;
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    dfs(0, N);
    cout<<ans;

    return 0;
}