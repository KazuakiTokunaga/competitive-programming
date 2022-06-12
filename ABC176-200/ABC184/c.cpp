#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

bool one_move(int a, int b, int c, int d){
    if (a + b == c + d) return true;
    if (a - b == c - d) return true;
    if (abs(a-c) + abs(b-d) <= 3) return true;
    return false;
}

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 and c1 == c2) {
        cout << 0 << endl;
        return 0;
    }
    if (one_move(r1, c1, r2, c2)){
        cout << 1 << endl;
        return 0;
    }
    if ((r1+c1) % 2 == (r2 + c2) % 2){
        cout << 2 << endl;
        return 0;
    }
    rep(i, -3, 4){
        rep(j, -3, 4){
            if (i == 0 and j == 0) continue;
            if (abs(i) + abs(j) > 3) continue;
            if (one_move(r1+i, c1+j, r2, c2)){
                cout << 2 << endl;
                return 0;
            }
        }
    }
    cout << 3 << endl;
}