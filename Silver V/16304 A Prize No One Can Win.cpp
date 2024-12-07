#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int N,x,ans;
    cin>>N>>x;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    ans = N;
    for(int i=N-1;i>0;i--){
        if(v[i] + v[i-1] > x){
            ans--;
        }
    }
    cout<<ans;
    return 0;
}