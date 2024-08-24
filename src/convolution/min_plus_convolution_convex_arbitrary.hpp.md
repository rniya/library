---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/optimization/monotone_minima.hpp
    title: Monotone Minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n#include <cassert>\n#line 2 \"src/optimization/monotone_minima.hpp\"\n#include\
    \ <vector>\n\ntemplate <class Select> std::vector<int> monotone_minima(int n,\
    \ int m, const Select& select) {\n    std::vector<int> res(n);\n    auto dfs =\
    \ [&](auto self, int u, int d, int l, int r) -> void {\n        if (u == d) return;\n\
    \        int m = (u + d) >> 1;\n        int argmin = l;\n        for (int col\
    \ = l + 1; col < r; col++) {\n            if (select(m, argmin, col)) {\n    \
    \            argmin = col;\n            }\n        }\n        res[m] = argmin;\n\
    \        self(self, u, m, l, argmin + 1);\n        self(self, m + 1, d, argmin,\
    \ r);\n    };\n    dfs(dfs, 0, n, 0, m);\n    return res;\n}\n#line 4 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    int n = a.size(), m = b.size();\n\
    \    assert(n and m);\n    for (int i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i]\
    \ <= a[i + 2] - a[i + 1]);\n    auto f = [&](int i, int j) { return a[i - j] +\
    \ b[j]; };\n    auto select = [&](int i, int j, int k) {\n        if (i < k) return\
    \ false;\n        if (n <= i - j) return true;\n        return f(i, j) >= f(i,\
    \ k);\n    };\n    auto argmin = monotone_minima(n + m - 1, m, select);\n    std::vector<T>\
    \ c(n + m - 1);\n    for (int i = 0; i < n + m - 1; i++) c[i] = f(i, argmin[i]);\n\
    \    return c;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include \"../optimization/monotone_minima.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    int n = a.size(), m = b.size();\n\
    \    assert(n and m);\n    for (int i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i]\
    \ <= a[i + 2] - a[i + 1]);\n    auto f = [&](int i, int j) { return a[i - j] +\
    \ b[j]; };\n    auto select = [&](int i, int j, int k) {\n        if (i < k) return\
    \ false;\n        if (n <= i - j) return true;\n        return f(i, j) >= f(i,\
    \ k);\n    };\n    auto argmin = monotone_minima(n + m - 1, m, select);\n    std::vector<T>\
    \ c(n + m - 1);\n    for (int i = 0; i < n + m - 1; i++) c[i] = f(i, argmin[i]);\n\
    \    return c;\n}"
  dependsOn:
  - src/optimization/monotone_minima.hpp
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: src/convolution/min_plus_convolution_convex_arbitrary.hpp
layout: document
title: Min Plus Convolution (Convex and Arbitary)
---

## 入力

数列 $a, b$ 

ここで数列 $a$ は下に凸である．
すなわち，任意の $0 \leq i \lt N - 2$ に対して $a _ {i + 1} - a _ i \leq a _ {i + 2} - a _ {i + 1}$ が成立する．

2 つの数列の長さをそれぞれ $n, m$ とする．

## 出力

数列 $a$ と $b$ の畳み込み．
すなわち，

$$
c _ k = \min _ {i + j = k} (a _ i + b _ j)
$$

で定義される長さ $n + m - 1$ の数列 $c$．

## 計算量

時間計算量 $\mathrm{O}((n + m) \log (n + m))$

## 概要

$(n + m - 1) \times m$ 行列 $X$ を

$$
X _ {i, j} := a _ {i - j} + b _ j
$$

により定めたとき，$X$ は totally monotone であり，monotone minima（時間計算量では SMAWK algorithm に劣るが，実用上はこちらの方が高速なのでこちらを採用している）により各行の最小値，すなわち所望の数列 $c$ を計算することが可能となる．
ここで，$i \lt 0$ や $n \leq i$ に対する $a_i$ は $a$ の凸性を保つような十分大きい値を取るとする．

<details>
<summary>totally monotone であることの証明</summary>
<div>

$X$ の任意の $2$ 次正方部分行列が monotone であることを示せば良い．
$X$ の行 $i, i ^ \prime\ (i \lt i ^ \prime)$ 及び列 $j, j ^ \prime\ (j \lt j ^ \prime)$ を取り出した部分行列を考える．
$X _ {i, j} > X _ {i, j ^ \prime} \implies X _ {i ^ \prime, j} \gt X _ {i ^ \prime, j ^ \prime}$ を示せば十分だが，これは $i \lt i ^ \prime$ より，

$$
0 \lt X _ {i, j} - X _ {i, j ^ \prime} = a _ {i - j} - a _ {i - j ^ \prime} \leq a _ {i ^ \prime - j} - a _ {i ^ \prime - j ^ \prime} = X _ {i ^ \prime, j} - X _ {i ^ \prime, j ^ \prime}
$$

だから成立する．

$\blacksquare$

</div>
</details>

## 出題例
[The 2nd Universal Cup. Stage 3: Binjiang L. Partially Free Meal](https://contest.ucup.ac/contest/1358/problem/7523)