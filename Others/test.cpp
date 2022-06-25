
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
	pii p1 = {1, 1};
	pii p2 = {1, 0};
	cout << max(p1, p2).first << " " << max(p1, p2).second << endl;
}