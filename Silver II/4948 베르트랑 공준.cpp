#include<iostream>
#define MAX 123456
using namespace std;
int arr[MAX*2+1]={0,};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    for(int i=2;i<=MAX*2;i++){
        bool flag=false;
        for(int j=2;j*j<=i;j++){
            if(i%j==0) {
                flag=true;
                break;
            }
        }
        if(!flag){
            arr[i]=1;
        }
    }
    int N;
    cin>>N;
    while(N!=0){
        int cnt=0;
        for(int i=N+1;i<=2*N;i++){
            if(arr[i]==1) {
                cnt++;
            }
        }
        cout<<cnt<<"\n";
        cin>>N;
    }
    return 0;
}