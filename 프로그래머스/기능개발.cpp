#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> count;
    vector<int> answer;
    int sum = 0;
    for(int i=0;i<progresses.size();i++){
        count.push_back((100 - progresses[i]) / speeds[i]);
        if((100 - progresses[i]) % speeds[i])count[i]++;
    }
    for(int i=0;i<count.size();i++){
        int tmp = i;
        while(count[tmp] >= count[i+1] && i<count.size()-1)i++;
        if(answer.size() == 0){
            answer.push_back(i+1);
            sum += i+1;
        }
        else{
            answer.push_back(i-sum+1);
            sum += i-sum+1;
        }
    }
    return answer;
}
