
def solve():
    n = int(input())
    a = list(map(int, input().split()))

    for i in range(n):
        max_count = 0
        for k in range(-100, 101):
            count = 0
            for j in range(i + 1, n):
                if abs(a[i] - k) > abs(a[j] - k):
                    count += 1
            max_count = max(max_count, count)
        print(max_count, end=" ")
    print()

t = int(input())
for _ in range(t):
    solve()
