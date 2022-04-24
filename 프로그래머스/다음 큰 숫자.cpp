#include <string>
#include <algorithm>

using namespace std;

string f(int n){
    string str = "";
    while(n){
        str += to_string(n%2);
        n /= 2;
    }
    reverse(str.begin(),str.end());
    return str;
}

int solution(int n) {
    int answer = 0;
    string str = f(n);
    if(str.find("0") == string::npos){
        str = "10" + str.substr(1,str.size()-1);
    }
    else{
        int n1 = 0;
        for(auto a : str)
            if(a == '1')n1++;
        while(true){
            int n2 = 0;
            string tmp = f(++n);
            for(auto a : tmp)
                if(a == '1')n2++;
            if(n1 == n2){
                str = tmp;
                break;
            }
        }
    }
    for(auto a : str)answer = answer * 2 + a - '0';
    return answer;
}
