def solution(phone_number):
    n = len(phone_number)
    stars = '*' * (n - 4)
    rest = phone_number[(n - 4):]
    return stars + rest