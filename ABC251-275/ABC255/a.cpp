#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int R, C;
    cin >> R >> C; R--; C--;

    vector<vector<int>> A(2);
    rep(i, 0, 2){
        int a1, a2;
        cin >> a1 >> a2;
        A[i].push_back(a1);
        A[i].push_back(a2);
    }

    cout << A[R][C] << endl;
}