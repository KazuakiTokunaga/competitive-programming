#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

int main() {
    int a = 4;
    if (chmin(a, 3)) cout << "value changed: a=" << a << endl;
    if (chmax(a, 6)) cout << "value changed: a=" << a << endl;
}