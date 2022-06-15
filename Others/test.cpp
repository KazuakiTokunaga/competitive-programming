#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)


int main() {
    vector<int> a = {1,2,3,4,5,6};
	auto iter = upper_bound(a.begin(), a.end(), 1);
	cout << (int)(iter - a.begin()) << endl;
}