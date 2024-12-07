#include<iostream>
using namespace std;
int main()
{
    int N;
    int arr[10]={0,};
    int number[11][10]={{0,1,1,1,1,1,1,1,1,1},
                        {9,20,20,20,20,20,20,20,20,20}};
    cin>>N;

    for(int i=1;i<=N;i++){
        int n = i;
        while(n != 0){
            arr[n%10]++;
            n/=10;
        }
    }

    for(int i=0;i<=9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}