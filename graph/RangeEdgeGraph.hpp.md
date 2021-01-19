---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/nikkei2019_2_qual_d.cpp
    title: test/atcoder/nikkei2019_2_qual_d.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/RangeEdgeGraph.md
    document_title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    const long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int\
    \ INF = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
    \ = {0, 1, 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n      \
    \  os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/RangeEdgeGraph.hpp\"\
    \n\n/**\n * @brief \u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30B0\u30E9\u30D5\
    \n * @docs docs/graph/RangeEdgeGraph.md\n */\ntemplate <typename T> class RangeEdgeGraph\
    \ {\n    struct edge {\n        int to;\n        T cost;\n        edge(int to,\
    \ T cost) : to(to), cost(cost) {}\n        bool operator<(const edge& rhs) const\
    \ { return cost > rhs.cost; }\n    };\n    int n;\n    vector<vector<edge>> G;\n\
    \    void add_edge(int u, int v, T cost) { G[(3 * n <= u ? u - 2 * n : u)].emplace_back(v,\
    \ cost); }\n\npublic:\n    RangeEdgeGraph(int n) : n(n), G(3 * n) {\n        for\
    \ (int i = 1; i < n; i++) {\n            int l = i << 1 | 0, r = i << 1 | 1;\n\
    \            add_edge(i, l, 0);\n            add_edge(i, r, 0);\n            add_edge(l\
    \ + 2 * n, i + 2 * n, 0);\n            add_edge(r + 2 * n, i + 2 * n, 0);\n  \
    \      }\n    }\n    void add_edge(int l1, int r1, int l2, int r2, T cost) {\n\
    \        int add = G.size();\n        G.emplace_back();\n        for (l1 += n,\
    \ r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {\n            if (l1 & 1) add_edge((l1++)\
    \ + 2 * n, add, 0);\n            if (r1 & 1) add_edge((--r1) + 2 * n, add, 0);\n\
    \        }\n        for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {\n  \
    \          if (l2 & 1) G[add].emplace_back(l2++, cost);\n            if (r2 &\
    \ 1) G[add].emplace_back(--r2, cost);\n        }\n    }\n    vector<T> build(int\
    \ s) {\n        vector<T> dp(G.size(), numeric_limits<T>::max());\n        s +=\
    \ n;\n        dp[s] = 0;\n        priority_queue<edge> pq;\n        pq.emplace(s,\
    \ dp[s]);\n        while (!pq.empty()) {\n            auto p = pq.top();\n   \
    \         pq.pop();\n            int v = p.to;\n            if (dp[v] < p.cost)\
    \ continue;\n            for (const auto& e : G[v]) {\n                int u =\
    \ e.to;\n                if (dp[v] + e.cost < dp[u]) {\n                    dp[u]\
    \ = dp[v] + e.cost;\n                    pq.emplace(u, dp[u]);\n             \
    \   }\n            }\n        }\n        vector<T> res(dp.begin() + n, dp.begin()\
    \ + 2 * n);\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u533A\u9593\u306B\
    \u8FBA\u3092\u5F35\u308B\u30B0\u30E9\u30D5\n * @docs docs/graph/RangeEdgeGraph.md\n\
    \ */\ntemplate <typename T> class RangeEdgeGraph {\n    struct edge {\n      \
    \  int to;\n        T cost;\n        edge(int to, T cost) : to(to), cost(cost)\
    \ {}\n        bool operator<(const edge& rhs) const { return cost > rhs.cost;\
    \ }\n    };\n    int n;\n    vector<vector<edge>> G;\n    void add_edge(int u,\
    \ int v, T cost) { G[(3 * n <= u ? u - 2 * n : u)].emplace_back(v, cost); }\n\n\
    public:\n    RangeEdgeGraph(int n) : n(n), G(3 * n) {\n        for (int i = 1;\
    \ i < n; i++) {\n            int l = i << 1 | 0, r = i << 1 | 1;\n           \
    \ add_edge(i, l, 0);\n            add_edge(i, r, 0);\n            add_edge(l +\
    \ 2 * n, i + 2 * n, 0);\n            add_edge(r + 2 * n, i + 2 * n, 0);\n    \
    \    }\n    }\n    void add_edge(int l1, int r1, int l2, int r2, T cost) {\n \
    \       int add = G.size();\n        G.emplace_back();\n        for (l1 += n,\
    \ r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {\n            if (l1 & 1) add_edge((l1++)\
    \ + 2 * n, add, 0);\n            if (r1 & 1) add_edge((--r1) + 2 * n, add, 0);\n\
    \        }\n        for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {\n  \
    \          if (l2 & 1) G[add].emplace_back(l2++, cost);\n            if (r2 &\
    \ 1) G[add].emplace_back(--r2, cost);\n        }\n    }\n    vector<T> build(int\
    \ s) {\n        vector<T> dp(G.size(), numeric_limits<T>::max());\n        s +=\
    \ n;\n        dp[s] = 0;\n        priority_queue<edge> pq;\n        pq.emplace(s,\
    \ dp[s]);\n        while (!pq.empty()) {\n            auto p = pq.top();\n   \
    \         pq.pop();\n            int v = p.to;\n            if (dp[v] < p.cost)\
    \ continue;\n            for (const auto& e : G[v]) {\n                int u =\
    \ e.to;\n                if (dp[v] + e.cost < dp[u]) {\n                    dp[u]\
    \ = dp[v] + e.cost;\n                    pq.emplace(u, dp[u]);\n             \
    \   }\n            }\n        }\n        vector<T> res(dp.begin() + n, dp.begin()\
    \ + 2 * n);\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/RangeEdgeGraph.hpp
  requiredBy:
  - test/atcoder/nikkei2019_2_qual_d.cpp
  timestamp: '2021-01-19 15:36:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/RangeEdgeGraph.hpp
layout: document
redirect_from:
- /library/graph/RangeEdgeGraph.hpp
- /library/graph/RangeEdgeGraph.hpp.html
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30B0\u30E9\u30D5"
---
## 概要
区間から区間に辺が伸びるようなグラフ上での最短路を計算する. Segment Treeの構造を利用して頂点数$3n+q$, 辺数$4n+q\log n$のグラフを構成している.

- 'add_edge(l1,r1,l2,r2,cost)'：$[l1,r1)$から$[l2,r2)$に対して伸びる重み$cost$の辺を追加する.
- 'build(s)'：$s$を始点にしたときの各点までの最短距離を計算する.

## 計算量
- 'add_edge(l1,r1,l2,r2,cost)'：$O(\log n)$
- 'build(s)'：$O(n+q\log n)\log(n+q)$

## 参照
[区間に辺を張るテクの実装例（Dijkstra法セット）と使用例 - Lorent’s diary](https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d)