#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> be(N+10, N+5);
    vector<int> af(N+10, N+5);

    rep(i, 1, N+1){
        if (S[i-1] == 'L'){
            int a = be[i-1];
            af[a] = i;
            af[i] = i-1;
            be[i-1] = i;
            be[i] = a;
        } else {
            int a1 = af[i-1];
            af[i-1] = i;
            af[i] = a1;
            be[a1] = i;
            be[i] = i-1;
        }
    }

    int s = 0;
    rep(i, 0, N+1) if (be[i] == N+5) {s = i; break;}
    rep(i, 0, N+1){
        cout << s << " ";
        s = af[s];
    }
    cout << endl;


}