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

    vector<pii> stack;
    int size = 0;
    rep(i, 0, N){
        int a;
        cin >> a;

        if (stack.empty()){
            stack.push_back({a, 1});
            cout << ++size << endl;
            continue;
        }

        pii p = stack.back();
        if (p.first != a){
            stack.push_back({a, 1});
            cout << ++size << endl;
        } else {
            if (p.second + 1 < p.first) {
                stack.push_back({a, p.second+1});
                cout << ++size << endl;
            } else {
                rep(j, 0, p.second) stack.pop_back();
                size -= p.second;
                cout << size << endl;
            }
        }
    }
}