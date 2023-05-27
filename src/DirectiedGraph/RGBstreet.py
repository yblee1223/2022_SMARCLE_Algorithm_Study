import sys

memo = [0] * 3
N = int(sys.stdin.readline())
for i in range(N):
    R, G, B = map(int, sys.stdin.readline().split())
    R += min(memo[1], memo[2])
    G += min(memo[0], memo[2])
    B += min(memo[0], memo[1])
    memo[0], memo[1], memo[2] = R, G, B
print(min(memo))

'''
8
71 39 44
32 83 55
51 37 63
89 29 100
83 58 11
65 13 15
47 25 29
60 66 19
'''