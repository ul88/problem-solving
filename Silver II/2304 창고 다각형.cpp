#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define MAX 1000
using namespace std;
using pii = pair<int,int>;
vector<pii> v;
int up(int start, int end){
    int ret = 0;
    
    int maxHeight = v[start].second;
    for(int i=start+1;i<=end;i++){
        ret += (v[i].first - v[i-1].first)*maxHeight;
        maxHeight = max(maxHeight, v[i].second);
    }

    return ret;
}

int down(int start, int end){
    int ret = 0;
    
    int maxHeight = v[start].second;
    for(int i=start-1;i>=end;i--){
        ret += (v[i+1].first - v[i].first)*maxHeight;
        maxHeight = max(maxHeight, v[i].second);
    }

    return ret;
}
int main()
{
    int N;
    int maxIdx = 0;
    cin>>N;
    v.reserve(N);
    for(int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());
    for(int i=0;i<N;i++){
        if(v[i].second > v[maxIdx].second) maxIdx = i;
    }
    cout<<up(0, maxIdx) + down(v.size()-1, maxIdx) + v[maxIdx].second;

    return 0;
}