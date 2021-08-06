#include <string>
#include <vector>
#include<algorithm>
#define ll long long

using namespace std;

ll f(ll a,ll b,char c){
    if(c == '+')return a+b;
    else if(c == '-')return a-b;
    else if(c == '*')return a*b;
}

long long solution(string expression) {
    ll answer = 0;
    string str = "";
    vector<char> Operator = {'+','-','*'};
    vector<ll> v;
    vector<char> op;
    for(int i=0;i<expression.size();i++){
         if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
             v.push_back(stoi(str));
             str = "";
             op.push_back(expression[i]);
         }
        else
            str += expression[i];
    }
    v.push_back(stoi(str));
    do{
        vector<ll> tmp1 = v;
        vector<char> tmp2 = op;
        for(int i=0;i<3;i++){
            for(int j=0;j<tmp2.size();j++){
                if(tmp2[j] == Operator[i]){
                    tmp1[j] = f(tmp1[j],tmp1[j+1],Operator[i]);
                    tmp1.erase(tmp1.begin()+j+1);
                    tmp2.erase(tmp2.begin()+j);
                    j--;
                }
            }
        }
        answer = max(answer,abs(tmp1[0]));
    }while(next_permutation(Operator.begin(),Operator.end()));
    return answer;
}
