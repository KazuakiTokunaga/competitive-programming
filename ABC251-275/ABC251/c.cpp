#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}

int main() {
    int N;
    cin >> N;
    
    map<string, int> judge;
    int res = -1;
    int resIdx = -1;
    rep(i, 0, N){
        string s; int t;
        cin >> s >> t;
        if (judge.count(s)) continue;
        else {
            if (chmax(res, t)) resIdx = (i+1);
            judge[s] = t;
        }
    }
    cout << resIdx << endl;
}