#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0xFFFFFFF
using namespace std;
void solution(int (*ptr_dp)[501],int K,int * ptr_psum){
    //dp[n][m] = min(dp[n][m],dp[n][k]+dp[k+1][m]+sum[m+1]-sum[n]);
    for(int i=0;i<K;i++){
        for(int j=0;j<K-i;j++){
            for(int k=j;k<i+j;k++){
                ptr_dp[j][i+j] = min(ptr_dp[j][i+j],ptr_dp[j][k]+ptr_dp[k+1][i+j]+ptr_psum[i+j+1]-ptr_psum[j]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int dp[501][501]={0,},psum[501]={0,};
    int T,K;
    cin>>T;
    while(T--){
        cin>>K;
        for(int i=0,a;i<K;i++){
            cin>>a;
            psum[i+1]=psum[i]+a;
            for(int j=0;j<K;j++){
                if(i!=j) dp[i][j]=INF;
            }
        }
        solution(dp,K,psum);
        cout<<dp[0][K-1]<<"\n";
    }
    return 0;
}