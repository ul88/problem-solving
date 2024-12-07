#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define MAX 100
using namespace std;
int main()
{
    map <int,int> m;
    priority_queue <int> pq;
    vector <pair<int,int> > v;
    int dp[MAX+1][MAX+1]={0,};
    int N,ans=0;
    cin>>N;
    for(int i=0,a,b;i<N;i++){
        cin>>a>>b;
        if(a<b) v.push_back({a,b});
        else v.push_back({b,a});
        pq.push(-a);
        pq.push(-b);
    }

    int idx = 0;
    while(!pq.empty()){
        int now = -pq.top();
        pq.pop();
        m.insert({now,idx++});
    }

    for(int i=0;i<N;i++){
        dp[m[v[i].first]][m[v[i].second]] = 1;
    }

    for(int i=0;i<N;i++){
        int cnt = 0;
        vector<pair<int,int>> temp;
        temp.push_back({m[v[i].first], m[v[i].second]});
        for(int j=m[v[i].first];j<=m[v[i].second];j++){
            for(int k=m[v[i].first];k<=m[v[i].second];k++){
                if(j==k) continue;
                if(dp[j][k] == 1){
                    temp.push_back({j,k});
                    cnt++;
                }
            }
        }
        for(int j=m[v[i].second];j<idx;j++){
            for(int k=m[v[i].second];k<idx;k++){
                if(j==k) continue;
                if(dp[j][k] == 1){
                    temp.push_back({j,k});
                    cnt++;
                }
            }
        }

        for(int j=0;j<temp.size();j++){
            for(int k=j+1;k<temp.size();k++){
                if(temp[j].first <= temp[k].first && temp[j].second >= temp[k].first
                && temp[j].second <= temp[k].second && temp[k].second < idx){
                    cnt--;
                }
            }
        }

        ans = max(ans,cnt);
    }

    cout<<ans;
    return 0;
}