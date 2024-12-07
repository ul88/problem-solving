#include<iostream>
#include<algorithm>
#define MAX 2000
using namespace std;
int arr[MAX+1][MAX+1]={0,}, store[MAX+1][MAX+1]={0,};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M,ans=0;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.length();j++){
            arr[i][j] = str[j]-'0';
        }
    }

    for(int j=0;j<M;j++){
        for(int i=0;i<N;i++){
            int temp = 0;
            if(j!=0){
                for(int k=-1;k<=1;k++){
                    if(i+k < 0 || i+k >= N) continue;
                    temp = max(temp, store[i+k][j-1]);
                }
            }
            
            store[i][j] = temp + arr[i][j];
            ans = max(ans, temp);
        }
    }

    cout<<ans;
    return 0;
}