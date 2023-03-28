def solution(picks, minerals):
    answer = 0
    piro = []
    tired = [0, 0, 0]
    number_of_pick = sum(picks)
    cnt = 0
    for idx, mineral in enumerate(minerals):
        if mineral == "diamond":
            tired[0] += 1 # 다이아몬드 개수
        elif mineral == "iron":
            tired[1] += 1 # 철 개수
        else:
            tired[2] += 1 # 돌 개수
        if (idx % 5 == 4 or idx == len(minerals) - 1):
            if cnt == number_of_pick: break
            cnt += 1
            piro.append(tired)
            tired = [0, 0, 0]
    piro.sort(reverse = True)
    for pick in piro:
        if picks[0] > 0:
            picks[0] -= 1
            answer += pick[0] + pick[1] + pick[2]
        elif picks[1] > 0:
            picks[1] -= 1
            answer += pick[0]*5 + pick[1] + pick[2]
        elif picks[2] > 0:
            picks[2] -= 1
            answer += pick[0]*25 + pick[1]*5 + pick[2]
        else:
            break
    return answer