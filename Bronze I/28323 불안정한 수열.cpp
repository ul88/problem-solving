#include<iostream>
#include<algorithm>
#define MAX 300000
using namespace std;
int main()
{
    int N,ans=1;
    int arr[MAX+1]={0,};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int temp=arr[N-1];
    for(int i=N-2;i>=0;i--){
        if(temp%2 != arr[i]%2){
            temp=arr[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}