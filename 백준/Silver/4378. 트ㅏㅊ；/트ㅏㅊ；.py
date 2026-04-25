qwerty = ['`','1','2','3','4','5','6','7','8','9','0','-','=', \
    'Q','W','E','R','T','Y','U','I','O','P','[',']','\\', \
    'A','S','D','F','G','H','J','K','L',';','\'', \
    'Z','X','C','V','B','N','M',',','.','/']

while True:
    try:
        string = input()

        for c in string:
            if c == ' ':
                print(c, end='')
            else:
                print(qwerty[qwerty.index(c)-1], end='')
        print('')
    
    except:
        break