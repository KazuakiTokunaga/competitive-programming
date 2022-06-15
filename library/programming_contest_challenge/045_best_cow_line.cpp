// 貪欲法_辞書順最小の問題

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()


int main() {
    int n; string s;
    cin >> n >> s;
    
    string res = "";
    int a = 0, b = n-1;

    while (a <= b){
        string sub = s.substr(a, b-a+1);
        string subr = sub;
        reverse(all(subr));
        
        bool left = true;
        if (sub <= subr){
            left = true;
        } else {
            left = false;
        }

        if (left) {res += s[a]; a++;}
        else {res += s[b]; b--;}
    }

    cout << res << endl;
}
