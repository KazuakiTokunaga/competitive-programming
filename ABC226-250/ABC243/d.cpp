#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N, X;
    cin >> N >> X;

    string S;
    cin >> S;

    string S_trimmed = "";
    vector<char> stack;
    
    rep(i, 0, N){
        if (S[i] == 'U'){
            if (!stack.empty()) stack.pop_back();
            else S_trimmed += S[i];
        } else {
            stack.push_back(S[i]);
        }
    }
    for (char c: stack) S_trimmed += c;

    ll cur = X;
    rep(i, 0, S_trimmed.size()){
        if (S_trimmed[i] == 'U') cur /= 2;
        if (S_trimmed[i] == 'R') cur = cur * 2 + 1;
        if (S_trimmed[i] == 'L') cur = cur * 2;
    }
    cout << cur << endl;
}