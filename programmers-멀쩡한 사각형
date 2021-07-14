#define ll long long
using namespace std;

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

long long solution(int w,int h) {
    return (ll)w*(ll)h-((ll)w+(ll)h-gcd((ll)w,(ll)h));
}
