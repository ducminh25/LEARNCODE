# Cho một list các số nguyên n phần tử lst được nhập vào từ bàn phím, bạn hãy biết chương trình tính tổng các phẩn tử trong list vừa nhập.
n = int(input("So phan tu cua danh sach: "))
lst=[]
for i in range(n):
    nhapvao = int(input("Nhap phan tu thu" + str(i+1) + ":"))
    lst.append(nhapvao)

tong = 0
for value in lst:
    tong += value

print("Tổng các phần tử trong danh sách là:", tong)