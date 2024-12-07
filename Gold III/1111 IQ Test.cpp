#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N,isManyCase=0,ans=0;
    vector <int> v;

    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
    }

    if(N==1){
        cout<<"A";
    }else if(N==2){
        if(v[0] == v[1]){
            cout<<v[0];
        }else{
            cout<<"A";
        }
    }else{
        int m=0;
        for(int i=-200;i<=200;i++){
            if(isManyCase>1) break;
            
            bool flag = true;
            m = v[1] - v[0]*i;
            for(int j=2;j<N;j++){
                if(v[j] != v[j-1]*i+m){
                    flag = false;
                    break;
                }
            }
            if(flag){
                // cout<<"m: "<<m<<" v[1]: "<<v[1]<<" v[0]*i: "<<v[0]*i<<" i: "<<i<<"\n";
                if(isManyCase==0){
                    ans = v[v.size()-1]*i+m;
                    isManyCase++;
                }else{
                    if(ans != v[v.size()-1]*i+m){
                        isManyCase++;
                    } 
                }
            }
            
        }

        if(isManyCase == 1){
            cout<<ans;
        }else if(isManyCase == 0){
            cout<<"B";
        }else{
            cout<<"A";
        }
    }
    return 0;
}