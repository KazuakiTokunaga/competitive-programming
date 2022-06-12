#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    string s; int q;
    cin >> s >> q;

    int status = 1;

    string head = "";
    rep(i, 0, q){
        int t;
        cin >> t;

        if (t==1) status = 1 - status;
        if (t==2){
            int f; string c;
            cin >> f >> c;
            if (status){
                if (f==1) head += c;
                else  s += c;
            } else {
                if (f==1) s += c;
                else head += c;
            }
        }
    }

    reverse(head.begin(), head.end());
    s = head + s;
    if (!status) reverse(s.begin(), s.end());
    cout << s << endl;

}