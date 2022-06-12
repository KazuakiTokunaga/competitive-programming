#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long i;
    i = floor(pow(n, 1.0/2.0));

    for (i; i > 0; i--) {
        if (n % i == 0) {
            cout << (n / i) + i - 2 << endl;
            return 0;
        }
    }
}

