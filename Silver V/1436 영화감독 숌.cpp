#include<iostream>
#include<vector>
using namespace std;
bool check(int n){
    int cnt = 0;
    bool flag = false;
    while(n!=0){
        if(n%10 == 6){
            if(flag == true){
                cnt++;
            }
            if(cnt>=2){
                return true;
            }
            flag = true;
        }else{
            cnt=0;
            flag = false;
        }
        n/=10;
    }
    return false;
}
int main()
{
    int N,ans=0;
    cin>>N;
    for(int i=666;i<=666*10000;i++){
        if(check(i)){
            N--;
            if(N==0){
                cout<<i;
                return 0;
            }    
        }
    }
    return 0;
}