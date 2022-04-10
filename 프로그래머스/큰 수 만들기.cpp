#include <string>

using namespace std;

string solution(string number, int k) {
    int now = -1;
    string ret = "";
    for(int i=0;i<number.size()-k;i++){
        char ch = -1;
        for(int j=now+1;j<=i+k;j++){
            if(ch < number[j]){
                now = j;
                ch = number[j];
            }
            if(ch == '9')break;
        }
        ret += ch;
    }
    return ret;
}
