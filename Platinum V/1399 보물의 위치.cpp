#include<iostream>
#include<vector>
using namespace std;
int dig(int n){
    if(n < 10) return n;
    int ret = 0;
    while(n!=0){
        ret += n%10;
        n/=10;
    }
    return dig(ret);
}

int gcd(int a, int b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int x = 0, y = 0;
        int K,M;
        vector<int> v;
        cin>>K>>M;

        v.push_back(1);
        bool flag = false;
        while(1){
            int t = dig(v.back()*M);
            if(v.back() == t){
                flag = true;
                break;
            }
            if(t == 1){
                break;
            }
            v.push_back(t);
        }

        if(v.size() >= K){
            for(int i=0;i<K;i++){
                if(i%4 == 0){
                    y+=v[i%v.size()];
                }else if(i%4==1){
                    x+=v[i%v.size()];
                }else if(i%4==2){
                    y-=v[i%v.size()];
                }else{
                    x-=v[i%v.size()];
                }
            }
            cout<<x<<" "<<y<<"\n";
        }
        else if(flag){
            for(int i=0;i<v.size()-1;i++){
                if(i%4 == 0){
                    y+=v[i%v.size()];
                }else if(i%4==1){
                    x+=v[i%v.size()];
                }else if(i%4==2){
                    y-=v[i%v.size()];
                }else{
                    x-=v[i%v.size()];
                }
            }
            int cnt = lcm(v.size(),4);
            
            for(int i=v.size()-1;i<cnt;i++){
                if(i%4 == 0){
                    y+=v.back();
                }else if(i%4==1){
                    x+=v.back();
                }else if(i%4==2){
                    y-=v.back();
                }else{
                    x-=v.back();
                }
            }

            int t = K-cnt;
            int rx = x, ry = y;

            for(int i=0;i<t%4;i++){
                if(i%4 == 0){
                    ry+=v.back();
                }else if(i%4==1){
                    rx+=v.back();
                }else if(i%4==2){
                    ry-=v.back();
                }else{
                    rx-=v.back();
                }
            }
            cout<<rx<<" "<<ry<<"\n";
        }
        else{
            int cnt = lcm(v.size(),4);
            for(int i=0;i<cnt;i++){
                if(i%4 == 0){
                    y+=v[i%v.size()];
                }else if(i%4==1){
                    x+=v[i%v.size()];
                }else if(i%4==2){
                    y-=v[i%v.size()];
                }else{
                    x-=v[i%v.size()];
                }
            }

            int rx = x*(K/cnt), ry = y*(K/cnt);

            for(int i=0;i<K%cnt;i++){
                if(i%4 == 0){
                    ry+=v[i%v.size()];
                }else if(i%4==1){
                    rx+=v[i%v.size()];
                }else if(i%4==2){
                    ry-=v[i%v.size()];
                }else{
                    rx-=v[i%v.size()];
                }
            }

            cout<<rx<<" "<<ry<<"\n";
        }
    }
    return 0;
}