from itertools import product

def permutations(array, r, prefix=[]):
    for i in range(len(array)):
        if i in prefix: continue
        if r == 1:
            yield [array[i]]
        else:
            prefix.append(i)
            for next in permutations(array, r-1, prefix):
                yield [array[i]] + next
            prefix.pop()


def solution(k, dungeons):
    answer = -1
    bf = list(permutations(list(range(len(dungeons))), len(dungeons), []))
    result = []
    for case in bf:
        temp = k
        cnt = 0
        for val in case:
            if temp >= dungeons[val][0]:
                temp -= dungeons[val][1]
                cnt += 1
            else:
                break
        result.append(cnt)
    answer = max(result)
    return answer