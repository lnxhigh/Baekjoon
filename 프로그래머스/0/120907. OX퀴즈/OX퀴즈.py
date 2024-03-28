def solution(quizzes):
    answer = []
    
    for quiz in quizzes:
        quiz = quiz.replace("=", "==")

        res = 'O' if eval(quiz) else 'X'
        answer.append(res)
            
    return answer