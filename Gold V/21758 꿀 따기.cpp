//누적합 O
#include<iostream>
#include<algorithm>
#define MAX 100000
using namespace std;
int main()
{
    int arr[MAX+1]={0,}, preSum[MAX+1]={0,},ans=0;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(i==0){
            preSum[i] = arr[i];
        }
        else{
            preSum[i] = preSum[i-1]+arr[i];
        }
    }

    for(int i=1;i<N-1;i++){
        ans = max(ans, preSum[N-1] - arr[0] + preSum[N-1] - preSum[i] - arr[i]);
        ans = max(ans, preSum[N-1] - arr[N-1] - arr[i] + preSum[i-1]);
        ans = max(ans, preSum[i] - arr[0] + preSum[N-1] - preSum[i-1] - arr[N-1]);
    }

    cout<<ans;
    
    return 0;
}
//누적합 X
// #include<iostream>
// #include<algorithm>
// #define MAX 100000
// using namespace std;
// int main()
// {
//     int arr[MAX+1]={0,}, ans=0;
//     int N,sum=0,temp=0;
//     scanf("%d",&N);
//     for(int i=0;i<N;i++){
//         scanf("%d",&arr[i]);
//         sum+=arr[i];
//     }

//     // 벌 벌 꿀
//     temp = sum - arr[0];
//     for(int i=1;i<N-1;i++){
//         temp -= arr[i];
//         ans = max(ans,sum-arr[0] - arr[i] + temp);
//     }
//     //꿀 벌 벌
//     temp = sum;
//     temp -= arr[N-1];
//     for(int i=N-2;i>0;i--){
//         temp -= arr[i];
//         ans = max(ans,sum-arr[i]+temp-arr[N-1]);
//     }

//     //벌 꿀 벌
//     temp = sum;
//     temp -= (arr[0] + arr[N-1]);
//     for(int i=1;i<N-1;i++){
//         ans = max(ans,temp+arr[i]);
//     }

//     printf("%d",ans);
    
//     return 0;
// }