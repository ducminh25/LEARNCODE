# Cho một list các số nguyên n phần tử lst được nhập từ bàn phím. Hãy viết chương trình python hiển thị ra màn hình số nhỏ nhất trong list vừa nhập.
n = int(input('So phan tu cua danh sach: '))
lst = []

for i in range(n):
    num = int(input('Nhap phan tu thu ' + str(i+1) + ': '))
    lst.append(num)

gtnn = lst[0]

for phantu in lst:
    if phantu < gtnn:
        gtnn = phantu
print('GTNN cua danh sach la:', gtnn)