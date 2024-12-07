#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
using pii = pair<int,int>;

bool compare(pii a, pii b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    int N;
    int d[4]={1,4,2,3};
    vector <pair<pii,pii> > v;
    vector <pii> temp;
    map <pii,int> m;
    int ans = 0;
    cin>>N;
    for(int i=0,a,b,c,d;i<N/2;i++){
        cin>>a>>b>>c>>d;
        v.push_back({{a,b},{c,d}});
        temp.push_back({a,b});
        temp.push_back({c,d});
    }

    sort(temp.begin(),temp.end(),compare);

    int idx = 0;
    for(int i=0;i<4;i++){
        if(d[i] == 1 || d[i] == 4){
            for(int j=0;j<temp.size();j++){
                if(temp[j].first == d[i]){
                    m.insert({temp[j],++idx});
                }
            }
        }else{
            for(int j=temp.size();j>=0;j--){
                if(temp[j].first == d[i]){
                    m.insert({temp[j],++idx});
                }
            }
        }
    }    

    int cross=0;
    // vector<int> cross(v.size(),0);
    for(int i=0;i<v.size();i++){
        int cnt = 0;
        for(int j=0;j<v.size();j++){
            if(i==j) continue;
            pii a = {m[v[i].first],m[v[i].second]};
            pii b = {m[v[j].first],m[v[j].second]};

            if(a.first > a.second){
                int temp = a.first;
                a.first = a.second;
                a.second = temp;
            }
            if(b.first > b.second){
                int temp = b.first;
                b.first = b.second;
                b.second = temp;
            }
            if(a.first > b.first){
                pii temp = a;
                a = b;
                b = temp;
            }
        
            if(a.first < b.first && a.second < b.second && b.first < a.second){
                cnt++;
                ans++;
            }
        }
        cross = max(cross,cnt);
    }


    cout<<ans/2<<"\n";
    cout<<cross;
    return 0;
}