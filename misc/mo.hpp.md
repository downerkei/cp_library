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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/cp_library/cp_library',\
    \ '-fpreprocessed', '-dD', '-E', '/home/runner/work/cp_library/cp_library/misc/mo.hpp']'\
    \ returned non-zero exit status 1.\n"
  code: "void mo() {\n    int B = W / sqrt(Q);\n\_ \_ vector<int> ord(Q);\n\_ \_ iota(ord.begin(),\
    \ ord.end(), 0);\n\_ \_ sort(ord.begin(), ord.end(), [&](int i, int j) {\n\t\_\
    \ \_ // \u30D6\u30ED\u30C3\u30AF\u304C\u9055\u3046\u306A\u3089\uFF0C\u5C0F\u3055\
    \u3044\u65B9\u304B\u3089\n\_ \_ \_ \_ if(L[i] / B != L[j] / B) return L[i] / B\
    \ < L[j] / B;\n\_ \_ \_ \_ \n\_ \_ \_ \_ // \u30D6\u30ED\u30C3\u30AF\u304C\u540C\
    \u3058\u306A\u3089\uFF0C\u4E0A(\u3082\u3057\u304F\u306F\u4E0B)\u304B\u3089\n\_\
    \ \_ \_ \_ if((L[i] / B) % 2) return R[i] > R[j];\n\_ \_ \_ \_ return R[i] < R[j];\n\
    \_ \_ });\n\_ \_ \n\_ \_ int cur_l = 0, cur_r = 0;\n\_ \_ for(int i : ord) {\n\
    \t\twhile(cur_l > L[i]) add_l(--l);\n\t\twhile(cur_l < L[i]) rem_l(l++);\n\t\t\
    while(cur_r > R[i]) rem_r(--r);\n\t\twhile(cur_r < R[i]) add_r(r++);\n\t\t\n\t\
    \tans[i] = calc();\n\_ \_ }\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/mo.hpp
layout: document
redirect_from:
- /library/misc/mo.hpp
- /library/misc/mo.hpp.html
title: misc/mo.hpp
---
