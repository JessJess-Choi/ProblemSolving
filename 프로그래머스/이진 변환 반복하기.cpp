#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int trans = 0, cnt = 0;
    while(s != "1"){
        string str = "";
        for(auto a : s){
            if(a == '0')cnt++;
            else
                str += a;
        }
        int n = str.size();
        string tmp = "";
        while(n){
            tmp += to_string(n % 2);
            n /= 2;
        }
        reverse(tmp.begin(),tmp.end());
        s = tmp;
        trans++;
    }
    answer.push_back(trans);
    answer.push_back(cnt);
    return answer;
}
