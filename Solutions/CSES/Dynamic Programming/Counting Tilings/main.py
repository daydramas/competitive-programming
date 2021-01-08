import math

def SQ(x):
    return x*x

K,N = map(int,input().split())
res = 1
if N%2 and K%2:
    print("0")
else:
    n = N // 2
    k = K // 2
    mod = (10 ** 9 + 7)
    res = 1
    for i in range(1, n+1):
        for j in range(1, k+1):
            t1 = SQ( math.cos(math.pi * i / (N+1)) )
            t2 = SQ( math.cos(math.pi * j / (K+1)) )
            res = res * ( 4.0 * t1 + 4.0 * t2)
            while res >= mod:
                res = res - mod
    ans = int(math.floor(res)) % mod
    print(ans)