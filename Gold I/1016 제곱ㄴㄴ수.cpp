#include<iostream>
#include<vector>
#include<set>
#define MAX 1000000
using namespace std;
typedef long long ll;
ll prime[MAX+1]={0,};
int main()
{
    ll min,max,ans=0;
    

    cin>>min>>max;
    
    for(ll i=2;i*i<=max;i++){
        ll n = min/(i*i);
        if(min%(i*i)) n++;
        for(ll j = n;j*i*i<=max;j++){
            prime[j*i*i-min]=1;
        }
    }

    for(int i=0;i<=max-min;i++){
        if(prime[i] == 0){
            cout<<i+min<<"\n";
            ans++;
        }
    }

    cout<<ans;
    return 0;
}