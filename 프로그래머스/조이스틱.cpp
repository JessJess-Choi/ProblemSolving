#include <string>

using namespace std;

int solution(string name) {
    int answer = 0, move = name.size() - 1;
    for(int i=0;i<name.size();i++){
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        int now = i + 1;
        while(now < name.size() && name[now] == 'A')now++;
        move = min(move,min(i * 2 + (int)name.size() - now, ((int)name.size() - now) * 2 + i));
    }
    return answer + move;
}
