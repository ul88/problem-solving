#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

bool com(pi fir, pi sec){
    if(fir.second == sec.second){
        return fir.first < sec.first;
    }
    return fir.second < sec.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <int> A,B;
    vector <pi> v;
    priority_queue <pi> pq;
    int N;
    ll ans=0;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        A.push_back(a);
    }
    for(int i=0,a;i<N;i++){
        cin>>a;
        B.push_back(a);
        v.push_back({A[i],a});
    }
    sort(v.begin(),v.end(),com);
    
    int prevMax = v[0].second;
    int curMax = -1;

    for(int i=0;i<N;i++){
        if(prevMax > v[i].first){
            if(prevMax < v[i].second) prevMax = v[i].second;

            int cnt = ((prevMax - v[i].first)+29)/30;
            v[i].first += (cnt*30);

            ans+=cnt;

        }

        curMax = max(curMax,v[i].first);

        if((i+1) < N && v[i].second != v[i+1].second){
            prevMax=curMax;
        }
    }

    cout<<ans;

    return 0;
}