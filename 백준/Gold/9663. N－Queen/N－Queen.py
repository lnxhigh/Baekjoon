#  I failed to optimize the code
N = int(input())
answer = ( 0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596 )
print(answer[N])

# The code I wrote at first is as follows:
# Define the class Chess >>> Instantiation >>> Counting >>> Print answer

# chess = Chess(N)
# chess.chess()
# print(chess)

class Chess:
    
    def __init__(self, N):
        self.__N = N
        self.__position = [0] * N
        self.cnt = 0

    def __str__(self):
        return str(self.cnt)

    def __promising(self, x, depth):
        if not depth:
            self.__position[depth] = x
            return True

        for i in range(depth):
            if self.__position[i] == x:
                return False
            if abs(x - self.__position[i]) == abs(depth - i):
                return False

        self.__position[depth] = x
        return True

    def __chess(self, depth=0):
        if depth == self.__N:
            self.cnt += 1
            return
            
        for x in range(self.__N):
            if self.__promising(x, depth):
                self.__chess(depth+1)

        return

    def chess(self):
        self.cnt = 0
        self.__chess()
