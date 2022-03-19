#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> v[4][3][3][3];
    unordered_map<string,int> m;
    int ans = 0;
    m["-"] = 0;
    m["cpp"] = m["backend"] = m["junior"] = m["chicken"] = 1;
    m["java"] = m["frontend"] = m["senior"] = m["pizza"] = 2;
    m["python"] = 3;
    for(auto a : info){
        string tmp, str1, str2, str3, str4, str5;
        int n;
        str1 = a.substr(0,a.find(" "));
        tmp = a.substr(str1.size() + 1, a.size() - str1.size() - 1);
        str2 = tmp.substr(0,tmp.find(" "));
        tmp = tmp.substr(str2.size() + 1, tmp.size() - str2.size() - 1);
        str3 = tmp.substr(0,tmp.find(" "));
        tmp = tmp.substr(str3.size() + 1, tmp.size() - str3.size() - 1);
        str4 = tmp.substr(0,tmp.find(" "));
        str5 = tmp.substr(str4.size() + 1, tmp.size() - str4.size() - 1);
        n = stoi(str5);
        v[m[str1]][m[str2]][m[str3]][m[str4]].push_back(n);
        v[m["-"]][m[str2]][m[str3]][m[str4]].push_back(n);
        v[m[str1]][m["-"]][m[str3]][m[str4]].push_back(n);
        v[m[str1]][m[str2]][m["-"]][m[str4]].push_back(n);
        v[m[str1]][m[str2]][m[str3]][m["-"]].push_back(n);
        v[m["-"]][m["-"]][m[str3]][m[str4]].push_back(n);
        v[m["-"]][m[str2]][m["-"]][m[str4]].push_back(n);
        v[m["-"]][m[str2]][m[str3]][m["-"]].push_back(n);
        v[m[str1]][m["-"]][m["-"]][m[str4]].push_back(n);
        v[m[str1]][m["-"]][m[str3]][m["-"]].push_back(n);
        v[m[str1]][m[str2]][m["-"]][m["-"]].push_back(n);
        v[m["-"]][m["-"]][m["-"]][m[str4]].push_back(n);
        v[m["-"]][m["-"]][m[str3]][m["-"]].push_back(n);
        v[m["-"]][m[str2]][m["-"]][m["-"]].push_back(n);
        v[m[str1]][m["-"]][m["-"]][m["-"]].push_back(n);
        v[m["-"]][m["-"]][m["-"]][m["-"]].push_back(n);
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                for(int l=0;l<3;l++)
                    sort(v[i][j][k][l].begin(),v[i][j][k][l].end());
    for(auto a : query){
        string tmp, str1, str2, str3, str4, str5;
        str1 = a.substr(0,a.find(" "));
        tmp = a.substr(str1.size() + 1, a.size() - str1.size() - 1);
        tmp = tmp.substr(tmp.find(" ") + 1, tmp.size() - tmp.find(" ") - 1);
        str2 = tmp.substr(0,tmp.find(" "));
        tmp = tmp.substr(str2.size() + 1, tmp.size() - str2.size() - 1);
        tmp = tmp.substr(tmp.find(" ") + 1, tmp.size() - tmp.find(" ") - 1);
        str3 = tmp.substr(0,tmp.find(" "));
        tmp = tmp.substr(str3.size() + 1, tmp.size() - str3.size() - 1);
        tmp = tmp.substr(tmp.find(" ") + 1, tmp.size() - tmp.find(" ") - 1);
        str4 = tmp.substr(0,tmp.find(" "));
        str5 = tmp.substr(str4.size() + 1, tmp.size() - str4.size() - 1);
        ans =  v[m[str1]][m[str2]][m[str3]][m[str4]].end() - lower_bound(v[m[str1]][m[str2]][m[str3]][m[str4]].begin(),v[m[str1]][m[str2]][m[str3]][m[str4]].end(),stoi(str5));
        answer.push_back(ans);
    }
    return answer;
}
