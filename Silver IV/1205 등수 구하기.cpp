#include<iostream>
#include<algorithm>
#define MAX 50
using namespace std;
typedef long long ll;
bool compare(int a,int b){
    return a>b;
}
int main()
{
    ll arr[MAX+1]={0,};
    int N,P;
    ll M;
    cin>>N>>M>>P;
    for(int i=0;i<=MAX;i++){
        arr[i]=-1;
    }
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N,compare);

    int ans = -1;
    while(arr[++ans] > M);
    if(ans>=P){
        cout<<-1;
    }else{
        bool flag = false;
        for(int i=ans;i<P;i++){
            if(arr[i] != M){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<ans+1;
        }else cout<<-1;
    }
    return 0;
}