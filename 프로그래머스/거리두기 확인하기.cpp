#include <string>
#include <vector>

using namespace std;

bool f(vector<string> places){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(places[i][j] != 'P')continue;
            if(i > 0){
                if(places[i-1][j] == 'P')return false;
                if(i > 1 && places[i-1][j] != 'X' && places[i-2][j] == 'P')return false;
            }
            if(i < 4){
                if(places[i+1][j] == 'P')return false;
                if(i < 3 && places[i+1][j] != 'X' && places[i+2][j] == 'P')return false;
            }
            if(j > 0){
                if(places[i][j-1] == 'P')return false;
                if(j > 1 && places[i][j-1] != 'X' && places[i][j-2] == 'P')return false;
            }
            if(j < 4){
                if(places[i][j+1] == 'P')return false;
                if(i < 3 && places[i][j+1] != 'X' && places[i][j+2] == 'P')return false;
            }
            if(i < 4 && j < 4 && places[i+1][j+1] == 'P' && (places[i+1][j] != 'X' || places[i][j+1] != 'X'))return false;
            if(i < 4 && j > 0 && places[i+1][j-1] == 'P' && (places[i][j-1] != 'X' || places[i+1][j] != 'X'))return false;
            if(i > 0 && j < 4 && places[i-1][j+1] == 'P' && (places[i-1][j] != 'X' || places[i][j+1] != 'X'))return false;
            if(i > 0 && j > 0 && places[i-1][j-1] == 'P' && (places[i-1][j] != 'X' || places[i][j-1] != 'X'))return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto a : places)
        if(f(a))answer.push_back(1);
        else
            answer.push_back(0);
    return answer;
}
