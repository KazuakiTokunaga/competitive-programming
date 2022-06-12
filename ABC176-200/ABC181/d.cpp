#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    string s;
    cin >> s;

    vector<ll> cnt(10, 0);
    rep(i, 0, s.size()){
        cnt[int(s[i]-'0')]++;
    }
    
    int a = 8;
    while (a < 100){
        if (s == "8"){
            cout << "Yes" << endl;
            return 0;
        }
        if (s.size() == 2) {
            if (stoi(s) == a or stoi(s) == (a / 10) + (a % 10) * 10){
                cout << "Yes" << endl;
                return 0;
            }
        }
        a += 8;
    }

    bool yesno = false;
    while (a < 1000){
        vector<int> cnt1(10, 0);
        string t = to_string(a);

        rep(i, 0, t.size()){
            cnt1[int(t[i]-'0')]++;
        }
        bool make = true;
        rep(i, 0, 10){
            if (cnt[i] < cnt1[i]) make = false;
        }
        if (make) yesno = true;
        a += 8;
    }

    if (yesno) cout << "Yes" << endl;
    else cout << "No" << endl;
}