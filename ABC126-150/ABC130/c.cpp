#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    
    cout << (double)w*h*0.5 << " " << (x == (double)w*0.5 and y == (double) h*0.5 ? 1: 0) << endl;   
}