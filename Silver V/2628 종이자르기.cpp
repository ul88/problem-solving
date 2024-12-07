#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100
using namespace std;
typedef struct st{
    int len;
    int arr[MAX+1];
}st;
int main()
{
    int N,M,k;
    cin>>N>>M>>k;
    st w={0,{}},h={0,{}};
    for(int i=0,a,b;i<k;i++){
        cin>>a>>b;
        if(a == 0){
            w.arr[w.len++] = b;
        }else{
            h.arr[h.len++] = b;
        }
    }

    sort(w.arr,w.arr+w.len);
    sort(h.arr, h.arr+h.len);
    
    int temp = 0;
    int ans = 0,ans1=0;
    for(int i=0;i<=w.len;i++){
        if(i==w.len){
            ans = max(ans, M-temp);
        }
        else{
            ans = max(ans, w.arr[i]-temp);
            temp = w.arr[i];
        }
    }
    if(ans == 0) ans = M;
    temp = 0;
    for(int i=0;i<=h.len;i++){
        if(i==h.len){
            ans1 = max(ans1,N-temp);
        }else{
            ans1 = max(ans1,h.arr[i]-temp);
            temp = h.arr[i];
        }
    }
    if(ans1 == 0) ans = N;

    cout<<ans*ans1;
    return 0;
}