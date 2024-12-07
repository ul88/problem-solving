#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
struct consumer{
    int id;
    int w;
    int num;
};
bool com(consumer a, consumer b){
    if(a.w == b.w) return a.num > b.num;
    return a.w < b.w;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue <pii> pq; // w, 계산대 번호
    vector <pii> v;
    vector <consumer> ans;
    int N,k;
    cin>>N>>k;
    for(int i=0,id,w;i<N;i++){
        cin>>id>>w;
        v.push_back({id,w});
        if(i<k){
            pq.push({0,-i});
        }
    }

    for(int i=0;i<max(N,k);i++){
        int num = -pq.top().second;
        int cost = -pq.top().first + v[i].second;
        pq.push({-cost,-num});
        pq.pop();
        if(v.size() <= i) break;
        ans.push_back({v[i].first, cost, num});
    }

    sort(ans.begin(),ans.end(),com);

    ll sum = 0;

    for(int i=0;i<ans.size();i++){
        sum += (ll)(i+1)*(ll)ans[i].id;
    }

    cout<<sum;
    return 0;
}