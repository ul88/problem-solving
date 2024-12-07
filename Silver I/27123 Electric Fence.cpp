#include<iostream>
using namespace std;
int main()
{
    int n,m,p,cnt=0;
    cin>>n>>m>>p;

    if(p==n){
        for(int i=1;i<n;i++){
            if(m*i % n == 0) cnt-=1;
            cnt += m*i/n;
        }
    }
    else if(p>n){
        for(int i=1;i<=n;i++){
            if(m*i % n == 0) cnt-=1;
            cnt += m*i/n;
        }
        for(int i=1;i<p-n;i++){
            if( (m*i) % (p-n) == 0) cnt-=1;
            cnt += (m*i)/(p-n);
        }
    }else{
        for(int i=1;i<=p;i++){
            if(m*i % n == 0) cnt-=1;
            cnt += m*i/n;
        }
        for(int i=p+1;i<n;i++){
            if(m*i % n == 0) cnt-=1;
            cnt+= m*i/n;
        }
        n-=p;
        for(int i=1;i<n;i++){
            cnt -= m*i/n;
        }
    }

    cout<<cnt;
    return 0;
}