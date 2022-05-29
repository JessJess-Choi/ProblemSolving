#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int indx;

bool compare(string a, string b){
    if(a[indx] != b[indx])
        return a[indx] < b[indx];
    return a < b;
}

vector<string> solution(vector<string> strings, int n) {
    indx = n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}
