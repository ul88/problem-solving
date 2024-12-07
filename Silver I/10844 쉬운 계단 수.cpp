#include<iostream>
#define MOD 1000000000
using namespace std;
typedef long long ll;
int main()
{
    ll dp[10]={0,},copyDp[10]={0,};
    int N;
    ll ans=0;
    cin>>N;

    for(int i=1;i<10;i++){
        copyDp[i]=1;
    }
    
    for(int i=2;i<=N;i++){
        for(int j=0;j<10;j++){
            if(j==0){
                dp[j] = copyDp[j+1]%MOD;
            }else if(j==9){
                dp[j] = copyDp[j-1]%MOD;
            }else{
                dp[j] = (copyDp[j+1] + copyDp[j-1])%MOD;
            }
        }
        for(int j=0;j<10;j++){
            copyDp[j] = dp[j]%MOD;
        }
    }

    for(int i=0;i<10;i++){
        ans=(ans+copyDp[i])%MOD;
    }
    cout<<ans;
    return 0;
}