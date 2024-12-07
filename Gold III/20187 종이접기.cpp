#include<iostream>
#include<vector>
#define MAX 10
using namespace std;

vector <char> v;
int ans[1<<MAX + 1][1<<MAX + 1]={0,};
int k,h;

int width[] = {2, 3, 0, 1};
int heigth[] = {1, 0, 3, 2};
void dfs(int idx, int y1, int x1, int y2, int x2){
    if(idx == k*2){
        ans[y1][x1] = h;
        return;
    }
    else if(v[idx] == 'D'){
        dfs(idx+1, (y1+y2)/2+1, x1, y2, x2);
        
        for(int i=y1;i<=(y1+y2)/2;i++){
            for(int j=x1;j<=x2;j++){
                ans[i][j] = width[ans[(y1+y2)-i][j]];
            }
        }
    }
    else if(v[idx] == 'U'){
        dfs(idx+1, y1, x1, (y1+y2)/2, x2);

        for(int i=(y1+y2)/2+1;i<=y2;i++){
            for(int j=x1;j<=x2;j++){
                ans[i][j] = width[ans[(y1+y2)-i][j]];
            }
        }
    }
    else if(v[idx] == 'R'){
        dfs(idx+1, y1, (x1+x2)/2+1, y2, x2);

        for(int i=y1;i<=y2;i++){
            for(int j=x1;j<=(x1+x2)/2;j++){
                ans[i][j] = heigth[ans[i][(x1+x2)-j]];
            }
        }
    }
    else{
        dfs(idx+1, y1, x1, y2, (x1+x2)/2);
        for(int i=y1;i<=y2;i++){
            for(int j=(x1+x2)/2+1;j<=x2;j++){
                ans[i][j] = heigth[ans[i][(x1+x2)-j]];
            }
        }
    }
}

int main()
{
    cin>>k;
    for(int i=0;i<k*2;i++){
        char a;
        cin>>a;
        v.push_back(a);
    }

    cin>>h;

    dfs(0,1,1,1<<k,1<<k);

    for(int i=1;i<=(1<<k);i++){
        for(int j=1;j<=(1<<k);j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}