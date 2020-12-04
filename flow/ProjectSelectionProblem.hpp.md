---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/Dinic.hpp
    title: Dinic
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/arc085_c.cpp
    title: test/atcoder/arc085_c.cpp
  - icon: ':warning:'
    path: test/codeforces/1404_E.cpp
    title: test/codeforces/1404_E.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/ProjectSelectionProblem.md
    document_title: Project Selection Problem
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/ProjectSelectionProblem.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Project Selection Problem\n * @docs docs/flow/ProjectSelectionProblem.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n#include \"../flow/Dinic.hpp\"\
    \n\ntemplate<typename T>\nstruct ProjectSelectionProblem{\n    int s,t;\n    T\
    \ sum=0;\n    const T inf=numeric_limits<T>::max()/2;\n    Dinic<T,true> D;\n\
    \    ProjectSelectionProblem(int n):s(n),t(n+1),D(n+2){}\n    void x_false_loss(int\
    \ x,T z){\n        D.add_edge(x,t,z);\n    }\n    void x_false_profit(int x,T\
    \ z){\n        sum+=z;\n        x_true_loss(x,z);\n    }\n    void x_true_loss(int\
    \ x,T z){\n        D.add_edge(s,x,z);\n    }\n    void x_true_profit(int x,T z){\n\
    \        sum+=z;\n        x_false_loss(x,z);\n    }\n    void x_false_y_true_loss(int\
    \ x,int y,T z){\n        D.add_edge(x,y,z);\n    }\n    void x_true_y_false_loss(int\
    \ x,int y,T z){\n        D.add_edge(y,x,z);\n    }\n    void x_true_y_true_profit(int\
    \ x,int y,T z){\n        sum+=z;\n        int w=D.add_vertex();\n        x_false_loss(w,z);\n\
    \        x_true_y_false_loss(w,x,inf);\n        x_true_y_false_loss(w,y,inf);\n\
    \    }\n    void x_false_y_false_profit(int x,int y,T z){\n        sum+=z;\n \
    \       int w=D.add_vertex();\n        x_true_loss(w,z);\n        x_false_y_true_loss(w,x,inf);\n\
    \        x_false_y_true_loss(w,y,inf);\n    }\n    T build(){\n        return\
    \ D.max_flow(s,t)-sum;\n    }\n};"
  dependsOn:
  - base.hpp
  - flow/Dinic.hpp
  isVerificationFile: false
  path: flow/ProjectSelectionProblem.hpp
  requiredBy:
  - test/atcoder/arc085_c.cpp
  - test/codeforces/1404_E.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2903.test.cpp
documentation_of: flow/ProjectSelectionProblem.hpp
layout: document
redirect_from:
- /library/flow/ProjectSelectionProblem.hpp
- /library/flow/ProjectSelectionProblem.hpp.html
title: Project Selection Problem
---
## 概要

## 計算量