#include <bits/stdc++.h>






/*
Cho số nguyên dương n và dãy số a1, a2, ..., an. Gọi đoạn con [u, v] của dãy là các phần tử liên tiếp a[u], a[u+1], ..., a[v](u ≤ v). 
Dễ thấy đoạn con [u, v] có độ dài là v-u+1 và giá trị trung bình là: a[u] + a[u+1] + ... + a[v]/(v-u+1).
Yêu cầu: Cho số nguyên k, hãy xác định đoạn con có độ dài không nhỏ hơn k có giá trị trung bình lớn nhất.
Dữ liệu vào: Từ file văn bản CAU4.INP gồm:
	Dòng đầu chứa 2 số nguyên dương n, k
	Dòng thứ 2 chứa n số nguyên A_1,A_2,…,A_N  (|A_i |≤10^9,1≤i≤n), các số được phân cách nhau bởi dấu cách.
Kết quả: Ghi ra file CAU4.OUT một số thực duy nhất là giá trị trung bình của đoạn con tìm được. Kết quả đưa ra lấy 3 chữ số thập phân sau dấu phẩy. 

*/