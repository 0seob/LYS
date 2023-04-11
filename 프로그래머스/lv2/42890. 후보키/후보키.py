from itertools import combinations

def solution(relation):
    answer = 0
    leng = list(range(len(relation[0])))
    candidate_key = []
    for i in range(1, len(relation[0])+1):
        if len(leng) < i:
            break
        bf = list(combinations(leng, i))
        for case in bf:
            ns = []
            for r in relation:
                key = [r[c] for c in case]
                if key in ns:
                    break
                else:
                    ns.append(key)
            else:
                for ck in candidate_key:
                    if set(ck).issubset(set(case)):
                        break
                else:
                    candidate_key.append(case)
    return len(candidate_key)