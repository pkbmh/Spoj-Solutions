// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

//i/o
#define SCI(a) scanf("%d", &a)
#define SCLL(a) scanf("%lld", &a)
#define PRI(a) printf("%d\n", a)
#define PRLL(a) printf("%lld\n", a)
#define gc getchar_unlocked

/*void fastRead_int(int *a)
{
register char c=0;
while (c#include<33) c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
}*/

//stl function
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define TR(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define LB(v , a) lower_bound (v.begin(), v.end(), a)
#define UP(v , a) upper_bound (v.begin(), v.end(), a)
#define ALL(a) a.begin() , a.end()
#define RALL(a) a.rbegin(), a.rend()

//data type
#define LLI long long int
#define LLU long long unsigned
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double double>
#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VLLI vector<LLI>
#define VPII vector<PII>
#define PSI pair<string,int>
#define PSS pair<string,string>
#define VS vector<string>
#define VVI vector<vector<int> >

//Initialization
#define SET0(a) memset(a , 0 , sizeof(a))
#define COPY(d , s) memcpy(d , s , sizeof(s))
#define SET1(a) memset(a , 1 , sizeof(a))
#define SETN1(a) memset(a , -1 , sizeof(a))

#define FOR(i ,s, e) for(int i = s; i <= e; i++)
#define RFOR(i,s, e) for(int i = s; i >= e; i--)
#define LOOP(n) for(int i = 0; i < n; ++i)
#define nl '\n'
template<class T> void swaper(T &a , T &b) {T c = a; a = b; b = c;}
template<class T> T GCD(T a , T b) {if(b == 0)return a; else return GCD(b , a%b);}
template<class T>  T MulMod(T a , T b , T mod) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y)%mod; y = (y<<1)%mod;b >>= 1;}return x;}
template<class T>  T PowMod(T a , T b, T mod) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y)%mod;y = (y*y)%mod;b >>= 1;}return x;}
template<class T>  T Multiply(T a , T b) {T x,y;x = 0;y = a;while(b > 0) {if(b&1) x = (x+y);y = (y<<1);b >>= 1;}return x;}
template<class T>  T Power(T a , T b) {T x,y;x = 1;y = a;while(b > 0) {if(b&1) x = (x*y);y = (y*y);b >>= 1;}return x;}

const int MAX = 1e6+10;
const LLI MOD7 = 1e9+7;
const LLI MOD9 = 1e9+9;


void dfs(vector<VPII> &g, int u, VPII &euler, VI&first) {
    first[u] = euler.size();
    euler.push_back({u, -1});
    for(auto v: g[u]) {
        if(first[v.first] == -1) {
            dfs(g, v.first, euler, first);
            euler.push_back({u,v.second});
        }
    }
}

void build(VPII &tree, int ind, int l, int h, VPII &arr) {
    if(l==h) {
        tree[ind] = {arr[l].second, arr[l].second};
        return;
    }
    int mid = l + (h-l) / 2;
    build(tree, ind*2+1, l, mid, arr);
    build(tree, ind*2+2, mid+1, h, arr);
    if (tree[ind*2+1].second == -1) tree[ind] = tree[ind*2+2];
    else if (tree[ind*2+2].second == -1) tree[ind] = tree[ind*2+1];
    else {
        tree[ind].first = min(tree[ind*2+2].first, tree[ind*2+1].first);
        tree[ind].second = max(tree[ind*2+2].second, tree[ind*2+1].second);
    }
}

PII query(VPII &tree, int ind, int l, int h, int p, int q) {
    if(p > h || q < l) return {-1,-1};
    if(l >= p && h <= q) return tree[ind];
    int mid = l + (h-l) / 2;
    auto pl = query(tree, ind*2+1, l, mid, p, q);
    auto pr = query(tree, ind*2+2, mid+1, h, p, q);
    if(pl.second == -1) return pr;
    if(pr.second == -1) return pl;
    return {min(pl.first, pr.first), max(pl.second, pr.second)};
}
int main() {
ios::sync_with_stdio(0); cin.tie(0);
    int n, u, v, w, q, l, r;
    cin >> n;
    vector<vector<PII>> g(n+1);
    for(int i = 0; i < n-1; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<PII> euler;
    vector<int>first(n+1, -1);
    dfs(g, 1, euler, first);
    cout << "eu" << endl;
    for(auto p: euler) cout << p.first << " "<< p.second << endl;
    cout << "eu" << endl;
    int esz = euler.size();
    VPII tree(esz*4);
    build(tree, 0, 0, esz-1, euler);  
    cin >> q;
    while(q--) {
        cin >> l >> r;
        auto p = query(tree, 0, 0, esz-1, min(first[l], first[r]), max(first[l], first[r]));
        cout << p.first << " "<< p.second << endl;
    } 
return 0;
}

