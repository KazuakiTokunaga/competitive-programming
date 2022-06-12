#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    vector<int> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    
    vector<int> v = {p.begin(), p.end()}; // イテレータ
    sort(v.begin(), v.end());

    int id = 1;
    int a = 0, b = 0;
    do {
        if (v == p) a = id;
        if (v == q) b = id;
        id++;
    } while(next_permutation(v.begin(), v.end()));

    cout << abs(a-b) << endl;
}