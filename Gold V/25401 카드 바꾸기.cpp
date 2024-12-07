#include<iostream>
#include<vector>
#include<cmath>
#define MAX 500
#define XMAX 1000000
#define INF INT32_MAX
using namespace std;
using ll = long long;
int arr[MAX+1]={0,},sub[MAX+1]={0,};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,ans=INF;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int sub = (arr[j] - arr[i])/(j-i);
            int cnt=0;
            int a = arr[i] - sub*(i+1);
            for(int k=0;k<N;k++){
                a+=sub;
                if(a != arr[k]) cnt++;
            }

            ans = min(ans,cnt);
        }
    }

    cout<<ans;
    return 0;
}