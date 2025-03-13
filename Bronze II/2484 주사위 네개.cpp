#include<iostream>
using namespace std;
int main()
{
    int N;
    int ans = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        int arr[7] = {0,};
        for(int j=0;j<4;j++){
            int a;
            cin>>a;
            arr[a]++;
        }
        int maxIdx = 0;
        int sum = 0;
        for(int j=1;j<=6;j++){
            if(arr[j] == 4) {
                sum = 50000+j*5000;
                break;
            }
            else if(arr[j] == 3){
                sum = 10000+j*1000;
                break;
            }
            else if(arr[j] == 2) {
                if(sum != 0) {
                    sum -= 1000;
                    sum *= 5;
                    sum = sum + 500*j + 2000;
                }
                else sum = 1000 + 100*j;
            }else if(arr[j] == 1){
                maxIdx = j;
            }
        }

        if(sum == 0) sum = maxIdx*100;
        
        ans = max(ans, sum);
    }
    cout<<ans;
    return 0;
}