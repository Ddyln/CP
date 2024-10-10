k = int(input())
arr = list(map(int, input().split()))
n = 1
for i in range(k):
    n *= arr[i]
c = int(input())
c %= n
for x in range(1, 1000001):
    if c == ((x * x) % n * x) % n:
        print(x)
        break