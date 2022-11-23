#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int T;
    cin >> T;
    
    rep(i, 0, T){
        ll a, s;
        cin >> a >> s;

        int c = 0;
        bool check = true;
        rep(j, 0, 60){
            int a1 = (a >> j) & 1;
            int s1 = (s >> j) & 1;

            // cout << c << " " << a1 << " " << s1 << " " << endl;
            if (!c){
                if (a1 & s1) {check = false; break;}
                else if (a1 & !s1) c = 1;
                else if (!a1 & s1) c = 0;
                else c = 0;
            } else {
                if (a1 & s1) c = 1;
                else if (a1 & !s1) {check = false; break;}
                else if (!a1 & s1) c = 0;
                else c = 1;
            }
            
            if (j == 59 and c) check = false;
        }
        if (check) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}