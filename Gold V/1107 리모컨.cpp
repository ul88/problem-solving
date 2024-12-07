#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#define INF INT32_MAX
using namespace std;
vector<int> v;
int ans = INF;   
int N;
void dfs(int ret, int len, int n){
    if(len > n+1) return;
    if(len >= n-1){
        ans = min(ans, (int)abs(N-ret) + (int)len);
    }
        
    for(int i=0;i<v.size();i++){
        dfs(ret*10 + v[i], len+1, n);
    }
}
int main()
{
    int M;
    cin>>N>>M;
    v.reserve(10);
    for(int i=0;i<10;i++) v.push_back(i);
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        v.erase(find(v.begin(), v.end() , a));
    }

    ans = min(ans, (int)abs(N-100));

    for(int i=0;i<v.size();i++){    
        dfs(v[i], 1, to_string(N).length());
    }
    cout<<ans;
    return 0;
}