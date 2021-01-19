---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/SlidingWindowAggregation.hpp
    title: Sliding Window Aggregation (SWAG)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nconst\
    \ long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int INF\
    \ = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/SlidingWindowAggregation.hpp\"\
    \n\n/**\n * @brief Sliding Window Aggregation (SWAG)\n * @docs docs/datastructure/SlidingWindowAggregation.md\n\
    \ */\ntemplate <typename Monoid> struct SlidingWindowAggregation {\n    typedef\
    \ function<Monoid(Monoid, Monoid)> F;\n    stack<pair<Monoid, Monoid>> front_stack,\
    \ back_stack;\n    F f;\n    Monoid id;\n    SlidingWindowAggregation(F f, Monoid\
    \ id) : f(f), id(id), front_stack(), back_stack() {\n        front_stack.emplace(id,\
    \ id);\n        back_stack.emplace(id, id);\n    }\n    void push(const Monoid&\
    \ x) { back_stack.emplace(x, f(back_stack.top().second, x)); }\n    void pop()\
    \ {\n        if (front_stack.size() == 1) {\n            while (1 < back_stack.size())\
    \ {\n                Monoid t = back_stack.top().first;\n                Monoid\
    \ calc = f(t, front_stack.top().second);\n                front_stack.emplace(t,\
    \ calc);\n                back_stack.pop();\n            }\n        }\n      \
    \  front_stack.pop();\n    }\n    Monoid fold() { return f(front_stack.top().second,\
    \ back_stack.top().second); }\n};\n#line 5 \"test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,L;\
    \ cin >> N >> L;\n    vector<int> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\
    \n    SlidingWindowAggregation<int> SWAG([](int a,int b){return min(a,b);},INT_MAX);\n\
    \n    for (int i=0;i<L-1;++i) SWAG.push(a[i]);\n    for (int i=L-1;i<N;++i){\n\
    \        SWAG.push(a[i]);\n        cout << SWAG.fold() << (i+1==N?'\\n':' ');\n\
    \        SWAG.pop();\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SlidingWindowAggregation.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,L;\
    \ cin >> N >> L;\n    vector<int> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\
    \n    SlidingWindowAggregation<int> SWAG([](int a,int b){return min(a,b);},INT_MAX);\n\
    \n    for (int i=0;i<L-1;++i) SWAG.push(a[i]);\n    for (int i=L-1;i<N;++i){\n\
    \        SWAG.push(a[i]);\n        cout << SWAG.fold() << (i+1==N?'\\n':' ');\n\
    \        SWAG.pop();\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SlidingWindowAggregation.hpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 14:04:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
- /verify/test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp.html
title: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
---