fi = open("phnt.inp","r")
n = int(fi.readline())
s = fi.readline()
fi.close()

def check(k):
    dic = {}
    for i in range(k,n+1):
        x = s[i-k:i]
        if (dic.get(x) != None):
            return False
        dic[x] = 1
    return True

ans = 0
l, r = 1, n
while (l <= r):
    mid = (l + r) // 2
    if (check(mid)):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

fo = open("phnt.out","w")
fo.write(str(ans))
fo.close()