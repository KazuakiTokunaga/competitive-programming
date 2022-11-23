#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string S;
    cin >> S;
    
    if (int(S[0]-'0')) {cout << "No" << endl; return 0;}
    
    // 0: すべて倒れている　1: 1本以上残っている
    vector<int> column(7, 0);
    rep(i, 0, 10){
        int id = i+1;
        int f = int(S[i]-'0');
        if (f) {
            if (id == 7) column[0] = 1;
            if (id == 4) column[1] = 1;
            if (id == 2 or id == 8) column[2] = 1;
            if (id == 1 or id == 5) column[3] = 1;
            if (id == 3 or id == 9) column[4] = 1;
            if (id == 6) column[5] = 1;
            if (id == 10) column[6] = 1;
        }
    }

    bool check = false;
    rep(i, 1, 6){
        if (!column[i]){
            int left = 0, right = 0;
            rep(j, 0, i) if (column[j]) left = 1;
            rep(j, i+1, 7) if (column[j]) right = 1;
            if (left and right) check = true;
        }
    }

    if (check) cout << "Yes" << endl;
    else cout << "No" << endl;
}