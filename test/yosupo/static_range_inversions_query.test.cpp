#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../algorithm/Mo.hpp"
#include "../../base.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"
#include "../../util/compress.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    Mo mo(N);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        mo.add(l, r);
    }

    vector<int> B = A;
    map<int, int> mp = compress(B);
    for (int i = 0; i < N; i++) A[i] = mp[A[i]];
    int n = mp.size();
    BinaryIndexedTree<int> BIT(n);
    vector<long long> ans(Q);
    long long inv = 0;
    int sum = 0;

    auto add_left = [&](int idx) {
        inv += BIT.query(0, A[idx]);
        sum++;
        BIT.add(A[idx], 1);
    };
    auto add_right = [&](int idx) {
        inv += BIT.query(A[idx] + 1, n);
        sum++;
        BIT.add(A[idx], 1);
    };
    auto del_left = [&](int idx) {
        inv -= BIT.query(0, A[idx]);
        sum--;
        BIT.add(A[idx], -1);
    };
    auto del_right = [&](int idx) {
        inv -= BIT.query(A[idx] + 1, n);
        sum--;
        BIT.add(A[idx], -1);
    };
    auto rem = [&](int idx) { ans[idx] = inv; };

    mo.run(add_left, add_right, del_left, del_right, rem);

    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
    return 0;
}