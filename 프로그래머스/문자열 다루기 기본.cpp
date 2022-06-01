#include <string>

using namespace std;

bool solution(string s) {
    if(s.size() != 4 && s.size() != 6)return false;
    for(auto a : s)
        if(a < '0' || a > '9')return false;
    return true;
}
