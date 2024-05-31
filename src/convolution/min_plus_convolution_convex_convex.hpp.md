---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_plus_convolution_convex_convex.test.cpp
    title: test/yosupo/min_plus_convolution_convex_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/convolution/min_plus_convolution_convex_convex.hpp\"\
    \n#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<T>\
    \ min_plus_convolution_convex_convex(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = a.size(), m = b.size();\n    assert(n and m);\n    for (int\
    \ i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);\n   \
    \ for (int i = 0; i + 2 < m; i++) assert(b[i + 1] - b[i] <= b[i + 2] - b[i + 1]);\n\
    \    std::vector<T> c(n + m - 1);\n    c[0] = a[0] + b[0];\n    for (int i = 0,\
    \ j = 0, k = 1; k < n + m - 1; k++) {\n        if (j == m - 1 or (i < n - 1 and\
    \ a[i + 1] + b[j] < a[i] + b[j + 1]))\n            c[k] = a[++i] + b[j];\n   \
    \     else\n            c[k] = a[i] + b[++j];\n    }\n    return c;\n}\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<T>\
    \ min_plus_convolution_convex_convex(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = a.size(), m = b.size();\n    assert(n and m);\n    for (int\
    \ i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);\n   \
    \ for (int i = 0; i + 2 < m; i++) assert(b[i + 1] - b[i] <= b[i + 2] - b[i + 1]);\n\
    \    std::vector<T> c(n + m - 1);\n    c[0] = a[0] + b[0];\n    for (int i = 0,\
    \ j = 0, k = 1; k < n + m - 1; k++) {\n        if (j == m - 1 or (i < n - 1 and\
    \ a[i + 1] + b[j] < a[i] + b[j + 1]))\n            c[k] = a[++i] + b[j];\n   \
    \     else\n            c[k] = a[i] + b[++j];\n    }\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_convex.hpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/min_plus_convolution_convex_convex.test.cpp
documentation_of: src/convolution/min_plus_convolution_convex_convex.hpp
layout: document
redirect_from:
- /library/src/convolution/min_plus_convolution_convex_convex.hpp
- /library/src/convolution/min_plus_convolution_convex_convex.hpp.html
title: src/convolution/min_plus_convolution_convex_convex.hpp
---