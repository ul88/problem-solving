#include<iostream>
#define MAX 1000
#define INF INT32_MAX
using namespace std;
struct RGB{
    int red;
    int green;
    int blue;
};
int main()
{
    RGB rgb[MAX+1]={};
    RGB dp[MAX+1]={};
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>rgb[i].red>>rgb[i].green>>rgb[i].blue;
        dp[i] = {INF, INF, INF};
        if(i == 0) dp[i] = rgb[i];
    }

    for(int i=1;i<N;i++){
        dp[i] = {rgb[i].red + min(dp[i-1].blue, dp[i-1].green),
                rgb[i].green + min(dp[i-1].red, dp[i-1].blue),
                rgb[i].blue + min(dp[i-1].red, dp[i-1].green)};
    }

    cout<<min(dp[N-1].red, min(dp[N-1].green, dp[N-1].blue));
}