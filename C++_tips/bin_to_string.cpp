#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// http://vivi.dyndns.org/tech/cpp/binHex.html
// https://atcoder.jp/contests/apg4b/tasks/APG4b_ac?lang=ja

string toBinary(ll n){
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
	reverse(r.begin(), r.end());
    return r;
}

int main() {
    
    //bitsetを用いる
	bitset<20> bs(100);
	cout << bs << endl;
	rrep(i, 19, 0){
		cout << bs[i]; // bitは右から0,1,2とアクセスする
	}
	cout << endl;
    cout << bs.to_string() << endl;

    // 関数で変換する
	cout << toBinary(419716939) << endl;
}