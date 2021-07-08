#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int dp[2][1000001];

int solution(vector<int> money) {
    int answer = 0;
    dp[0][0] = money[0];
    dp[0][1] = max(money[0],money[1]);
    dp[1][1] = money[1];
    dp[1][2] = max(money[1],money[2]);
    for(int i=2;i<money.size()-1;i++)dp[0][i] = max(dp[0][i-1],dp[0][i-2]+money[i]);
    for(int i=3;i<money.size();i++)dp[1][i] = max(dp[1][i-1],dp[1][i-2]+money[i]);
    for(int i=0;i<money.size();i++)answer = max(max(dp[0][i],dp[1][i]),answer);
    return answer;
}
