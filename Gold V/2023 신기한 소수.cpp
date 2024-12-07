#include<iostream>  
#define MAX 100000000  
using namespace std; 
int arr[6] = {1, 2, 3, 5, 7, 9};
void dfs(int n,int digit){  
    if(n>=MAX) return;  
    if(digit<0) return;  
    bool flag = true;  
    for(int i=2;i*i<=n;i++){  
        if(n%i==0){  
            flag = false;  
            break;  
        }  
    }  
    if(!flag) return;  
    else{  
        if(digit == 0){  
            cout<<n<<"\n";  
        }  
    }  
    for(int i=0;i<6;i++){  
        if(n==0 && i==0 || i==9) continue;   
        dfs(n*10+arr[i],digit-1);  
    }  
  
}  
int main()  
{  
    int N;
    cin>>N;  
    dfs(0,N);  
    return 0;  
}  