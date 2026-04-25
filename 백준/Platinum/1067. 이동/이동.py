import cmath

def FFT(x, N):
    if N == 1: return [x[0]]

    G = FFT([x[i] for i in range(N) if not i % 2], N//2)
    H = FFT([x[i] for i in range(N) if i % 2], N//2)
    W = [cmath.exp(complex(real = 0, imag = -2*cmath.pi*r/N)) for r in range(N//2)]
    X = [G[r] + W[r]*H[r] for r in range(N//2)] + [G[r] - W[r]*H[r] for r in range(N//2)]

    return X

def IFFT(x, N):
    if N == 1: return [x[0]]

    g = IFFT([x[i] for i in range(N) if not i % 2], N//2)
    h = IFFT([x[i] for i in range(N) if i % 2], N//2)
    w = [cmath.exp(complex(real = 0, imag = +2*cmath.pi*k/N)) for k in range(N//2)]
    x = [0.5 * (g[k] + w[k]*h[k]) for k in range(N//2)] + [0.5 * (g[k] - w[k]*h[k]) for k in range(N//2)]
    
    return x

N = int(input())
x = list(map(int, input().split()))
h = list(map(int, input().split()))
h.reverse()

M = 1
while M < 2*N: 
    M *= 2
x += [0] * (M-N)
h = h*2 + [0] * (M-2*N)

X = FFT(x, M)
H = FFT(h, M)
XH = [X[r]*H[r] for r in range(M)]
xh = IFFT(XH, M)

conv = [round(xh[k].real) for k in range(N-1, 2*N)]
answer = max(conv)

print(answer)