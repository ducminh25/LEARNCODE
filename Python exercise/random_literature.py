import random
import os

authors = input()
draft = {'Mùa xuân nho nhỏ': 'Thanh Hải', 'Tây Tiến': 'Quang Dũng', 'Việt Bắc': 'Tố Hữu', 'Đất Nước': 'Nguyễn Khoa Điềm', 'Tiếng Hát Con Tàu': 'Chế Lan Viên', 'Đò Lèn': 'Nguyễn Duy',
           'Sóng': 'Xuân Quỳnh', 'Đàn Ghi-ta-lor-ca': 'Thanh Thảo', 'Người Lái Đò Sông Đà': 'Nguyễn Tuân',
           'Ai Đặt Tên Cho Dòng Sông': 'Nguyễn Huy Tưởng', 'Vợ Chồng A Phủ': 'Tô Hoài',
           'Vợ Nhặt': 'Kim Lân', 'Rừng Xà Nu': 'Nguyễn Trung Thành', 'Những Đứa Con Trong Gia Đình': 'Nguyễn Thi',
           'Chiếc Thuyền Ngoài Xa': 'Nguyễn Minh Châu', 'Hồn Trương Ba, Da Hàng Thịt': 'Lưu Quang Vũ',
           'Dọn Về Làng': 'Nông Quốc Chấn', 'Thuốc': 'Lỗ Tấn', 'Số Phận Con Người': 'Sô-lô-khôp',
           'Ông Già Và Biển Cả': 'E. Hê-minh-uê'
           }


def generate_quiz_files(num_students: int = 10):
    if not os.path.exists('./bo_cau_hoi'):
        os.makedirs('./bo_cau_hoi')
    if not os.path.exists('./dap_an'):
        os.makedirs('./dap_an')
    for quiz_num in range(num_students):
        quiz_file = open(os.path.join('./bo_cau_hoi', f'quiz{quiz_num + 1}.txt'), 'w', encoding='utf-8')
        answer_key_file = open(os.path.join('./dap_an', f'quiz_answers{quiz_num + 1}.txt'), 'w', encoding='utf-8')
        quiz_file.write('Name:\n\nDate:\n\nPeriod:\n\n')
        quiz_file.write((' '*20) + f'Quiz (Form {quiz_num + 1})\n\n')
        quiz_file.write('Phần 1: Điền tên tác giả cho mỗi tác phẩm sau. Mỗi câu hỏi có 1 điểm.\n\n')
        works = list(draft.keys())
        random.shuffle(works)

        for question_num in range(10):
            quiz_file.write(f'{question_num + 1}. Tác giả của tác phẩm "{works[question_num]}" là: ___________\n\n')
            correct_answer = draft[works[question_num]]
            answer_key_file.write(f"{question_num + 1}. {correct_answer}\n")

        quiz_file.write('Phần 2: Chọn đáp án đúng cho mỗi câu hỏi sau. Mỗi câu hỏi có 4 lựa chọn và có 1 điểm.\n\n')

        for question_num in range(10, len(works)):
            correct_answer = draft[works[question_num]]
            wrong_answers = list(draft.values())
            del wrong_answers[wrong_answers.index(correct_answer)]
            wrong_answers = random.sample(wrong_answers, 3)

            quiz_file.write(f'{question_num + 1}. Tác giả của tác phẩm "{works[question_num]}" là ai?\n')
            answer_options = [correct_answer] + wrong_answers
            random.shuffle(answer_options)
            for i in range(4):
                quiz_file.write(f"    {'ABCD'[i]}. {answer_options[i]}\n")
            quiz_file.write('\n')

            correct_letter = "ABCD"[answer_options.index(correct_answer)]
            answer_key_file.write(f"{question_num + 1}. {correct_letter}\n")

        quiz_file.close()
        answer_key_file.close()

generate_quiz_files()

'''

'''