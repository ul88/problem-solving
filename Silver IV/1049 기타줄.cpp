#include<iostream>
#include<vector>
#include<algorithm>
#define INF INT32_MAX
using namespace std;
int main()
{
    vector <pair<int,int> > v;
    int N,M,ans=INF, m = INF;
    cin>>N>>M;
    for(int i=0,a,b;i<M;i++){
        cin>>a>>b;
        v.push_back({a,b});
        m = min(m,b);
        ans = min(ans,b*N);
    }

    for(int i=0;i<M;i++){
        int temp = N/6 + (N%6 == 0);
        for(int j=1;j<=temp+1;j++){
            if(6*j < N){
                ans = min(ans, v[i].first*j + (N-(6*j))*m);
            }else{
                ans = min(ans, v[i].first*j);
            }
        }
    }

    cout<<ans;
    return 0;
}