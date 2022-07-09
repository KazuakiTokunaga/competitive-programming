#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    int cnt = 0;
    rep(i, 1, 30){
        rep(j, 1, 30){
            rep(k, 1, 30){
                rep(l, 1, 30){
                    int a02 = h1 - i - j;
                    int a12 = h2 - k - l;
                    int a20 = w1 - k - i;
                    int a21 = w2 - l - j;
                    int a22 = h3 - a21 - a20;
                    if (a02 < 1 or a12 < 1 or a20 < 1 or a21 < 1 or a22 < 1) continue;
                    if (a22 != w3 - a12 - a02) continue;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}