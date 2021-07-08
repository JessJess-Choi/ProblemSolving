#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size()-1;i++){
        int cnt = 0;
        for(int j=i+1;j<prices.size();j++){
            if(prices[i] > prices[j] || j == prices.size()-1){
                answer.push_back(cnt+1);
                break;
            }
            cnt++;
        }
    }
    answer.push_back(0);
    return answer;
}
