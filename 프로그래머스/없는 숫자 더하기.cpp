#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(auto a : numbers)answer -= a;
    return answer;
}
