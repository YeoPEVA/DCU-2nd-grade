print("2024-11-26, 학번 : 20118669, 이창엽\n")
score = int(input("점수를 입력하세요 (0-100): "))

if score > 100 or score < 0:
    print("점수 범위를 벗어났습니다.")
else:
    match score // 10:
        case 10 | 9:
            grade = 'A'
        case 8:
            grade = 'B'
        case 7:
            grade = 'C'
        case 6:
            grade = 'D'
        case _:
            grade = 'F'
    print(f"학점: {grade}")
