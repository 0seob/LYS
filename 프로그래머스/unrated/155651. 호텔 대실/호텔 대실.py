def solution(book_time):
    new_book = []
    answer = 0
    for bt in book_time:
        sth, stm = bt[0].split(":")
        st = int(sth)*60 + int(stm)
        new_book.append([st, 1])
        eth, etm = bt[1].split(":")
        et = int(eth)*60 + int(etm) + 10
        new_book.append([et, 0])
    new_book.sort()
    cnt = 0
    for nb in new_book:
        if nb[1] == 1:
            cnt += 1
            answer = max(answer, cnt)
        else:
            cnt -= 1
    return answer