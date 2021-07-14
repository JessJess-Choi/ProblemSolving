#include <string>
#include <vector>
#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    int answer = 0;
    for(int i=0;i<moves.size();i++){
        int index = moves[i]-1;
        for(int j=0;j<board.size();j++){
            if(board[j][index]){
                if(!s.empty() && s.top()==board[j][index]){
                    s.pop();
                    answer+=2;
                }
                else
                    s.push(board[j][index]);
                board[j][index] = 0;
                break;
            }
        }
    }
    return answer;
}
