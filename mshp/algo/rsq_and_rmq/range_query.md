# Range query

Data structures for solving RSQ/RMQ problems:

  - Prefix sums
  - SQRT-decomposition
  - Segment tree
  - Fenwick tree

# Range sum query (RSQ)

|  Property    | prefix | segment | fenwick | sqrt |
| ------------ | ------ | ------- | ------- | ---- |
| memory       |    N   |    4N   |    N    | N+√N |
| time(update) |    N   |  log(N) |  log(N) |   2  |
| time(query)  |    1   |  log(N) |  log(N) |  √N  |

# Range max query (RMQ)

|  Property    | sqrt | sqrt+/- | segment |
| ------------ | ---- | ------- | ------- |
| memory       | N+√N |  N+√N   |    4N   |
| time(update) |   2  |   √N    |  log(N) |
| time(query)  |  √N  |   √N    |  log(N) |

  - sqrt - SQRT-decomposition with increments only.
  - sqrt+/- - SQRT-decomposition with increments and decrements.
