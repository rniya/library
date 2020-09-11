---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/DSL_2_I.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_I.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I</a>


## Depends on

* :question: <a href="../../../library/base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="../../../library/datastructure/LazySegmentTree.hpp.html">Lazy Segment Tree <small>(datastructure/LazySegmentTree.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    const int inf=1<<30;
    int n,q; cin >> n >> q;

    struct node{
        long long a; int b;
        node(long long a,int b):a(a),b(b){}
    };
    auto f=[](node a,node b){return node(a.a+b.a,a.b+b.b);};
    auto g=[](node a,long long x){return node(x!=inf?x*a.b:a.a,a.b);};
    auto h=[](long long a,long long b){return b;};
    LazySegmentTree<node,long long> seg(n,f,g,h,node(0,0),inf);
    vector<node> v(n,node(0,1));
    seg.build(v);

    for (;q--;){
        int c,s,t,x; cin >> c >> s >> t;
        if (!c){
            cin >> x;
            seg.update(s,t+1,x);
        } else cout << seg.query(s,t+1).a << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/LazySegmentTree.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
