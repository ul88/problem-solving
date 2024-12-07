#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 5000
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
int main()
{
    int N,K,ans = 0;
    vector<pair<int,int>> v;
    priority_queue <pair<int,int> > pq;
    cin>>N>>K;
    for(int i=0,a;i<N;i++){
        cin>>a;
        pq.push({a,i});
    }

    for(int i=0;i<K;i++){
        pair<int,int> now = pq.top();
        pq.pop();
        v.push_back(now);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<K;i++){
        ans += v[i].first-i;
    }

    cout<<ans;
    return 0;
}