#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    ll cnt[2]={0,},ans[2]={0,};
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        cnt[a%2]++;
        ans[a%2]+=cnt[a%2?0:1];
    }
    cout<<min(ans[0],ans[1]);
    return 0;
}