fi = open("bsbb.inp","r")
n = int(fi.readline())
fi.close()

def cal(x):
    if (x == 1): return 1
    i = 2
    count_div = 1
    while (i*i <= x):
        d = 0
        while (x % i == 0):
            d += 1
            x = x // i
        count_div *= d + 1
        i += 1
    if (x > 1): count_div *= 2
    return count_div

ans = 0
for i in range(1,n):
    ans += cal(i)
fo = open("bsbb.out","w")
fo.write(str(ans))
fo.close()