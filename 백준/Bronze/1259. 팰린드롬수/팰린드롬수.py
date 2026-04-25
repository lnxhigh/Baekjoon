while True:
    s = input()
    if s == "0": break
    print("no" if any(s[i] != s[len(s)-1-i] for i in range(len(s)//2)) else "yes")