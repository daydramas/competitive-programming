# can't belive i'm using python :)

def f(n):
    i=1
    j=1
    while (n > 9*i*j):
        n -= 9*i*j;
        j *= 10;
        i += 1
    k = j + (n-1)//i
    j = (n-1) % i
    while j<i-1:
        k = k//10
        j+=1
    return k % 10;

n = int(input())
for i in range(n):
    x = int(input())
    print(f(x))