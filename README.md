# README

## Sites

- [AtCoder](./AtCoder) ([site](https://atcoder.jp/), [profile](https://atcoder.jp/users/dongliu0426))
- [Codeforces](./Codeforces) ([site](http://codeforces.com/), [profile](https://codeforces.com/profile/lunchbox))
- [CSES](./CSES) ([site](https://cses.fi/problemset/), [profile](https://cses.fi/user/37667))
- [LeetCode](./LeetCode) ([site](https://leetcode.com/), [profile](https://leetcode.com/dongliu0426/))
- [USACO](./USACO) ([site](http://usaco.org/))

## `.zshrc`

```
co() { g++ -std=c++11 -o "${1%.*}" $1 -Wall -DLOCAL; }
run() { co $1 && ./${1%.*} & fg; }
```

*from https://usaco.guide/general/cpp-command*