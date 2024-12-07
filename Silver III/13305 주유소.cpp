#include<iostream>
#include<vector>
#define MAX 100000
#define INF INT64_MAX
using namespace std;
typedef long long ll;
int main()
{
    vector <int> city(MAX+1, 0),gas(MAX+1, 0);
    ll ans = 0;
    int N;
    cin>>N;
    for(int i=0,a;i<N-1;i++){
        cin>>city[i];
    }
    for(int i=0,a;i<N;i++){
        cin>>gas[i];
    }

    ll minGas = gas[0];
    for(int i=1;i<N;i++){
        ans+=minGas*city[i-1];
        if(minGas > gas[i]){
            minGas = gas[i];
        }
    }

    cout<<ans;
    return 0;
}