from math import floor, ceil

def solution(w,h):
    answer = 0
    if w == h:
        return sum(range(1,w))*2

    for i in range(1, w):
        answer += (h*i)//w
    return answer*2
    # out = 0
    # before_y = 0
    # for x in range(1, w+1):
    #     now_y = (h/w) * x
    #     out += ceil(now_y) - floor(before_y)
    #     before_y = now_y
    # return answer - out