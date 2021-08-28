n = int(input().strip())
for i in range(n):
    a, b, c = map(int, input().strip().split())
    if a + b > c:
        print("Case #{}: true".format(i + 1))
    else:
        print("Case #{}: false".format(i + 1))
