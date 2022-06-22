#include <string>
#include <vector>

using namespace std;

int dp[101][101];
int g[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto a : puddles)g[a[0]][a[1]] = -1;
    dp[1][0] = 1;
    for(int i=1;i<101;i++)
        for(int j=1;j<101;j++)
            if(g[i][j] == -1)dp[i][j] = 0;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
    return dp[m][n];
}
