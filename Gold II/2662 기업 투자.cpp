#include<iostream>
#include<algorithm>
#define MAX 300
using namespace std;
int ans = 0;
int N,M;
int main()
{
    int arr[MAX+1][21] = {0,};
    int dp[MAX+1][21] = {0,};
    int answer[21]={0,};
    int ans[MAX+1][21] = {0,};
    cin>>N>>M;
    for(int i=0,a;i<N;i++){
        cin>>a;
        for(int j=1,b;j<=M;j++){
            cin>>b;
            arr[a][j] = b;
        }
    }
    for(int i=1;i<=M;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=N;k++){
                if(j+k > N) continue;
                if(dp[j+k][i] < dp[j][i-1] + arr[k][i]){
                    dp[j+k][i] = dp[j][i-1] + arr[k][i];
                    ans[j+k][i] = k;
                }
            
            }
        }
    }

    cout<<dp[N][M]<<"\n";
    int temp = N;
    for(int i=M;i>0;i--){
        answer[i] = ans[temp][i];
        temp -= ans[temp][i];
    }
    for(int i=1;i<=M;i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}