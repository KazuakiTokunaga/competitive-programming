
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
	vector<int> a = {1,2,3,4,5,6,7};
	cout << lower_bound(all(a), 2) - a.begin() << endl;
}