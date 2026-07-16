def max_of_4(a, b, c, d):
    if a > b:
        max = a
    else: max = b
    if max < c:
        max = c
        if max<d:
            max = d
    return max

a = int(input())
b = int(input())
c = int(input())
d = int(input())

result = max_of_4(a, b, c, d)
print(f"Số lớn nhất trong 4 số là: {result}\n")