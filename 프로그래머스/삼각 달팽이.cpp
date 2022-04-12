#include <string>
#include <vector>

using namespace std;

int v[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    int r = -1, c = 0, now = 1;
    for(int i=n;i>0;i-=3){
        for(int j=0;j<i;j++)v[++r][c] = now++;
        for(int j=0;j<i-1;j++)v[r][++c] = now++;
        for(int j=0;j<i-2;j++)v[--r][--c] = now++;
    }
    for(int i=0;i<1001;i++){
        if(v[i][0] == 0)break;
        for(int j=0;j<1001;j++){
            if(v[i][j] == 0)break;
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}
