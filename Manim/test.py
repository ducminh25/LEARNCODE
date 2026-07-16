from manim import *
import numpy as np

class GeometryProblem(Scene):
    def construct(self):
        # --- Cấu hình chung ---
        radius = 3
        # Chọn các góc sao cho tam giác ABC nhọn
        # A khoảng 110 độ, B khoảng 215 độ, C khoảng 325 độ
        angle_a = 110 * DEGREES
        angle_b = 215 * DEGREES
        angle_c = 325 * DEGREES

        # Hàm lấy tọa độ từ góc trên đường tròn
        def get_coords(angle):
            return radius * np.array([np.cos(angle), np.sin(angle), 0])

        # 1. Khởi tạo các điểm cơ bản
        O = ORIGIN
        A = get_coords(angle_a)
        B = get_coords(angle_b)
        C = get_coords(angle_c)

        # Tính toán các điểm phụ thuộc
        # Trực tâm H = A + B + C (đối với đường tròn đơn vị tâm O gốc tọa độ, tính chất Euler)
        # Tuy nhiên để tổng quát và chính xác với phép chiếu hình học:
        # D là hình chiếu của A lên BC
        line_bc = Line(B, C)
        D = line_bc.get_projection(A)
        
        # E là hình chiếu của B lên AC
        line_ac = Line(A, C)
        E = line_ac.get_projection(B)
        
        # F là hình chiếu của C lên AB
        line_ab = Line(A, B)
        F = line_ab.get_projection(C)

        # Giao điểm các đường cao là H
        # Lấy giao điểm của AD và BE
        line_ad_full = Line(A, D)
        line_be_full = Line(B, E)
        H = line_intersection(
            [A, D],
            [B, E]
        )

        # K là điểm đối xứng của A qua O (Đường kính AK)
        K = -A 

        # --- Tạo Mobjects (Đối tượng đồ họa) ---
        
        # Đường tròn tâm O
        circle = Circle(radius=radius, color=WHITE)
        dot_o = Dot(O, color=WHITE)
        label_o = MathTex("O").next_to(dot_o, DOWN, buff=0.1)

        # Tam giác ABC
        triangle = Polygon(A, B, C, color=BLUE)
        dot_a = Dot(A)
        dot_b = Dot(B)
        dot_c = Dot(C)
        
        label_a = MathTex("A").next_to(dot_a, UP)
        label_b = MathTex("B").next_to(dot_b, LEFT)
        label_c = MathTex("C").next_to(dot_c, RIGHT)

        # Các đường cao
        altitude_ad = Line(A, D, color=RED)
        altitude_be = Line(B, E, color=RED)
        altitude_cf = Line(C, F, color=RED)
        
        dot_d = Dot(D, radius=0.06, color=RED)
        dot_e = Dot(E, radius=0.06, color=RED)
        dot_f = Dot(F, radius=0.06, color=RED)
        dot_h = Dot(H, color=YELLOW)

        label_d = MathTex("D").next_to(dot_d, DOWN, buff=0.1)
        label_e = MathTex("E").next_to(dot_e, RIGHT, buff=0.1)
        label_f = MathTex("F").next_to(dot_f, LEFT, buff=0.1)
        label_h = MathTex("H").next_to(dot_h, UP + RIGHT, buff=0.05)

        # Ký hiệu vuông góc
        right_angle_d = RightAngle(Line(A, D), Line(B, C), length=0.2, quadrant=(-1,-1))
        right_angle_e = RightAngle(Line(B, E), Line(A, C), length=0.2, quadrant=(-1,-1))
        right_angle_f = RightAngle(Line(C, F), Line(A, B), length=0.2, quadrant=(1,-1))

        # Đường kính AK
        diameter_ak = Line(A, K, color=GREEN)
        dot_k = Dot(K, color=GREEN)
        label_k = MathTex("K").next_to(dot_k, DOWN)
        
        # Nối K với B và C (thường đi kèm để chứng minh BHCK là hình bình hành)
        line_kb = Line(K, B, color=GREEN_E, stroke_opacity=0.5)
        line_kc = Line(K, C, color=GREEN_E, stroke_opacity=0.5)

        # --- ANIMATION SCRIPT (Kịch bản diễn hoạt) ---

        # 1. Vẽ đường tròn tâm O
        self.play(Create(circle), FadeIn(dot_o), Write(label_o))
        self.wait(0.5)

        # 2. Vẽ tam giác ABC
        self.play(
            Create(triangle),
            FadeIn(Group(dot_a, dot_b, dot_c)),
            Write(Group(label_a, label_b, label_c))
        )
        self.wait(1)

        # 3. Kẻ các đường cao AD, BE, CF
        self.play(Create(altitude_ad), FadeIn(dot_d), Write(label_d))
        self.play(Create(right_angle_d))
        
        self.play(Create(altitude_be), FadeIn(dot_e), Write(label_e))
        self.play(Create(right_angle_e))

        self.play(Create(altitude_cf), FadeIn(dot_f), Write(label_f))
        self.play(Create(right_angle_f))
        
        # Hiện trực tâm H
        self.play(FadeIn(dot_h), Write(label_h))
        self.wait(1)

        # 4. Kẻ đường kính AK
        self.play(Create(diameter_ak))
        self.play(FadeIn(dot_k), Write(label_k))
        
        # Vẽ thêm các đường nối phụ (KB, KC) để làm đẹp hình
        self.play(Create(line_kb), Create(line_kc))
        
        self.wait(2)
