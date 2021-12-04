---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/Dinic.hpp
    title: Dinic (Maximum flow)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.Dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#line 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\n\
    typedef unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (size_t i =\
    \ 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \"\
    \ \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr\
    \ != m.end();) {\n        os << '(' << itr->first << ',' << itr->second << ')';\n\
    \        if (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n    \
    \    os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, size_t N> ostream& operator<<(ostream& os, const array<T,\
    \ N>& v) {\n    for (size_t i = 0; i < N; i++) {\n        os << v[i] << (i + 1\
    \ == N ? \"\" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename\
    \ T> void print_tuple(ostream&, const T&) {}\ntemplate <int i, typename T, typename\
    \ H, class... Args> void print_tuple(ostream& os, const T& t) {\n    if (i) os\
    \ << ',';\n    os << get<i>(t);\n    print_tuple<i + 1, T, Args...>(os, t);\n\
    }\ntemplate <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>&\
    \ t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>, Args...>(os, t);\n\
    \    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class\
    \ Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr\
    \ << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate\
    \ <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate\
    \ <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\nint topbit(signed\
    \ t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(long long t)\
    \ { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(signed a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long long a) { return a == 0 ?\
    \ 64 : __builtin_ctzll(a); }\nint popcount(signed t) { return __builtin_popcount(t);\
    \ }\nint popcount(long long t) { return __builtin_popcountll(t); }\nbool ispow2(int\
    \ i) { return i && (i & -i) == i; }\nlong long MSK(int n) { return (1LL << n)\
    \ - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y >= 1);\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T> T floor(T x, T y)\
    \ {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\n\
    template <class T1, class T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n  \
    \      a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n}\ntemplate <typename T> int lwb(const vector<T>& v, const\
    \ T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }\n#pragma endregion\n\
    #line 9 \"flow/Dinic.hpp\"\n\ntemplate <typename Cap, bool directed> struct Dinic\
    \ {\n    Dinic(int n) : n(n), G(n), level(n), iter(n) {}\n\n    int add_edge(int\
    \ from, int to, Cap cap) {\n        assert(0 <= from && from < n);\n        assert(0\
    \ <= to && to < n);\n        assert(0 <= cap);\n        assert(from != to);\n\
    \        int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();\n\
    \        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, to_id);\n        G[to].emplace_back(from, directed ? 0 : cap, from_id);\n\
    \        return m;\n    }\n\n    int add_vertex() {\n        G.emplace_back();\n\
    \        level.emplace_back();\n        iter.emplace_back();\n        return n++;\n\
    \    }\n\n    std::tuple<int, int, Cap, Cap> get_edge(int i) {\n        assert(0\
    \ <= i && i < (int)pos.size());\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap};\n    }\n\n    std::vector<std::tuple<int, int, Cap, Cap>>\
    \ edges() {\n        std::vector<std::tuple<int, int, Cap, Cap>> res;\n      \
    \  for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n  \
    \      return res;\n    }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        assert(0 <= i && i < (int)pos.size());\n        assert(0 <= new_flow\
    \ && new_flow <= new_cap);\n        auto& e = G[pos[i].first][pos[i].second];\n\
    \        auto& re = G[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n   \
    \     re.cap = (directed ? new_flow : new_cap + new_flow);\n    }\n\n    Cap max_flow(int\
    \ s, int t) { return max_flow(s, t, std::numeric_limits<Cap>::max()); }\n\n  \
    \  Cap max_flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s <\
    \ n);\n        assert(0 <= t && t < n);\n        if (s == t) return 0;\n     \
    \   Cap flow = 0;\n        while (flow < flow_limit) {\n            bfs(s, t);\n\
    \            if (level[t] < 0) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            while (flow < flow_limit) {\n                Cap f = dfs(s,\
    \ t, flow_limit - flow);\n                if (f == 0) break;\n               \
    \ flow += f;\n            }\n        }\n        return flow;\n    }\n\n    std::vector<bool>\
    \ min_cut(int s) {\n        assert(0 <= s && s < n);\n        std::vector<bool>\
    \ visited(n);\n        std::queue<int> que;\n        visited[s] = true;\n    \
    \    que.emplace(s);\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            for (const auto& e : G[v]) {\n          \
    \      if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.emplace(e.to);\n                }\n            }\n  \
    \      }\n        return visited;\n    }\n\n    void dump_graphviz(std::string\
    \ filename = \"maxflow\") {\n        std::ofstream ofs(filename + \".dot\");\n\
    \        ofs << \"digraph {\\n\";\n        auto es = edges();\n        for (const\
    \ auto& e : es) {\n            int from, to;\n            Cap cap, flow;\n   \
    \         std::tie(from, to, cap, flow) = e;\n            ofs << from << \" ->\
    \ \" << to << \" [label = \\\"\" << flow << \"/\" << cap << \"\\\", color = \"\
    \n                << (flow == cap ? \"red\"\n                    : flow > 0  ?\
    \ \"blue\"\n                                : \"black\")\n                << \"\
    ];\\n\";\n        }\n        ofs << \"}\\n\";\n        ofs.close();\n        return;\n\
    \    }\n\nprivate:\n    struct edge {\n        int to;\n        Cap cap;\n   \
    \     int rev;\n        edge(int to, Cap cap, int rev) : to(to), cap(cap), rev(rev)\
    \ {}\n    };\n\n    int n;\n    std::vector<std::vector<edge>> G;\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<int> level, iter;\n\n    void bfs(int s, int t)\
    \ {\n        std::fill(level.begin(), level.end(), -1);\n        std::queue<int>\
    \ que;\n        level[s] = 0;\n        que.emplace(s);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (const auto& e : G[v]) {\n                if (e.cap > 0 && level[e.to] < 0)\
    \ {\n                    level[e.to] = level[v] + 1;\n                    if (e.to\
    \ == t) return;\n                    que.emplace(e.to);\n                }\n \
    \           }\n        }\n    }\n\n    Cap dfs(int v, int t, Cap f) {\n      \
    \  if (v == t) return f;\n        for (int& i = iter[v]; i < (int)G[v].size();\
    \ i++) {\n            auto& e = G[v][i];\n            if (e.cap <= 0 || level[v]\
    \ >= level[e.to]) continue;\n            Cap d = dfs(e.to, t, std::min(f, e.cap));\n\
    \            if (d <= 0) continue;\n            e.cap -= d;\n            G[e.to][e.rev].cap\
    \ += d;\n            return d;\n        }\n        return 0;\n    }\n};\n\n/**\n\
    \ * @brief Dinic (Maximum flow)\n * @docs docs/flow/Dinic.md\n */\n#line 5 \"\
    test/aoj/GRL_6_A.Dinic.test.cpp\"\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int V, E;\n    cin >> V >> E;\n\n    Dinic<int, true> D(V);\n\n    for (int\
    \ i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n  \
    \      D.add_edge(u, v, c);\n    }\n\n    cout << D.max_flow(0, V - 1) << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../flow/Dinic.hpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V, E;\n    cin\
    \ >> V >> E;\n\n    Dinic<int, true> D(V);\n\n    for (int i = 0; i < E; i++)\
    \ {\n        int u, v, c;\n        cin >> u >> v >> c;\n        D.add_edge(u,\
    \ v, c);\n    }\n\n    cout << D.max_flow(0, V - 1) << '\\n';\n}\n"
  dependsOn:
  - base.hpp
  - flow/Dinic.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.Dinic.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.Dinic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.Dinic.test.cpp
- /verify/test/aoj/GRL_6_A.Dinic.test.cpp.html
title: test/aoj/GRL_6_A.Dinic.test.cpp
---