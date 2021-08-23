#include<iostream>
#include<string>
using namespace std;
int dp[4001][4001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1,s2;cin>>s1>>s2;
    int ans = 0;
    s1 = " " + s1;
    s2 = " " + s2;
    for(int i=1;i<s1.size();i++)
        for(int j=1;j<s2.size();j++){
            if(s1[i] == s2[j])dp[i][j] = dp[i-1][j-1] + 1;
            ans = max(ans,dp[i][j]);
        }
    cout<<ans;
    return 0;
}
