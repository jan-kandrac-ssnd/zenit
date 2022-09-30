a = list(map(int, input().split()))
b = max(a)
print(b if b < 0 else sum(filter(lambda x: x > 0, a)))
