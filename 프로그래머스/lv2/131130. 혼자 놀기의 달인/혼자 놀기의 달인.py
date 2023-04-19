from collections import deque

def solution(cards):
    answer = 0
    visit = [0 for _ in range(len(cards)+1)]
    cards = [0] + cards
    for idx, card in enumerate(cards[1:]):
        dq = deque()
        if visit[idx+1] > 0:
            continue
        visit[idx+1] = idx+1
        dq.append(card)
        visit[card] = idx+1
        while dq:
            cx = dq.popleft()
            if visit[cards[cx]] > 0:
                continue
            dq.append(cards[cx])
            visit[cards[cx]] = idx+1
    answer_dict = {}
    for num in visit[1:]:
        if num in answer_dict:
            answer_dict[num] += 1
        else:
            answer_dict[num] = 1
    answer_list = sorted(answer_dict.values(), reverse = True)
    if len(answer_list) == 1:
        return 0
    return answer_list[0] * answer_list[1]