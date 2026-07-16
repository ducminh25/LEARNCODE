danh_sach_hoc_vien = {}

def them_hoc_vien():
    while True:
        try:
            ten = input("Nhập tên học viên: ")
            tuoi = int(input("Nhập tuổi học viên: "))
            diem_so = float(input("Nhập điểm số học viên: "))
            if ten in danh_sach_hoc_vien:
                print("Lỗi: Học viên này đã có trong danh sách.")
            else:
                danh_sach_hoc_vien [ten] = [ten, tuoi, diem_so]
                print("Đã thêm học viên mới vào danh sách.")
                break
            break
        except ValueError: print("Bạn đang nhập sai kiểu dữ liệu. Hãy nhập lại cho đúng.")
            
def xem_danh_sach():
    if len(danh_sach_hoc_vien) == 0:
        print("Chưa có học viên nào trong danh sách.")
    else:
        print("Danh sách các học viên:")
        for [ten, tuoi], diem_so in danh_sach_hoc_vien.items():
            print(f"- Tên: {ten}, Tuổi: {tuoi}, Điểm số: {diem_so}")

def diem_trung_binh():
    if len(danh_sach_hoc_vien) == 0:
        print("Chưa có học viên nào trong danh sách.")
    else: 
        tong_diem = 0
        for i, [ten, diem_so] in danh_sach_hoc_vien.items():
            tong_diem += diem_so
        diem_trung_binh = tong_diem / len(danh_sach_hoc_vien)
        print(f"Điểm trung bình của tất cả các học viên là: {diem_trung_binh}")

def hv_diem_cao_nhat():
    if len(danh_sach_hoc_vien) == 0:
        print("Chưa có học viên nào trong danh sách.")
    else:
        maximum = 0
        max_name = ""
        for ten, [tuoi, diem_so] in danh_sach_hoc_vien.items():
            if diem_so > maximum:
                maximum = diem_so
                max_name = ten
        print(f"Học viên có điểm cao nhất là: {max_name} với số điểm {maximum}")

def delete_hv():
    if len(danh_sach_hoc_vien) == 0:
        print("Chưa có học viên nào trong danh sách.")
    else:
        ten = input("Nhập tên học viên: ")
        if ten in danh_sach_hoc_vien:
            del danh_sach_hoc_vien[ten]
        else: print("Học viên không tồn tại trong danh sách.")

def menu():
    print("___________________________________________")
    print("Chọn chức năng:")
    print("1. Thêm học viên mới vào danh sách.")
    print("2. Xem danh sách học viên.")
    print("3. Tính điểm trung bình.")
    print("4. Tìm học viên có điểm số cao nhất.")
    print("5. Xóa học viên.")
    print("6. Thoát chương trình.")
    print("___________________________________________")

while True:
    menu()
    while True:
        try:
            lua_chon = int(input("Nhập lựa chọn của bạn (1-6): "))
            if lua_chon in range(1, 7):
                break
            else:
                print("Lỗi: Lựa chọn không hợp lệ. Vui lòng nhập lại.")
        except ValueError:
            print("Lỗi: Bạn phải nhập một số nguyên. Vui lòng nhập lại.")
            
    if lua_chon == 1:
        them_hoc_vien()
    if lua_chon == 2:
        xem_danh_sach()
    if lua_chon == 3:
        diem_trung_binh()
    if lua_chon == 4:
        hv_diem_cao_nhat()
    if lua_chon == 5:
        delete_hv()
    if lua_chon == 6:
        break
