#include<iostream>
#include<string>
#include<algorithm>
#define MAX 1000
#define INF INT32_MAX
using namespace std;
int main()
{
    int N;
    string str;
    cin>>N;
    cin>>str;
    int ans=0;
    int dp[MAX+1] = {0,};
    for(int i=0;i<N;i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int i=0;i<str.length();i++){
        if(dp[i] == INF) continue;
        if(str[i] == 'B'){
            for(int j=i+1;j<str.length();j++){
                if(str[j] == 'O'){
                    dp[j] = min(dp[j],dp[i] + (j-i)*(j-i));
                }
            }
        }
        else if(str[i] == 'O'){
            for(int j=i+1;j<str.length();j++){
                if(str[j] == 'J'){
                    dp[j] = min(dp[j],dp[i] + (j-i)*(j-i));
                }
            }
        }else{
            for(int j=i+1;j<str.length();j++){
                if(str[j] == 'B'){
                    dp[j] = min(dp[j],dp[i] + (j-i)*(j-i));
                }
            }
        }
    }

    if(dp[N-1] == INF) cout<<-1;
    else cout<<dp[N-1];
    return 0;
}