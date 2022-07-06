#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define ll long long
#define MAX 1000000000

using namespace std;

stack<ll> st;

bool pop(){
    if(st.empty())return true;
    st.pop();
    return false;
}

bool INV(){
    if(st.empty())return true;
    ll n = -st.top(); st.pop();
    st.push(n);
    return false;
}

bool DUP(){
    if(st.empty())return true;
    st.push(st.top());
    return false;
}

bool SWP(){
    if(st.empty())return true;
    ll n1 = st.top(); st.pop();
    if(st.empty())return true;
    ll n2 = st.top(); st.pop();
    st.push(n1);
    st.push(n2);
    return false;
}

bool ADD(){
    if(st.empty())return true;
    ll n1 = st.top(); st.pop();
    if(st.empty())return true;
    ll n2 = st.top(); st.pop();
    st.push(n1 + n2);
    return false;
}

bool SUB(){
    if(st.empty())return true;
    ll n1 = st.top(); st.pop();
    if(st.empty())return true;
    ll n2 = st.top(); st.pop();
    st.push(n2 - n1);
    return false;
}

bool MUL(){
    if(st.empty())return true;
    ll n1 = st.top(); st.pop();
    if(st.empty())return true;
    ll n2 = st.top(); st.pop();
    st.push(n1 * n2);
    return false;
}

bool DIV(){
    if(st.empty())return true;
    ll n1 = st.top(); st.pop();
    if(st.empty())return true;
    ll n2 = st.top(); st.pop();
    if(n1 == 0)return true;
    if(n1 < 0 || n2 < 0){
        if(n1 < 0 && n2 < 0)st.push(abs(n2) / abs(n1));
        else
            st.push(-(abs(n2) / abs(n1)));
    }
    else
        st.push(abs(n2) / abs(n1));
    return false;
}

bool MOD(){
    if(st.empty())return true;
    ll n1 = st.top(); st.pop();
    if(st.empty())return true;
    ll n2 = st.top(); st.pop();
    if(n1 == 0)return true;
    if(n2 < 0)st.push(-(abs(n2) % abs(n1)));
    else
        st.push(abs(n2) % abs(n1));
    return false;
}

bool NUM(ll n){
    st.push(n);
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true){
        vector<string> vs;
        int N;
        while(true){
            string str; cin >> str;
            if(str == "END")break;
            if(str == "QUIT")return 0;
            if(str == "NUM"){
                ll n; cin >> n;
                str = str + " " + to_string(n);
            }
            vs.push_back(str);
        }
        cin >> N;
        while(N--){
            ll n; cin >> n;
            st.push(n);
            bool error = false;
            for(string str : vs){
                if(str == "POP")error = pop();
                else if(str == "INV")error = INV();
                else if(str == "DUP")error = DUP();
                else if(str == "SWP")error = SWP();
                else if(str == "ADD")error = ADD();
                else if(str == "SUB")error = SUB();
                else if(str == "MUL")error = MUL();
                else if(str == "DIV")error = DIV();
                else if(str == "MOD")error = MOD();
                else if(str.substr(0,3) == "NUM")error = NUM(stoll(str.substr(str.find(" ") + 1, str.size() - str.find(" ") - 1)));
                
                if(!st.empty() && (st.top() > MAX || st.top() < -MAX))
                    error = true;
                if(error)break;
            }
            if(error || st.size() != 1)cout<<"ERROR\n";
            else
                cout<<st.top()<<"\n";
            while(!st.empty())st.pop();
        }
        cout<<"\n";
    }
    return 0;
}
