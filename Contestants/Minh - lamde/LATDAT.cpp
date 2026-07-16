#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

// Dùng struct để code dễ đọc hơn
struct LatDat {
    int w, h;
    int id; // Giữ lại id ban đầu để debug nếu cần
};

// Hàm so sánh để sắp xếp
bool compareLatDat(const LatDat& a, const LatDat& b) {
    if (a.w != b.w) {
        return a.w < b.w; // Sắp xếp theo chiều rộng tăng dần
    }
    return a.h > b.h; // Nếu chiều rộng bằng nhau, sắp xếp theo chiều cao giảm dần
}

int main() {
    // Mở file input và output
    std::ifstream inFile("LATDAT.INP");
    std::ofstream outFile("LATDAT.OUT");

    if (!inFile.is_open()) {
        std::cerr << "Khong the mo file LATDAT.INP" << std::endl;
        return 1;
    }

    int m;
    inFile >> m;

    std::vector<LatDat> dolls(m);
    for (int i = 0; i < m; ++i) {
        inFile >> dolls[i].w >> dolls[i].h;
        dolls[i].id = i;
    }

    // Bước 1: Sắp xếp các con lật đật
    std::sort(dolls.begin(), dolls.end(), compareLatDat);

    // Bước 2: Áp dụng thuật toán tham lam
    // multiset sẽ tự động sắp xếp các phần tử và cho phép truy cập hiệu quả
    std::multiset<int> chains; // Lưu chiều cao của các con lật đật ngoài cùng

    for (int i = 0; i < m; ++i) {
        int current_h = dolls[i].h;

        // Tìm chuỗi có con lật đật ngoài cùng lớn nhất mà vẫn nhỏ hơn con hiện tại
        // lower_bound(h) sẽ tìm phần tử đầu tiên >= h
        auto it = chains.lower_bound(current_h);

        if (it == chains.begin()) {
            // Không có con nào nhỏ hơn con hiện tại (it trỏ đến đầu)
            // -> Bắt đầu một chuỗi mới
            chains.insert(current_h);
        } else {
            // Có ít nhất một con nhỏ hơn con hiện tại
            // Lựa chọn tham lam: chọn con lớn nhất trong số các con nhỏ hơn
            // chính là con ngay trước `it`
            --it;
            // Thay thế con đó bằng con hiện tại (lồng vào)
            chains.erase(it);
            chains.insert(current_h);
        }
    }

    // Bước 3: Kết quả là số lượng chuỗi còn lại
    outFile << chains.size() << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}
