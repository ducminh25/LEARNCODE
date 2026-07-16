s = input("Nhập chuỗi s: ")
if len(s) < 2:
    result = ""
else:
    result = s[:2] + s[-2:]
print("Chuỗi kết quả là:", result)