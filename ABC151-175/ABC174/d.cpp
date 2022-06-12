#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n; string s;
    cin >> n >> s;

    int count_r = 0;
    vector<int> accum_r(n, 0);
    rep(i, 0, n){
        if (s[i] == 'R') count_r++;
        accum_r[i] = count_r;
    }

    cout << count_r - accum_r[count_r-1] << endl;   
}