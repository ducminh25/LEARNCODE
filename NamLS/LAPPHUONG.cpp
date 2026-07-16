/*
Sub 1: (trâu) dùng hàm cbrt để check
Sub 2: 
    - Đoạn con từ i đến j có tích là lập phương: a [i] * a[i + 1] * ... * a [j] là số lập phương
    Số lớn quá k tính được tích --> phải lưu các phân tích thành tích thừa số nguyên tố.
    p1 ^ q1 * p2 ^ q2 * ... * pk ^ qk thì nó là số lập phương khi nào? Khi q đều chia hết cho 3.
    Khi lưu tích thừa số nguyên tố, ta chỉ quan tâm giá trị q % 3. Đoạn có tích lập phương thì có toàn bộ số mũ = 0.
    - Giả sử tích a [1] * a[2] * ... * a [j] = p1 ^ q1 * p2 ^ q2 * ... * pk ^ qk
    và a [1] * a [2] * ... * a [i - 1] = p1 ^ t1 * p2 ^ t2 * ... * pk ^ tk
    thì a [i] * a [i + 1] * ... * a [j] là lập phương khi q1 == t1 && q2 == t2 && ... && qk == tk
    - Đếm số cặp (i,j) thỏa mãn đề bài:
        Cho j chạy từ 1 đến n: 
        Phân tích thừa số nguyên tố a[j] và ghép vào tích tsnt của dãy từ a[1] đến a[j].
        Số các số i thỏa mãn (ghép được với j) là số các dãy q1, q2, …qk đã xuất hiện trước đó.
        Ta cho cả vector q vào map để lưu xem vector q đã xuất hiện bao nhiêu lần, mỗi lần xuất hiện là 1 số i thỏa mãn để ghép với j.
*/