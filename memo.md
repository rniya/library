- [Burnside の補題 / Polya の定理](#burnside-の補題--polya-の定理)
    - [問題例](#問題例)
- [Lagrange の反転公式](#lagrange-の反転公式)
    - [問題例](#問題例-1)
- [Alien dp](#alien-dp)
    - [Links](#links)
    - [問題例](#問題例-2)
- [Monge 性](#monge-性)
    - [Links](#links-1)
    - [問題例](#問題例-3)
- [凸包](#凸包)
    - [問題例](#問題例-4)


## Burnside の補題 / Polya の定理
$n$ 個の要素の組 $(x_1, \dots, x_n)$ からなる有限集合を $X$，その置換の集合を $G$ とする．
$G$ の置換で一致するものを同一視した際の $X$ の相異なる要素の個数は
$$
\frac{1}{|G|} \sum_{g \in G} |\{x \in X \mid gx = x\}|
$$
に等しい．
#### 問題例
- [AtCoder Beginner Contest 198 F - Cube](https://atcoder.jp/contests/abc198/tasks/abc198_f)
- [AtCoder Beginner Contest 284 Ex - Count Unlabeled Graphs](https://atcoder.jp/contests/abc284/tasks/abc284_h)

## Lagrange の反転公式
形式的冪級数 $F(x), G(x)$ は逆関数の関係にあるとする（すなわち $F(G(x)) = G(F(x)) = x$ が成り立つ）．
$[x^0]F(x) = [x^0]G(x) = 0$ かつ $[x^1]F(x) \neq 0,\ [x^1]G(x) \neq 0$ が成り立つとき，
$$
[x^n]G(x) = \frac{1}{n} [x^{n - 1}] \left(\frac{x}{F(x)}\right)^n.
$$

#### 問題例
- [AtCoder Beginner Contest 222 H - Beautiful Binary Tree](https://atcoder.jp/contests/abc222/tasks/abc222_h)
- [Educational Codeforces Round 142 (Rated for Div. 2) F2. Graph Coloring (hard version)](https://codeforces.com/contest/1792/problem/F2)
  - [参考](https://codeforces.com/blog/entry/111835?#comment-996577)

## Alien dp

#### Links
- [Alien DP をざっくり理解する - sapphire15の日記](https://sapphire15.hatenablog.com/entry/2022/05/30/012835)
- [Monge グラフ上の $d$-辺最短路長を計算するアルゴリズム \| Kyopro Encyclopedia of Algorithms](https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge)
- [Aliens DP で辺の本数が区間で指定される場合 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2022/01/13/001217)
- [Incredibly beautiful DP optimization from $N^3$ to $N \log^2 N$ - Codeforces](https://codeforces.com/blog/entry/49691)

#### 問題例
- [AtCoder Beginner Contest 218 H - Red and Blue Lamps](https://atcoder.jp/contests/abc218/tasks/abc218_h)

## Monge 性

#### Links
- [SMAWK algorithm as an alternative for D&C optimization - Codeforces](https://codeforces.com/blog/entry/110844)

#### 問題例
- [The 1st Universal Cup. Stage 3: Poland I. Investors](https://qoj.ac/contest/1103/problem/5507?v=1)
  - 分割統治による高速化．

## 凸包
#### 問題例
- [The 1st Universal Cup. Stage 2: Hong Kong D. Shortest Path Query](https://qoj.ac/contest/1099/problem/5458?v=1)
  - 各頂点の状態としては凸包の頂点のみが重要となるが、$n \times n$ の格子点を頂点にもつ凸包の頂点数は $O(n^{2 / 3})$ で抑えられる（[参照](https://not522.hatenablog.com/entry/2016/09/24/154939)）．
- [The 1st Universal Cup. Stage 3: Poland B. Big Picture](https://qoj.ac/contest/1099/problem/5456?v=1)
  - 利益を考えると最終的な開店の仕方は凸包に一致する．