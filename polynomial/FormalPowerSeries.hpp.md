---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: polynomial/StirlingSecond.hpp
    title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1302.test.cpp
    title: test/yukicoder/1302.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/polynomial/FormalPowerSeries.md
    document_title: Formal Power Series
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"polynomial/FormalPowerSeries.hpp\"\
    \n\n/**\n * @brief Formal Power Series\n * @docs docs/polynomial/FormalPowerSeries.md\n\
    \ */\ntemplate <typename M> struct FormalPowerSeries : vector<M> {\n    using\
    \ vector<M>::vector;\n    using Poly = FormalPowerSeries;\n    using MUL = function<Poly(Poly,\
    \ Poly)>;\n    static MUL& get_mul() {\n        static MUL mul = nullptr;\n  \
    \      return mul;\n    }\n    static void set_mul(MUL f) { get_mul() = f; }\n\
    \    void shrink() {\n        while (this->size() && this->back() == M(0)) this->pop_back();\n\
    \    }\n    Poly pre(int deg) const { return Poly(this->begin(), this->begin()\
    \ + min((int)this->size(), deg)); }\n    Poly operator+(const M& v) const { return\
    \ Poly(*this) += v; }\n    Poly operator+(const Poly& p) const { return Poly(*this)\
    \ += p; }\n    Poly operator-(const M& v) const { return Poly(*this) -= v; }\n\
    \    Poly operator-(const Poly& p) const { return Poly(*this) -= p; }\n    Poly\
    \ operator*(const M& v) const { return Poly(*this) *= v; }\n    Poly operator*(const\
    \ Poly& p) const { return Poly(*this) *= p; }\n    Poly operator/(const Poly&\
    \ p) const { return Poly(*this) /= p; }\n    Poly operator%(const Poly& p) const\
    \ { return Poly(*this) %= p; }\n    Poly& operator+=(const M& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] += v;\n        return *this;\n\
    \    }\n    Poly& operator+=(const Poly& p) {\n        if (p.size() > this->size())\
    \ this->resize(p.size());\n        for (int i = 0; i < p.size(); i++) (*this)[i]\
    \ += p[i];\n        return *this;\n    }\n    Poly& operator-=(const M& v) {\n\
    \        if (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n     \
    \   return *this;\n    }\n    Poly& operator-=(const Poly& p) {\n        if (p.size()\
    \ > this->size()) this->resize(p.size());\n        for (int i = 0; i < p.size();\
    \ i++) (*this)[i] -= p[i];\n        return *this;\n    }\n    Poly& operator*=(const\
    \ M& v) {\n        for (int i = 0; i < this->size(); i++) (*this)[i] *= v;\n \
    \       return *this;\n    }\n    Poly& operator*=(const Poly& p) {\n        if\
    \ (this->empty() || p.empty()) {\n            this->clear();\n            return\
    \ *this;\n        }\n        assert(get_mul() != nullptr);\n        return *this\
    \ = get_mul()(*this, p);\n    }\n    Poly& operator/=(const Poly& p) {\n     \
    \   if (this->size() < p.size()) {\n            this->clear();\n            return\
    \ *this;\n        }\n        int n = this->size() - p.size() - 1;\n        return\
    \ *this = (rev().pre(n) * p.rev().inv(n)).pre(n).rev(n);\n    }\n    Poly& operator%=(const\
    \ Poly& p) { return *this -= *this / p * p; }\n    Poly operator<<(const int deg)\
    \ {\n        Poly res(*this);\n        res.insert(res.begin(), deg, M(0));\n \
    \       return res;\n    }\n    Poly operator>>(const int deg) {\n        if (this->size()\
    \ <= deg) return {};\n        Poly res(*this);\n        res.erase(res.begin(),\
    \ res.begin() + deg);\n        return res;\n    }\n    Poly operator-() const\
    \ {\n        Poly res(this->size());\n        for (int i = 0; i < this->size();\
    \ i++) res[i] = -(*this)[i];\n        return res;\n    }\n    Poly rev(int deg\
    \ = -1) const {\n        Poly res(*this);\n        if (~deg) res.resize(deg, M(0));\n\
    \        reverse(res.begin(), res.end());\n        return res;\n    }\n    Poly\
    \ diff() const {\n        Poly res(max(0, (int)this->size() - 1));\n        for\
    \ (int i = 1; i < this->size(); i++) res[i - 1] = (*this)[i] * M(i);\n       \
    \ return res;\n    }\n    Poly integral() const {\n        Poly res(this->size()\
    \ + 1);\n        res[0] = M(0);\n        for (int i = 0; i < this->size(); i++)\
    \ res[i + 1] = (*this)[i] / M(i + 1);\n        return res;\n    }\n    Poly inv(int\
    \ deg = -1) const {\n        assert((*this)[0] != M(0));\n        if (deg < 0)\
    \ deg = this->size();\n        Poly res({M(1) / (*this)[0]});\n        for (int\
    \ i = 1; i < deg; i <<= 1) {\n            res = (res + res - res * res * pre(i\
    \ << 1)).pre(i << 1);\n        }\n        return res.pre(deg);\n    }\n    Poly\
    \ log(int deg = -1) const {\n        assert((*this)[0] == M(1));\n        if (deg\
    \ < 0) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n    }\n    Poly sqrt(int deg = -1) const {\n        assert((*this)[0]\
    \ == M(1));\n        if (deg == -1) deg = this->size();\n        Poly res({M(1)});\n\
    \        M inv2 = M(1) / M(2);\n        for (int i = 1; i < deg; i <<= 1) {\n\
    \            res = (res + pre(i << 1) * res.inv(i << 1)) * inv2;\n        }\n\
    \        return res.pre(deg);\n    }\n    Poly exp(int deg = -1) {\n        assert((*this)[0]\
    \ == M(0));\n        if (deg < 0) deg = this->size();\n        Poly res({M(1)});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            res = (res * (pre(i\
    \ << 1) + M(1) - res.log(i << 1))).pre(i << 1);\n        }\n        return res.pre(deg);\n\
    \    }\n    Poly pow(long long k, int deg = -1) const {\n        if (deg < 0)\
    \ deg = this->size();\n        for (int i = 0; i < this->size(); i++) {\n    \
    \        if ((*this)[i] == M(0)) continue;\n            if (k * i > deg) return\
    \ Poly(deg, M(0));\n            M inv = M(1) / (*this)[i];\n            Poly res\
    \ = (((*this * inv) >> i).log() * k).exp() * (*this)[i].pow(k);\n            res\
    \ = (res << (i * k)).pre(deg);\n            if (res.size() < deg) res.resize(deg,\
    \ M(0));\n            return res;\n        }\n        return *this;\n    }\n \
    \   Poly pow_mod(long long k, const Poly& mod) const {\n        Poly x(*this),\
    \ res = {M(1)};\n        while (k > 0) {\n            if (k & 1) res = res * x\
    \ % mod;\n            x = x * x % mod;\n            k >>= 1;\n        }\n    \
    \    return res;\n    }\n    Poly linear_mul(const M& a, const M& b) {\n     \
    \   Poly res(this->size() + 1);\n        for (int i = 0; i < this->size() + 1;\
    \ i++) {\n            res[i] = (i - 1 >= 0 ? (*this)[i - 1] * a : M(0)) + (i <\
    \ this->size() ? (*this)[i] * b : M(0));\n        }\n        return res;\n   \
    \ }\n    Poly linear_div(const M& a, const M& b) {\n        Poly res(this->size()\
    \ - 1);\n        M inv_b = M(1) / b;\n        for (int i = 0; i + 1 < this->size();\
    \ i++) {\n            res[i] = ((*this)[i] - (i - 1 >= 0 ? res[i - 1] * a : M(0)))\
    \ * inv_b;\n        }\n        return res;\n    }\n    Poly sparse_mul(const M&\
    \ c, const M& d) {\n        Poly res(*this);\n        res.resize(this->size()\
    \ + d, M(0));\n        for (int i = 0; i < this->size(); i++) {\n            res[i\
    \ + d] += (*this)[i] * c;\n        }\n        return res;\n    }\n    Poly sparse_div(const\
    \ M& c, const M& d) {\n        Poly res(*this);\n        for (int i = 0; i < res.size()\
    \ - d; i++) {\n            res[i + d] -= res[i] * c;\n        }\n        return\
    \ res;\n    }\n    M operator()(const M& x) const {\n        M res = 0, power\
    \ = 1;\n        for (int i = 0; i < this->size(); i++, power *= x) {\n       \
    \     res += (*this)[i] * power;\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Formal Power Series\n\
    \ * @docs docs/polynomial/FormalPowerSeries.md\n */\ntemplate <typename M> struct\
    \ FormalPowerSeries : vector<M> {\n    using vector<M>::vector;\n    using Poly\
    \ = FormalPowerSeries;\n    using MUL = function<Poly(Poly, Poly)>;\n    static\
    \ MUL& get_mul() {\n        static MUL mul = nullptr;\n        return mul;\n \
    \   }\n    static void set_mul(MUL f) { get_mul() = f; }\n    void shrink() {\n\
    \        while (this->size() && this->back() == M(0)) this->pop_back();\n    }\n\
    \    Poly pre(int deg) const { return Poly(this->begin(), this->begin() + min((int)this->size(),\
    \ deg)); }\n    Poly operator+(const M& v) const { return Poly(*this) += v; }\n\
    \    Poly operator+(const Poly& p) const { return Poly(*this) += p; }\n    Poly\
    \ operator-(const M& v) const { return Poly(*this) -= v; }\n    Poly operator-(const\
    \ Poly& p) const { return Poly(*this) -= p; }\n    Poly operator*(const M& v)\
    \ const { return Poly(*this) *= v; }\n    Poly operator*(const Poly& p) const\
    \ { return Poly(*this) *= p; }\n    Poly operator/(const Poly& p) const { return\
    \ Poly(*this) /= p; }\n    Poly operator%(const Poly& p) const { return Poly(*this)\
    \ %= p; }\n    Poly& operator+=(const M& v) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += v;\n        return *this;\n    }\n    Poly& operator+=(const\
    \ Poly& p) {\n        if (p.size() > this->size()) this->resize(p.size());\n \
    \       for (int i = 0; i < p.size(); i++) (*this)[i] += p[i];\n        return\
    \ *this;\n    }\n    Poly& operator-=(const M& v) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= v;\n        return *this;\n    }\n \
    \   Poly& operator-=(const Poly& p) {\n        if (p.size() > this->size()) this->resize(p.size());\n\
    \        for (int i = 0; i < p.size(); i++) (*this)[i] -= p[i];\n        return\
    \ *this;\n    }\n    Poly& operator*=(const M& v) {\n        for (int i = 0; i\
    \ < this->size(); i++) (*this)[i] *= v;\n        return *this;\n    }\n    Poly&\
    \ operator*=(const Poly& p) {\n        if (this->empty() || p.empty()) {\n   \
    \         this->clear();\n            return *this;\n        }\n        assert(get_mul()\
    \ != nullptr);\n        return *this = get_mul()(*this, p);\n    }\n    Poly&\
    \ operator/=(const Poly& p) {\n        if (this->size() < p.size()) {\n      \
    \      this->clear();\n            return *this;\n        }\n        int n = this->size()\
    \ - p.size() - 1;\n        return *this = (rev().pre(n) * p.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n    Poly& operator%=(const Poly& p) { return *this -= *this / p * p; }\n\
    \    Poly operator<<(const int deg) {\n        Poly res(*this);\n        res.insert(res.begin(),\
    \ deg, M(0));\n        return res;\n    }\n    Poly operator>>(const int deg)\
    \ {\n        if (this->size() <= deg) return {};\n        Poly res(*this);\n \
    \       res.erase(res.begin(), res.begin() + deg);\n        return res;\n    }\n\
    \    Poly operator-() const {\n        Poly res(this->size());\n        for (int\
    \ i = 0; i < this->size(); i++) res[i] = -(*this)[i];\n        return res;\n \
    \   }\n    Poly rev(int deg = -1) const {\n        Poly res(*this);\n        if\
    \ (~deg) res.resize(deg, M(0));\n        reverse(res.begin(), res.end());\n  \
    \      return res;\n    }\n    Poly diff() const {\n        Poly res(max(0, (int)this->size()\
    \ - 1));\n        for (int i = 1; i < this->size(); i++) res[i - 1] = (*this)[i]\
    \ * M(i);\n        return res;\n    }\n    Poly integral() const {\n        Poly\
    \ res(this->size() + 1);\n        res[0] = M(0);\n        for (int i = 0; i <\
    \ this->size(); i++) res[i + 1] = (*this)[i] / M(i + 1);\n        return res;\n\
    \    }\n    Poly inv(int deg = -1) const {\n        assert((*this)[0] != M(0));\n\
    \        if (deg < 0) deg = this->size();\n        Poly res({M(1) / (*this)[0]});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            res = (res + res - res\
    \ * res * pre(i << 1)).pre(i << 1);\n        }\n        return res.pre(deg);\n\
    \    }\n    Poly log(int deg = -1) const {\n        assert((*this)[0] == M(1));\n\
    \        if (deg < 0) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n    }\n    Poly sqrt(int deg = -1) const {\n        assert((*this)[0]\
    \ == M(1));\n        if (deg == -1) deg = this->size();\n        Poly res({M(1)});\n\
    \        M inv2 = M(1) / M(2);\n        for (int i = 1; i < deg; i <<= 1) {\n\
    \            res = (res + pre(i << 1) * res.inv(i << 1)) * inv2;\n        }\n\
    \        return res.pre(deg);\n    }\n    Poly exp(int deg = -1) {\n        assert((*this)[0]\
    \ == M(0));\n        if (deg < 0) deg = this->size();\n        Poly res({M(1)});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            res = (res * (pre(i\
    \ << 1) + M(1) - res.log(i << 1))).pre(i << 1);\n        }\n        return res.pre(deg);\n\
    \    }\n    Poly pow(long long k, int deg = -1) const {\n        if (deg < 0)\
    \ deg = this->size();\n        for (int i = 0; i < this->size(); i++) {\n    \
    \        if ((*this)[i] == M(0)) continue;\n            if (k * i > deg) return\
    \ Poly(deg, M(0));\n            M inv = M(1) / (*this)[i];\n            Poly res\
    \ = (((*this * inv) >> i).log() * k).exp() * (*this)[i].pow(k);\n            res\
    \ = (res << (i * k)).pre(deg);\n            if (res.size() < deg) res.resize(deg,\
    \ M(0));\n            return res;\n        }\n        return *this;\n    }\n \
    \   Poly pow_mod(long long k, const Poly& mod) const {\n        Poly x(*this),\
    \ res = {M(1)};\n        while (k > 0) {\n            if (k & 1) res = res * x\
    \ % mod;\n            x = x * x % mod;\n            k >>= 1;\n        }\n    \
    \    return res;\n    }\n    Poly linear_mul(const M& a, const M& b) {\n     \
    \   Poly res(this->size() + 1);\n        for (int i = 0; i < this->size() + 1;\
    \ i++) {\n            res[i] = (i - 1 >= 0 ? (*this)[i - 1] * a : M(0)) + (i <\
    \ this->size() ? (*this)[i] * b : M(0));\n        }\n        return res;\n   \
    \ }\n    Poly linear_div(const M& a, const M& b) {\n        Poly res(this->size()\
    \ - 1);\n        M inv_b = M(1) / b;\n        for (int i = 0; i + 1 < this->size();\
    \ i++) {\n            res[i] = ((*this)[i] - (i - 1 >= 0 ? res[i - 1] * a : M(0)))\
    \ * inv_b;\n        }\n        return res;\n    }\n    Poly sparse_mul(const M&\
    \ c, const M& d) {\n        Poly res(*this);\n        res.resize(this->size()\
    \ + d, M(0));\n        for (int i = 0; i < this->size(); i++) {\n            res[i\
    \ + d] += (*this)[i] * c;\n        }\n        return res;\n    }\n    Poly sparse_div(const\
    \ M& c, const M& d) {\n        Poly res(*this);\n        for (int i = 0; i < res.size()\
    \ - d; i++) {\n            res[i + d] -= res[i] * c;\n        }\n        return\
    \ res;\n    }\n    M operator()(const M& x) const {\n        M res = 0, power\
    \ = 1;\n        for (int i = 0; i < this->size(); i++, power *= x) {\n       \
    \     res += (*this)[i] * power;\n        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: polynomial/FormalPowerSeries.hpp
  requiredBy:
  - polynomial/StirlingSecond.hpp
  timestamp: '2021-01-19 14:32:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yukicoder/1302.test.cpp
  - test/yukicoder/3046.test.cpp
documentation_of: polynomial/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/polynomial/FormalPowerSeries.hpp
- /library/polynomial/FormalPowerSeries.hpp.html
title: Formal Power Series
---
## 概要
形式的冪級数(Formal Power Series)に関する諸演算を扱う.
- `operator+`：$P(x)+Q(x)$
- `operator-`：$P(x)-Q(x)$
- `operator*`：$P(x)Q(x)$
- `operator/`：$P(x)/Q(x)$
- `operator%`：$P(x)\%Q(x)$
- `operator<<(deg)`：$P(x)*x^{\deg}$
- `operator>>(deg)`：$P(x)/x^{\deg}$
- `diff()`：$P'(x)$
- `integral()`：$\int P(x)\mathrm{d}{x}$
- `inv()`：$1/P(x)$
- `log()`：$\log(P(x))=\int \frac{P'(x)}{P(x)}\mathrm{d}x$
- `sqrt()`：$\sqrt{P(x)}$
- `exp()`：$\exp(P(x))$
- `pow(k)`：$(P(x))^k$
- `pow_mod(k,mod)`：$(P(x))^k\%Q(x)$
- `linear_mul(a,b)`：$P(x)(ax+b)$
- `linear_div(a,b)`：$P(x)/(ax+b)$
- `sparse_mul(c,d)`：$P(x)(1+cx^d)$
- `sparse_div(c,d)`：$P(x)/(1+cx^d)$
- `operator(x)`：$P(x)$に実際に$x$を代入した際の値を返す.

## 計算量
- $P(x)+Q(x),P(x)-Q(x),P(x)*x^{\deg},P(x)/x^{\deg}$：$O(n)$
- $P(x)Q(x),P(x)/Q(x),P(x)\%Q(x)$：$O(n\log n)$
- $P'(x),\int P(x)\mathrm{d}{x}$：$O(n)$
- $1/P(x)$：$O(n\log n)$
- $\log(P(x))$：$O(n\log n)$
- $\sqrt{P(x)}$：$O(n\log n)$
- $\exp(P(x))$：$O(n\log n)$
- $(P(x))^k$：$O(n\log n)$
- $P(x)(ax+b),P(x)/(ax+b)$：$O(n)$
- $P(x)(1+cx^d),P(x)/(1+cx^d)$：$O(n+d)$

## 参照
[Operations on Formal Power Series - Codeforces](https://codeforces.com/blog/entry/56422)