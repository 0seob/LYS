from itertools import combinations

def solution(orders, course):
    answer = []
    menu_dict = [{}, {}, {}, {}, {}, {}, {}, {}, {}]
    for od in orders:
        menu = list(od)
        menu.sort()
        for cou in course:
            if len(menu) < cou:
                break
            bf = list(combinations(menu, cou))
            for temp in bf:
                if temp in menu_dict[cou-2]:
                    menu_dict[cou-2][temp] += 1
                else:
                    menu_dict[cou-2][temp] = 1
            
    for cou in course:
        tl = list(sorted(menu_dict[cou-2].items(), reverse=True, key=lambda md:md[1]))
        if tl:
            for temp in tl:
                # print(temp)
                if temp[1] == tl[0][1] and tl[0][1] >= 2:
                    answer.append(''.join(temp[0]))
                else:
                    break
    answer.sort()
    return answer