#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

bool year(int num){
    if (num == 0 or num >= 13){
        return true;
    } else {
        return false;
    }
}

int main() {
    string s;
    cin >> s;
    
    int head = int(s[0]-'0') * 10 + int(s[1]-'0');
    int tail = int(s[2]-'0') * 10 + int(s[3]-'0');


    if (year(head) and !year(tail)){
        cout << "YYMM" << endl;
    } else if (year(tail) and !year(head)){
        cout << "MMYY" << endl;
    } else if (!year(tail) and !year(head)){
        cout << "AMBIGUOUS" << endl;
    } else {
        cout << "NA" << endl;
    }
}