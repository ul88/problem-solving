#include<iostream>
#include<cmath>
#define MAX 531441 // 3^12
using namespace std;
int ans[MAX+1]={};
void dfs(int start, int end){
    if(end - start == 1){
        ans[start] = 1;
        return;
    }else if(start - end == 1){
        ans[end] = 1;
        return;
    }
    int mid = (end - start)/3;
    dfs(start,start+mid);
    dfs(end-mid,end);
}
int main()
{
    int a;
    while(cin>>a){
        if(a==0) cout<<"-\n";
        else {
            dfs(0,pow(3,a));
            for(int i=0;i<pow(3,a);i++){
                if(ans[i]) cout<<"-";
                else cout<<" ";
                ans[i] = 0;
            }
            cout<<"\n";
        }
    }
    return 0;
}