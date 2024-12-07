#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 25
using namespace std;
using pii = pair<int,int>;
vector <string> v;
vector <int> ans;
int visit[MAX+1][MAX+1] = {0, };
pii dxy[] ={{-1,0} , {1,0} , {0,1}, {0,-1}};
int N;
int dfs(int n,int m){
    if(n>=N || m>=N || n<0 || m<0) return -1;
    if(v[n][m] == '0') return -1;
    if(visit[n][m]) return -1;
    visit[n][m] = 1;
    int cnt = 0;
    for(int i=0;i<4;i++){
        cnt += dfs(n+dxy[i].first,m+dxy[i].second)+1;
    }
    return cnt;
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j]) continue;
            if(v[i][j] == '1'){
                ans.push_back(dfs(i,j)+1);
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(auto iter : ans){
        cout<<iter<<"\n";
    }
    return 0;
}