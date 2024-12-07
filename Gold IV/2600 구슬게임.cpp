#include<iostream>
#include<vector>
using namespace std;
using pii = pair<int,int>;
vector<int> b(3,0);
void dfs(char AB,int k1,int k2){ // AB == true -> A, AB == false -> B
    cout<<k1<<" "<<k2<<"\n";
    if(k1 == 0 && k2 == 0){
        cout<<AB<<"\n";
        return;
    }
    if(AB == 'A'){
        for(int i=0;i<3;i++){
            if(k1-b[i] < 0) return;
            if(k1-b[i] == 0){
                int temp = k1-b[i];
                k1 = k2;
                k2 = temp;
            }

            bool flag = false;
            for(int j=0;j<3;j++){
                if(k1-b[j] == 0) flag = true;
            }

            if(!flag) dfs('B',k1-b[i],k2);
        }
    }else{
        for(int i=0;i<3;i++){
            if(k1-b[i] < 0) return;
            if(k1-b[i] == 0){
                int temp = k1-b[i];
                k1 = k2;
                k2 = temp;
            }

            bool flag = false;
            for(int j=0;j<3;j++){
                if(k1-b[j] == 0) flag = true;
            }
            if(!flag) dfs('A',k1-b[i],k2);
        }
    }
}
int main()
{
    cin>>b[0]>>b[1]>>b[2];
    for(int i=0,k1,k2;i<5;i++){
        cin>>k1>>k2;
        dfs('A',k1,k2);
    }

    return 0;
}