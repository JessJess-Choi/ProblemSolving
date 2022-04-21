#include <string>
#include <vector>
#include <algorithm>
#define P pair<pair<pair<int,int>,int>,int>

using namespace std;

int solution(string dirs) {
    int x = 0, y = 0;
    vector<P> v;
    for(auto a : dirs){
        P tmp,tmp1;
        tmp.first.first.first = x;
        tmp.first.first.second = y;
        tmp1.first.second = x;
        tmp1.second = y;
        if(a == 'U' && y < 5)y++;
        else if(a == 'D' && y > -5)y--;
        else if(a == 'R' && x < 5)x++;
        else if(a == 'L' && x > -5)x--;
        else
            continue;
        tmp.first.second = x;
        tmp.second = y;
        tmp1.first.first.first = x;
        tmp1.first.first.second = y;
        if(find(v.begin(),v.end(),tmp) == v.end() && find(v.begin(),v.end(),tmp1) == v.end())
            v.push_back(tmp);
    }
    return (int)v.size();
}
