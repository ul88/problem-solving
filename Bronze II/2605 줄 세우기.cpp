#include<iostream>
#define MAX 100
using namespace std;
int main()
{
    int N,arr[MAX+1]={0,};
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        if(a==0){
            arr[i] = i+1;
        }else{
            for(int j=i;j>=i-a;j--){
                arr[j] = arr[j-1];
            }
            arr[i-a] = i+1;
        }
    }

    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}