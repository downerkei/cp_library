---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/timer.hpp\"\nstruct Timer {\n    chrono::system_clock::time_point\
    \ start;\n\n    Timer() { reset(); }\n    void reset() { start = chrono::system_clock::now();\
    \ }\n\n    // return millisecond\n    inline double get_second() {\n        chrono::system_clock::time_point\
    \ now = chrono::system_clock::now();\n        return (double) chrono::duration_cast<chrono::milliseconds>\
    \ (now - start).count();\n    }\n};\n"
  code: "struct Timer {\n    chrono::system_clock::time_point start;\n\n    Timer()\
    \ { reset(); }\n    void reset() { start = chrono::system_clock::now(); }\n\n\
    \    // return millisecond\n    inline double get_second() {\n        chrono::system_clock::time_point\
    \ now = chrono::system_clock::now();\n        return (double) chrono::duration_cast<chrono::milliseconds>\
    \ (now - start).count();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy: []
  timestamp: '2024-10-14 14:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
