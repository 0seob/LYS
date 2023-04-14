from math import sqrt, ceil, floor

def solution(r1, r2):
    answer = 0
    for i in range(1, r1+1):
        y = len(range(ceil(sqrt(r1**2 - i**2)), floor(sqrt(r2**2 - i**2))))
        answer += y + 1
    for i in range(r1+1, r2+1):
        y = floor(sqrt(r2**2 - i**2))
        answer += y + 1
    
    return answer*4