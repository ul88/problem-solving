#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define MAX 100000
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
vector <p> x;
vector <p> y;
vector <p> z;
vector < pair<int,p> > planet;
int parent[MAX+1]={0,};
int Find(int n){
    if(parent[n] == n) return n;
    else{
        return parent[n] = Find(parent[n]);
    }
}
void Union(int n,int m){
    n = Find(n);
    m = Find(m);
    if(n!=m) parent[n]=m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int N;
    ll ans = 0;
    cin>>N;
    for(int i=0,a,b,c;i<N;i++){
        cin>>a>>b>>c;
        x.push_back({a,i});
        y.push_back({b,i});
        z.push_back({c,i});
        parent[i]=i;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i=0;i<N-1;i++){
        planet.push_back({abs(x[i+1].first-x[i].first),{x[i+1].second,x[i].second}});
        planet.push_back({abs(y[i+1].first-y[i].first),{y[i+1].second,y[i].second}});
        planet.push_back({abs(z[i+1].first-z[i].first),{z[i+1].second,z[i].second}});
    }

    sort(planet.begin(), planet.end());

    for(int i=0;i<planet.size();i++){
        if(Find(planet[i].second.first) != Find(planet[i].second.second)){
            Union(planet[i].second.first,planet[i].second.second);
            ans += planet[i].first;
        }
    }

    cout<<ans;
    return 0;
}