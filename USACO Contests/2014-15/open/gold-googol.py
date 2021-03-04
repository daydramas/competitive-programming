'''
This program takes $\mathcal{O}(N)$, 
but for some reason, it ACs the test cases.
'''
import sys

def ask(x):
	print(x)
	sys.stdout.flush()
	return list(map(int, input().split()))

def count(x):
	if x == 0:
		return 0
	a, b = ask(x)
	return 1 + count(a) + count(b);

ans = count(1)
print("Answer " + str(ans))
