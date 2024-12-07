#include<iostream>
#include<algorithm>
#include<string>
#define INF INT32_MAX
using namespace std;
int N,ans=INF;
string str;
int check(bool dir,char color){
    int cnt=0;
    bool flag=false;
    if(dir){
        for(int i=N-1;i>=0;i--){
            if(str[i]==color){
                if(flag){
                    cnt++;
                } 
            }else{
                flag=true;
            }
        }
    }else{
        for(int i=0;i<N;i++){
            if(str[i]==color){
                if(flag){
                    cnt++;
                } 
            }else{
                flag=true;
            }
        }
    }
    return cnt;
}
int main()
{
    
    cin>>N;
    cin>>str;
    ans=min(ans,check(0,'R'));
    ans=min(ans,check(0,'B'));
    ans=min(ans,check(1,'R'));
    ans=min(ans,check(1,'B'));
    cout<<ans;
    return 0;
}