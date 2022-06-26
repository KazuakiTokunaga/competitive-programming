#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
using ld = long double;

int main() {
    int n;
    cin >> n;
    
    vector<pii> AB(n);
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        AB[i] = make_pair(a, b);
    }

    bool odd = false;
    if (n % 2 == 1) odd = true;

    auto greater = [](auto a, auto b){return a.second > b.second;}; // lambda式

    if (odd){
        sort(all(AB));
        ll a = AB[n/2].first;

        // Bが大きい順
        sort(all(AB), greater);
        ll b = AB[n/2].second;

        cout << max(b-a+1, (ll)0) << endl;

    } else {
        sort(all(AB));
        int a0 = AB[n/2-1].first; int a1 = AB[n/2].first;
        ld s = double(a0 + a1) / 2;

        sort(all(AB), greater);
        int b0 = AB[n/2-1].second; int b1 = AB[n/2].second;
        ld e = double(b0 + b1) / 2;

        cout << int((e - s) * 2 + 1) << endl;
    }
    

}