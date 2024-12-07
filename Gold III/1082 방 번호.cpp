#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
bool com(pii a, pii b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pii> v;
    vector<pii> temp;
    int ans[10] = {0,};
    int N,M;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back({a,i});
    }
    cin>>M;

    int m;
    temp = v;
    sort(v.begin(),v.end(),com);

    if(v[0].second == 0){
        m = M-v[1].first;
        ans[v[0].second] += m/v[0].first;
        m %= v[0].first;

        m -= v[0].first;
        m += v[1].first;
        ans[v[0].second]++;
        
    }else{
        m = M%v[0].first;
        ans[v[0].second] += M/v[0].first;
    }
    
    for(int i=N-1;i>0;i--){
        if(v[0].first >= temp[i].first) continue;
        if(temp[i].second <= v[0].second) continue;
        int dec = m / (temp[i].first - v[0].first);
        ans[temp[i].second] += min(dec,ans[v[0].second]);
        ans[v[0].second] -= dec;
        
        if(ans[v[0].second] <= 0) break;

        m %= (temp[i].first - v[0].first);
    }

    bool flag = false;
    for(int i=9;i>0;i--){
        if(ans[i] > 0) flag = true;
    }
    
    if(!flag){
        cout<<0;
        return 0;
    }

    for(int i=9;i>=0;i--){
        for(int j=0;j<ans[i];j++) cout<<i;
    }
    return 0;
}