---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/linearalgebra/characteristic_polynomial.hpp
    title: Characteristic Polynomial
  - icon: ':question:'
    path: src/util/modint.hpp
    title: src/util/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/characteristic_polynomial
    links:
    - https://judge.yosupo.jp/problem/characteristic_polynomial
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linearalgebra/characteristic_polynomial.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/characteristic_polynomial\"\
    \n\n#include \"linearalgebra/characteristic_polynomial.hpp\"\n#include \"util/modint.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    std::vector<std::vector<mint>>\
    \ a(N, std::vector<mint>(N));\n    for (int i = 0; i < N; i++) {\n        for\
    \ (int j = 0; j < N; j++) {\n            std::cin >> a[i][j];\n        }\n   \
    \ }\n\n    auto p = characteristic_polynomial(a);\n    for (int i = 0; i <= N;\
    \ i++) std::cout << p[i] << (i == N ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/linearalgebra/characteristic_polynomial.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/characteristic_polynomial.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/characteristic_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/characteristic_polynomial.test.cpp
- /verify/test/yosupo/characteristic_polynomial.test.cpp.html
title: test/yosupo/characteristic_polynomial.test.cpp
---