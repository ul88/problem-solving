#include<iostream>
using namespace std;
int main()
{
    int N,ans=0;
    cin>>N;

    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            int k = N-(i+j);
            if(j>k) continue;
            if(i+j>k && j+k>i && i+k>j){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}