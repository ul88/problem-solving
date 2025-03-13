#include<iostream>
#include<vector>
#define MAX 100000
using namespace std;
vector<int> cage(MAX+1);
vector<int> v[MAX+1];
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int M;
        cin>>M;
        for(int j=0;j<M;j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }

    bool flag = 1;
    while(flag){
        flag = 0;
        for(int i=1;i<=N;i++){
            int cnt = 0;
            for(int j=0;j<v[i].size();j++){
                if(cage[i] == cage[v[i][j]]) cnt++;
            }
            if(cnt>=2) 
            {
                cage[i] = !cage[i];
                flag = 1;
            }
        }
    }

    int ans1=0,ans2=0;
    for(int i=1;i<=N;i++){
        if(cage[i] == 0) ans1++;
        else ans2++;
    }

    cout<<ans1<<" ";
    for(int i=1;i<=N;i++) if(cage[i]==0) cout<<i<<" ";
    cout<<"\n"<<ans2<<" ";
    for(int i=1;i<=N;i++) if(cage[i]==1) cout<<i<<" ";
    return 0;
}