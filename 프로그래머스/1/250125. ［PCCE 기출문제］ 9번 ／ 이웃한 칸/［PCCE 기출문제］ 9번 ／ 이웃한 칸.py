def solution(board, h, w):
    n = len(board)
    answer = 0
    
    # up down left right
    delta = [ [-1,0], [+1,0], [0,-1], [0,+1] ]
    
    for dh, dw in delta:
        h_check, w_check = h + dh, w + dw
        if 0 <= h_check < n and 0 <= w_check < n:
            if board[h][w] == board[h_check][w_check]:
                answer += 1

    return answer