print("2024-11-26, 학번 : 20118669, 이창엽\n")
score = int(input("점수를 입력하세요 (0-100): "))

if score > 100 or score < 0:
    print("점수 범위를 벗어났습니다.")
else:
    if 90 <= score <= 100:
        grade = 'A'
    elif 80 <= score:
        grade = 'B'
    elif 70 <= score:
        grade = 'C'
    elif 60 <= score:
        grade = 'D'
    else:
        grade = 'F'
    print(f"학점: {grade}")
