from collections import Counter
def solution(topping):
    answer = 0
    ubro = dict(Counter(topping))
    dbro = dict()
    for i in range(len(topping)):
        ubro[topping[i]] -= 1
        if ubro[topping[i]] == 0: del ubro[topping[i]]
        if topping[i] in dbro: dbro[topping[i]] += 1
        else: dbro[topping[i]] = 1
        if len(ubro) == len(dbro): answer += 1
    return answer