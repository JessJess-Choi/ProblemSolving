#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto a : commands){
        vector<int> tmp;
        tmp.resize(a[1] - a[0] + 1);
        copy(array.begin() + a[0] - 1,array.begin() + a[1],tmp.begin());
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[a[2] - 1]);
    }
    return answer;
}
