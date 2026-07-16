# Cho một list các số nguyên n phần tử lst được nhập vào từ bàn phím, bạn hãy viết chương trình hiển thị ra màn hình một list chứa các số số lẻ trong list vừa nhập.
n = int(input("Nhập số phần tử n: "))
lst = []

for i in range(n):
    item = int(input(f"Nhập phần tử thứ {i+1}: "))
    lst.append(item)

odd = []

for item in lst:
    if item % 2 == 1:
        odd.append(item)

print(f"List chứa các số lẻ là: {odd}")