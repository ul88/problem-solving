#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int W,H,N;
    vector<pair<int,int>> v;
    cin>>W>>H>>N;
    for(int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    int ans = 0;
    for(int i=1;i<N;i++){ // 대각선 위로 올라갈 수 있을 때 까지 올라가기
        if (v[i - 1].first <= v[i].first && v[i - 1].second <= v[i].second) {
            int diff = min(min(W - v[i - 1].first, H - v[i - 1].second), 
                            min(v[i].first - v[i - 1].first, v[i].second - v[i - 1].second)
                           );
            v[i - 1].first += diff;
            v[i - 1].second += diff;
            ans += diff;
        } else if (v[i - 1].first > v[i].first && v[i - 1].second > v[i].second) {
            int diff = min(v[i - 1].first - v[i].first, v[i - 1].second - v[i].second);
            v[i - 1].first -= diff;
            v[i - 1].second -= diff;
            ans += diff;
        }

        ans += abs(v[i-1].first - v[i].first) + abs(v[i-1].second - v[i].second);
    }

    cout<<ans;
    return 0;
}