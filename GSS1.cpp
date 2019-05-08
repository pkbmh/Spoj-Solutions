#include <iostream>
using namespace std;
#define LLI long long int
LLI mx = -750350001;

struct node {
    LLI l, r, f,m;
    node(){}
    node(LLI a){
        l = r = f = m = a;
    }
};

node tree[50000*4+10];
int arr[50000];

node merge_node(node left, node right) {
    node n;
    n.f = left.f + right.f;
    n.l = max(left.l , max(left.f, left.f+right.l));
    n.r  = max(right.r, max(right.f, right.f+left.r));
    n.m = max(left.m, right.m);
    n.m = max(max(n.m, n.f), max(n.l, n.r));
    n.m = max(n.m, left.r+right.l);
    return n;
}
void build(int ind, int l, int r) {
    if(l == r) {
        tree[ind] = node(arr[l]);
        return;
    }
    int mid = (l+r) / 2;
    build(ind*2+1, l, mid);
    build(ind*2+2, mid+1, r);
    tree[ind] = merge_node(tree[ind*2+1], tree[ind*2+2]);
}

node query(int ind, int l, int r, int p, int q) {
    if(p > r || q < l) return node(mx);
    if(l >= p && r <= q) return tree[ind];
    int mid = (l+r) / 2;
    return merge_node(query(ind*2+1, l, mid, p, q), query(ind*2+2, mid+1, r, p, q));
}
int main() {
ios::sync_with_stdio(0); cin.tie(0);
    int n, l,r,m;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    build(0, 0, n-1);
    cin >> m;
    while(m--) {
        cin >> l >> r;
        l--; r--;
        node res = query(0, 0, n-1, l, r);
        cout << max(max(res.m,res.f), max(res.l, res.r)) << endl;
    }
return 0;
}

