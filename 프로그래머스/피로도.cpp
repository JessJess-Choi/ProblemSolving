#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(),dungeons.end());
    do{
        int tmp = k, cnt = 0;
        for(int i=0;i<dungeons.size();i++){
            if(dungeons[i][0] > tmp)break;
            else{
                tmp -= dungeons[i][1];
                cnt++;
            }
        }
        answer = max(answer,cnt);
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    return answer;
}
