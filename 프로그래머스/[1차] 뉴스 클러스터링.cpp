#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0, tmp1 = 0, tmp2 = 0;
    map<string,int> m,m1,m2;
    for(auto &a : str1)
        if(a >= 'A' && a <= 'Z')a += 'a' - 'A';
    for(auto &a : str2)
        if(a >= 'A' && a <= 'Z')a += 'a' - 'A';
    for(int i=0;i<str1.size()-1;i++)
        if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z'){
            m1[str1.substr(i,2)]++;
            m[str1.substr(i,2)]++;
        }
    for(int i=0;i<str2.size()-1;i++)
        if(str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z'){
            m2[str2.substr(i,2)]++;
            m[str2.substr(i,2)]++;
        }
    for(auto a : m)tmp1++;
    if(tmp1 == 0)return 65536;
    for(auto a : m1)
        while(m2[a.first] && m1[a.first]){
            m1[a.first]--;
            m2[a.first]--;
            tmp2++;
        }
    tmp1 = tmp2;
    for(auto a : m1)tmp1 += a.second;
    for(auto a : m2)tmp1 += a.second;
    return tmp2 * 65536 / tmp1;
}
