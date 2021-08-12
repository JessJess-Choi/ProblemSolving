#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto a : numbers){
        if(a%2 == 0)answer.push_back(a+1);
        else{
            long long tmp = 1;
            while(true){
                if((a&tmp) == 0)break;
                tmp *= 2;
            }
            tmp /= 2;
            answer.push_back(a + tmp);
        }
    }
    return answer;
}
