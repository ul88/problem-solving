#include<iostream>
using namespace std;
int main()
{
    int N,K,ans=0;
    int arr[2][3]={0,};
    cin>>N>>K;
    for(int i=0,a,b;i<N;i++){
        scanf("%d %d",&a,&b);
        if(b>=1 && b<=2){
            arr[0][0]++;
        }else if(b>=3 && b<=4){
            arr[a][1]++;
        }else{
            arr[a][2]++;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=i;j<3;j++){
            if(arr[i][j]%K!=0){
                ans++;
            }
            ans+=arr[i][j]/K;
        }
    }
    cout<<ans;
    return 0;
}

