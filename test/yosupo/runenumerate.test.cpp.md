---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/run_enumerate.hpp
    title: Run Enumerate
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/run_enumerate.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n\n#include\
    \ <iostream>\n#include \"string/run_enumerate.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    std::string S;\n    std::cin >> S;\n\
    \n    auto res = run_enumerate::enumerate(S);\n    std::sort(res.begin(), res.end());\n\
    \    std::cout << res.size() << '\\n';\n    for (auto [t, l, r] : res) std::cout\
    \ << t << ' ' << l << ' ' << r << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/string/run_enumerate.hpp
  isVerificationFile: true
  path: test/yosupo/runenumerate.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/runenumerate.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/runenumerate.test.cpp
- /verify/test/yosupo/runenumerate.test.cpp.html
title: test/yosupo/runenumerate.test.cpp
---