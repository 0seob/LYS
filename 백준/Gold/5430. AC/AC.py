from collections import deque
import ast

first = True
error = False

def reverse():
    global first
    if first == True:
        first = False
    else:
        first = True

T = int(input())

for _ in range(T):
    first = True
    error = False
    p = input()
    n = int(input())
    dq = deque(ast.literal_eval(input()))
    for chr in p:
        if chr == 'R':
            reverse()
        else:
            if len(dq) == 0:
                print("error")
                error = True
                break
            if first == True:
                dq.popleft()
            else:
                dq.pop()
    if len(dq) == 0 and error == False:
        print("[]")
    elif first == True and error != True:
        print(f"[{dq[0]}", end="")
        for val in list(dq)[1:]:
            print(f",{val}", end="")
        print("]")
    elif first == False and error != True:
        dq.reverse()
        print(f"[{dq[0]}", end="")
        for val in list(dq)[1:]:
            print(f",{val}", end="")
        print("]")