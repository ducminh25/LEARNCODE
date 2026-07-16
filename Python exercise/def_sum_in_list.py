def sum_list(list):
    total = 0
    for num in list:
        total += num
    return total

n = int(input("Nhập số lượng phần tử: "))
lst = []
for i in range(n):
    num = int(input(f"Nhập phần tử thứ {i+1}: "))
    lst.append(num)
sum = sum_list(lst)
print(f"Tổng các phần tử trong danh sách là: {sum}")