def solution(phone_book):
    answer = True
    pd = dict()
    for pn in phone_book:
        pd[pn] = 1
    for pn in phone_book:
        pd.pop(pn)
        temp = ''
        for i in range(len(pn)):
            temp += pn[i]
            if temp in pd:
                return False
        pd[pn] = 1
    return answer