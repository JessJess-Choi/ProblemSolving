#include <string>
#include <vector>
#include <set>

using namespace std;

bool check(vector<string> board){
    for(int i=0;i<board.size()-1;i++)
        for(int j=0;j<board[i].size()-1;j++)
            if(board[i][j] != '0' && board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j+1])
                return true;
    return false;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(check(board)){
        set<pair<int,int>> s;
        for(int i=0;i<board.size()-1;i++){
            for(int j=0;j<board[i].size()-1;j++){
                if(board[i][j] == '0')continue;
                if(board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j+1]){
                    s.insert({i,j});
                }
            }
        }
        for(auto a : s){
            board[a.first][a.second] = '0';
            board[a.first+1][a.second] = '0';
            board[a.first][a.second+1] = '0';
            board[a.first+1][a.second+1] = '0';
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == '0'){
                    for(int k=i;k>0;k--)board[k][j] = board[k-1][j];
                    board[0][j] = '0';
                }
            }
        }
    }
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[i].size();j++)
            if(board[i][j] == '0')answer++;
    return answer;
}
