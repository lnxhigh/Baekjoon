expression = input()

operand = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' ,'K', 'L', 'M', 'N', \
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

operator = ['+', '-', '*', '/', '(', ')']
priority = {'+': 1, '-': 1, '*': 2, '/': 2, '(': 0, ')': None}

def infixToPostfix(infixExpression):
    post = ''
    stack = []

    for c in infixExpression:
        if c in operand:
            post += c

        elif c in operator:
            if not stack:
                stack.append(c)
            else:
                if c == '(':
                    stack.append(c)
                    continue

                if c == ')':
                    while True:
                        p = stack.pop()
                        if p != '(':
                            post += p
                            continue
                        else:
                            break
                    continue

                if priority[c] <= priority[stack[-1]]:
                    while priority[c] <= priority[stack[-1]]:
                        post += stack.pop()
                        if not stack:
                            break
                
                stack.append(c)

        else:
            pass

    while stack:
        post += stack.pop()

    return post

post = infixToPostfix(expression)
print(post)