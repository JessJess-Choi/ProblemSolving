#include<iostream>
#include<string>
using namespace std;
int dp[5001][5001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;cin>>n;
    string s1,s2;cin>>s1;
    for(int i=s1.size()-1;i>=0;i--)s2 += s1[i];
    s1 = " " + s1;
    s2 = " " + s2;
    for(int i=1;i<s1.size();i++)
        for(int j=1;j<s2.size();j++)
            if(s1[i] == s2[j])dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    cout<<s1.size() - dp[s1.size()-1][s2.size()-1] - 1;
    return 0;
}
