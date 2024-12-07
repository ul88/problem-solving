#include<iostream>
#include<vector>
#define MAX 250000
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(MAX+1);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    int temp = 1;
    int ans = 0;
    for(int i=0;i<N;i++){
        if(temp == v[i]) temp++;
        else ans++;
    }

    if(temp == N-ans+1) cout<<ans;
    else cout<<N;
    return 0;
}