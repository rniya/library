---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/dp/monotone_minima.md
    document_title: monotone minima
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"dp/monotone_minima.hpp\"\
    \n\n/**\n * @brief monotone minima\n * @docs docs/dp/monotone_minima.md\n */\n\
    template <class Select> vector<size_t> monotone_minima(const size_t H, const size_t\
    \ W, const Select& select) {\n    auto solve = [&](auto self, const vector<size_t>&\
    \ v) -> vector<size_t> {\n        const size_t n = v.size();\n        if (n ==\
    \ 0) return {};\n        vector<size_t> u;\n        for (size_t i = 1; i < n;\
    \ i += 2) u.emplace_back(v[i]);\n        const vector<size_t> ch = self(self,\
    \ u);\n        vector<size_t> res(n);\n        for (size_t i = 0; i < ch.size();\
    \ i++) res[i << 1 | 1] = ch[i];\n        for (size_t i = 0, cur = 0; i < n; i\
    \ += 2) {\n            size_t nxt = (i + 1 == n ? W - 1 : res[i + 1]);\n     \
    \       for (res[i] = cur; cur < nxt;) {\n                if (select(v[i], res[i],\
    \ ++cur)) {\n                    res[i] = cur;\n                }\n          \
    \  }\n        }\n        return res;\n    };\n\n    vector<size_t> dp(H);\n  \
    \  iota(dp.begin(), dp.end(), 0);\n    return solve(solve, dp);\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief monotone minima\n\
    \ * @docs docs/dp/monotone_minima.md\n */\ntemplate <class Select> vector<size_t>\
    \ monotone_minima(const size_t H, const size_t W, const Select& select) {\n  \
    \  auto solve = [&](auto self, const vector<size_t>& v) -> vector<size_t> {\n\
    \        const size_t n = v.size();\n        if (n == 0) return {};\n        vector<size_t>\
    \ u;\n        for (size_t i = 1; i < n; i += 2) u.emplace_back(v[i]);\n      \
    \  const vector<size_t> ch = self(self, u);\n        vector<size_t> res(n);\n\
    \        for (size_t i = 0; i < ch.size(); i++) res[i << 1 | 1] = ch[i];\n   \
    \     for (size_t i = 0, cur = 0; i < n; i += 2) {\n            size_t nxt = (i\
    \ + 1 == n ? W - 1 : res[i + 1]);\n            for (res[i] = cur; cur < nxt;)\
    \ {\n                if (select(v[i], res[i], ++cur)) {\n                    res[i]\
    \ = cur;\n                }\n            }\n        }\n        return res;\n \
    \   };\n\n    vector<size_t> dp(H);\n    iota(dp.begin(), dp.end(), 0);\n    return\
    \ solve(solve, dp);\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: dp/monotone_minima.hpp
  requiredBy: []
  timestamp: '2021-09-11 00:56:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/monotone_minima.hpp
layout: document
redirect_from:
- /library/dp/monotone_minima.hpp
- /library/dp/monotone_minima.hpp.html
title: monotone minima
---
## 概要

f(i) を求める主なアルゴリズムは 2 種類存在する。

## 計算量
$O(W + H \log W)$

## 問題例
[2020-2021 Summer Petrozavodsk Camp, Day 6: Korean Contest F. Rhythm Game](https://codeforces.com/gym/102984/problem/F)

## 参照
[Monge 行列と monotone minima について - Lorent’s diary](https://lorent-kyopro.hatenablog.com/entry/2021/04/04/133958)
[DP高速化 - ferinの競プロ帳](https://ferin-tech.hatenablog.com/entry/2018/02/23/071343)
[Knuth-Yao speedup - 週刊 spaghetti_source - TopCoder部](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html)