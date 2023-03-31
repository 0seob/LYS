S = input()
T = input()

def dfs(S, T):
    retA, retB = False, False
    if len(S) == len(T):
        if S != T:
            return False
        else:
            return True
    if T[-1] == 'A':
        retA = dfs(S, T[:-1])
    if T[0] == 'B':
        T = T[::-1]
        retB = dfs(S, T[:-1])
    return retA or retB

if dfs(S, T) == True:
    print(1)
else:
    print(0)