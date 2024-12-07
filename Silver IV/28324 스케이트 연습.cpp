#include<iostream>
#define MAX 500000
using namespace std;
typedef long long ll;
int main()
{
    int arr[MAX+1]={0,};
    int N;
    ll ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int temp=1;
    ans++;
    for(int i=N-2;i>=0;i--){
        if(temp<arr[i]){
            ans+=++temp;
        }else{
            temp=arr[i];
            ans+=temp;
        }
    }
    cout<<ans;
    return 0;
}