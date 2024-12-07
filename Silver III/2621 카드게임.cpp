#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v[5];
    int number[10]={0,};
    int ans = 0;
    for(int i=0;i<5;i++){
        char a;
        int b;
        cin>>a>>b;
        if(a=='R'){
            v[0].push_back(b);
        }
        else if(a=='B'){
            v[1].push_back(b);
        }
        else if(a=='Y'){
            v[2].push_back(b);
        }
        else{
            v[3].push_back(b);
        }
        v[4].push_back(b);
        number[b]++;
    }

    for(int i=0;i<5;i++){
        sort(v[i].begin(),v[i].end());
    }

    //1: 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때, 점수는 가장 높은 숫자에 900을 더한다.
    for(int i=0;i<4;i++){
        if(v[i].size() == 5){
            bool flag = true;
            for(int j=1;j<5;j++){
                if(v[i][j] - v[i][j-1] != 1){
                    flag = false;
                    break;
                }
            }
            if(flag) ans = max(ans,v[i].back()+900);
        }
    }

    //2: 카드 5장 중 4장의 숫자가 같을 때 점수는 같은 숫자에 800을 더한다. 
    for(int i=1;i<10;i++){
        if(number[i] == 4){
            ans = max(ans,i+800);
        }
    }

    //3: 카드 5장 중 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 점수는 3장이 같은 숫자에 10을 곱하고 2장이 같은 숫자를 더한 다음 700을 더한다.
    int three = 0;
    int two = 0;
    for(int i=1;i<10;i++){
        if(number[i] == 3) three = i;
        if(number[i] == 2) two = i;
    }
    if(three != 0 && two != 0){
        ans = max(ans,three*10+two+700);
    }

    //4: 5장의 카드 색깔이 모두 같을 때 점수는 가장 높은 숫자에 600을 더한다.
    for(int i=0;i<4;i++){
        if(v[i].size() == 5){
            ans = max(ans,v[i].back()+600);
            break;
        }
    }

    //5: 카드 5장의 숫자가 연속적일 때 점수는 가장 높은 숫자에 500을 더한다.
    bool flag = true;
    for(int i=1;i<5;i++){
        if(v[4][i]-v[4][i-1] != 1){
            flag = false;
            break;
        }
    }
    if(flag) ans = max(ans,v[4].back()+500);

    //6: 카드 5장 중 3장의 숫자가 같을 때 점수는 같은 숫자에 400을 더한다.
    for(int i=1;i<10;i++){
        if(number[i] == 3){
            ans = max(ans,i+400);
        }
    }

    //7: 카드 5장 중 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 점수는 같은 숫자 중 큰 숫자에 10을 곱하고 같은 숫자 중 작은 숫자를 더한 다음 300을 더한다.
    two = 0;
    for(int i=1;i<10;i++){
        if(number[i] == 2){
            if(two == 0){
                two = i;
            }else{
                ans = max(ans,i*10+two+300);
            }
        }
    }

    //8: 카드 5장 중 2장의 숫자가 같을 때 점수는 같은 숫자에 200을 더한다. 
    for(int i=1;i<10;i++){
        if(number[i] == 2){
            ans = max(ans,i+200);
        }
    }

    //9: 위의 어떤 경우에도 해당하지 않을 때 점수는 가장 큰 숫자에 100을 더한다.
    ans = max(ans,v[4].back()+100);

    cout<<ans;

    return 0;
}