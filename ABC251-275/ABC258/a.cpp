#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int K;
    cin >> K;

    if (K >= 60) {
        K -= 60;
        string s = to_string(K);
        if (s.size() == 1) s = '0' + s; 
        cout << "22:" << s << endl;
    } else {
        string s = to_string(K);
        if (s.size()==1) s = '0' + s;
        cout << "21:" << s << endl;
    }
}