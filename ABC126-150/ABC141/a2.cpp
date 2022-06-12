#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    cout << (s == "Sunny" ? "Cloudy" :(s == "Cloudy" ? "Rainy" : "Sunny")) << endl;
    return 0;
}