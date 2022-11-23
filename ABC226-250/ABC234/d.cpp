#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, K;
    cin >> N >> K;

    set<int> s;
    auto iter = s.begin();
    rep(i, 0, N){
        int p;
        cin >> p;
        s.insert(p);

        if (i+1 == K){ // k番目
            iter = s.begin();
            cout << *iter << endl;
        }
        if (i+1 > K){
            if (*iter < p) iter++;
            cout << *iter << endl;
        }
    }
    
}