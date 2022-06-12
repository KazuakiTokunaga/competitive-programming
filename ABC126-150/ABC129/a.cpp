#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    vector<int> v(3);
    rep(i, 0, 3){
        cin >> v[i];
    };

    sort(v.begin(), v.end());

    cout << v[0] + v[1] << endl;   
}