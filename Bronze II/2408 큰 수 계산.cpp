#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class lll{
public:
    lll() : num {} {}
    lll(string str){
        for(auto iter = str.crbegin();iter!=str.crend();iter++){
            num.push_back(*iter-'0');
        }
    }
    vector<int> get_num() { return num; };
    void set_num(vector<int> v) { num = v; };
    lll operator+(lll& operand);
    lll operator-(lll& operand);
    lll operator*(lll& operand);
    lll operator/(lll& operand);

    void print(){
        for(auto iter = num.crbegin();iter != num.crend();iter++){
            cout<<*iter;
        }
    }
private:
    vector<int> num;
};

lll lll::operator+(lll& operand){
    lll res;
    vector<int> temp = operand.get_num();
    if(num.size() < temp.size()){
        swap(num,temp);
    }
    for(int i=0;i<num.size();i++){
        if(i < temp.size()) num[i] += temp[i];
        if(num[i] >= 10){
            if(i == num.size()-1){
                num.push_back(1);
            }else{
                num[i+1]++;
            }
        }
        num[i] %= 10;
    }
    
    res.set_num(num);
    return res;
}

lll lll::operator-(lll& operand){    
    lll res;
    vector<int> temp = operand.get_num();

    res.set_num(num);
    return res;
}

lll lll::operator*(lll& operand){
    lll res;
    vector<int> temp = operand.get_num();
    
    res.set_num(num);
    return res;
}

lll lll::operator/(lll& operand){
    lll res;
    vector<int> temp = operand.get_num();

    res.set_num(num);
    return res;
}

int main()
{
    lll ans("0");
    int N;
    string op;
    cin>>N;
    for(int i=0;i<2*N-1;i++){
        string str;
        cin>>str;
        lll a(str);

        if(i == 0){
            ans = ans + a;    
        }
        else if(i%2 == 1){
            op = str;
        }else{
            switch(op[0]){
            case '+':
                ans = ans + a;
                break;
            case '-':
                ans = ans - a;
                break;
            case '*':
                ans = ans * a;
                break;
            case '/':
                ans = ans / a;
                break;
            }
        }
    }
    return 0;
}