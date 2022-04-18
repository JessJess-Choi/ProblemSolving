#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        int r = i / n;
        int c = i % n;
        answer.push_back(r > c ? r + 1 : c + 1);
    }
    return answer;
}
