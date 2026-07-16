# Phương trình bậc nhất:
print("Nhap so a va b cho phuong trinh bac nhat dang ax + b = 0: ")
a = int(input())
b = int(input())
if a==0:
    if a==b:
        print("Phuong trinh co vo so nghiem. Phuong trinh co dang: 0 = 0")
    else: print(f"Phuong trinh vo nghiem. Phuong trinh co dang: {b} = 0")
else: print(f"Phuong trinh co dang {a}x + {b} = 0. x = ",-b/a)