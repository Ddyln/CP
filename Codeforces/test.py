def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid][0] == target:
            return arr[mid][1]
        elif arr[mid][0] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

n = int(input())
A = input().strip()
A += ' '
sz = len(A)
num, cnt, arr = 0, 0, []

for i in range(len(A)):
    if A[i] == ' ':
        if len(arr) == 0 or arr[-1][0] != num:
            arr.append([num, cnt])
        else:
            arr[-1][1] = cnt
        num = 0
        cnt += 1
    else:
        num = num * 10 + int(A[i])

n = int(input())
A = input().strip()
A += ' '
num, mp = 0, {}
for i in range(len(A)):
    if A[i] == ' ':
        if num not in mp:
            mp[num] = binary_search(arr, num)
        print(mp[num])
        num = 0
    else:
        num = num * 10 + int(A[i])