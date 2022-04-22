#include<vector>

using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
            dp[i][j] = board[i][j];
    for(int i=1;i<board.size();i++)
        for(int j=1;j<board[0].size();j++)
            if(board[i][j]){
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
                answer = max(dp[i][j],answer);
            }
    return answer * answer;
}
