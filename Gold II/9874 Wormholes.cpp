#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 12
using namespace std;
vector <pair<int,int> > hole;
int connect[MAX+1]={0,};
int visit[MAX+1]={0,};
int N,ans=0;

bool com(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

bool isCheck(int n){    
    if(visit[n]) return 1; 
    visit[n]=1;
    for(int i=n+1;i<N;i++){
        if(hole[n].second == hole[i].second){
            return isCheck(connect[i]);
        }else{
            return 0;
        }
    }
    return 0;
}

void dfs(int n, int p){
    if(p==0){
        bool flag=false;
        for(int i=0;i<N;i++){
            for(int i=0;i<N;i++){
                visit[i]=0;
            }
            if(isCheck(i)){
                flag=true;
                break;
            }
            
        }
        if(flag == true){
            ans++;
        }
        return;
    }
    for(int i=n;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(connect[i] != -1 || connect[j] != -1) continue;
            connect[i]=j;
            connect[j]=i;
            dfs(i+1,p-1);
            connect[i]=-1;
            connect[j]=-1;
        }
    }
}

void checkPair(){
    for(int i=0;i<N/2;i++){
        for(int j=0;j<N;j++){
            for(int k=j+1;k<N;k++){
                if(connect[k]!=-1||connect[j]!=-1) continue;
                connect[k]=j;
                connect[j]=k;
                cout<<j<<" "<<k<<"\n";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;

    for(int i=0,a,b;i<N;i++){
        cin>>a>>b;
        hole.push_back({a,b});
        connect[i]=-1;
    }

    sort(hole.begin(),hole.end(),com);

    // dfs(0,N/2);

    checkPair();

    cout<<ans;
    return 0;
}