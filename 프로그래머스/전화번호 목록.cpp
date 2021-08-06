#include <string>
#include <vector>
#include<map>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string,int> m;
    for(string str : phone_book)
        m[str] = 1;
    for(string str : phone_book){
        string tmp = "";
        for(char ch : str){
            tmp += ch;
            if(tmp.compare(str) && (m.find(tmp) != m.end()))return false;
        }
    }
    return true;
}
