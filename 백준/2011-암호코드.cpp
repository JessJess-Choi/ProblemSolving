#include<iostream>
#include<string>
using namespace std;
int dp[5001],tmp;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;cin>>str;
    if(str.size() == 1 && str[0] == '0'){
        cout<<0;
        return 0;
    }
    dp[0] = 1;
    for(int i=1;i<=str.size();i++){
        if(str[i-1]>='1' && str[i-1]<='9')dp[i] = dp[i-1];
        if(i==1)continue;
        tmp = stoi(str.substr(i-2,2));
        if(tmp>=10 && tmp<=26)dp[i] = (dp[i-2] + dp[i]) % 1000000;
    }
    cout<<dp[str.size()];
    return 0;
}
