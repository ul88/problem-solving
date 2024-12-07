#include<iostream>
#include<vector>
#include<cmath>
#define INF INT32_MAX
using namespace std;
typedef pair<int,int> pii;
int N;
vector<pii> v;
bool check(pii point1, pii point2){
for(int i=0;i<N;i++){
        if(point1.first <= v[i].first && point2.first >= v[i].first && point1.second == v[i].second) continue;
        if(point1.first <= v[i].first && point2.first >= v[i].first && point2.second == v[i].second) continue;
        if(point1.second <= v[i].second && v[i].second <= point2.second && point1.first == v[i].first) continue;
        if(point1.second <= v[i].second && v[i].second <= point2.second && point2.first == v[i].first) continue;
        return false;
    }
    return true;
}
int main()
{
    
    pii point1={INF,INF}, point2={-INF,-INF};
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        point1 = {min(point1.first,a),min(point1.second,b)};
        point2 = {max(point2.first,a),max(point2.second,b)};
    }

    //point1.first -> 왼쪽 아래 x 좌표, point1.second -> 왼쪽 아래 y 좌표
    //point2.first -> 오른쪽 위 x 좌표, point2.second -> 오른쪽 위 y 좌표

    if(point2.second - point1.second != point2.first - point1.first){
        int inc = abs((point2.second - point1.second) - (point2.first - point1.first));
        if(point2.second - point1.second > point2.first - point1.first){
            if(check(point1, {point2.first + inc, point2.second}) ||
                check({point1.first - inc, point1.second}, point2)){
                cout<<max(point2.second-point1.second, point2.first - point1.first);
                return 0;
            }
        }else{
            if(check(point1, {point2.first, point2.second + inc}) ||
                check({point1.first, point1.second - inc}, point2)){
                cout<<max(point2.second-point1.second, point2.first - point1.first);
                return 0;
            }
        }
    }
    else{
        if(check(point1,point2)){
            cout<<point2.second-point1.second;
            return 0;
        }
    }

    cout<<-1;    
    return 0;
}