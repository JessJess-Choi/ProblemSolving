#include <string>

using namespace std;

bool solution(string s)
{
    int a = 0, b = 0;
    for(auto n : s)
        if(n == 'p' || n == 'P')a++;
        else if(n == 'y' || n == 'Y')b++;
    return a == b;
}
