#include <iostream>
using namespace std;

#define LLI long long int
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
int main() {
ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
    LLI a,b;
    cin >> a >> b;
    cout << PowMod(a,b,10LL) << endl;
    }
return 0;
}

