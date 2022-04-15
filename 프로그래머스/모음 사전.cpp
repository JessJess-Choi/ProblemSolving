#include <string>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0, total = 0;
    for(int i=1;i<=5;i++)
        total += pow(5,i);
    for(int i=0;i<word.size();i++)
        if(word[i] == 'A')answer += 1;
        else if(word[i] == 'E')answer += total / pow(5,i + 1) * 1 + 1;
        else if(word[i] == 'I')answer += total / pow(5, i + 1) * 2 + 1;
        else if(word[i] == 'O')answer += total / pow(5, i + 1) * 3 + 1;
        else if(word[i] == 'U')answer += total / pow(5, i + 1) * 4 + 1;
    return answer;
}
