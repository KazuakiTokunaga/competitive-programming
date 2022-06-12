#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    transform(s.begin() + k - 1, s.begin() + k, s.begin() + k - 1, ::tolower);
    cout << s << endl;


}