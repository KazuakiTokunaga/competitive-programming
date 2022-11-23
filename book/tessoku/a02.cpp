#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, X;
    cin >> N >> X;

    rep(i, 0, N) {
        int A;
        cin >> A;
        if (A==X) {cout << "Yes" << endl; return 0;}
    }
    
    cout << "No" << endl;

}