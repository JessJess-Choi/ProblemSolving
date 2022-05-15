#include <string>

using namespace std;

int solution(int n) {
    string str = "";
    int answer = 0;
    while(n){
        str += to_string(n%3);
        n /= 3;
    }
    for(auto a : str)answer = answer * 3 + a - '0';
    return answer;
}
