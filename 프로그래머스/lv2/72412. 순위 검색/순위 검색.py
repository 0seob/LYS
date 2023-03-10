from bisect import bisect_left

lan = {"cpp": 0, "java": 1, "python": 2}
end = {"backend": 0, "frontend": 1}
exp = {"junior": 0, "senior": 1}
food = {"chicken": 0, "pizza": 1}

def get_number(temp):
    first = lan[temp[0]]
    second = end[temp[1]]
    third = exp[temp[2]]
    fourth = food[temp[3]]
    return first*8 + second*4 + third*2 + fourth

def get_number_query(temp):
    if temp[0] == "-":
        first = [0, 1, 2]
    else:
        first = [lan[temp[0]]]
    if temp[1] == "-":
        second = [0, 1]
    else:
        second = [end[temp[1]]]
    if temp[2] == "-":
        third = [0, 1]
    else:
        third = [exp[temp[2]]]
    if temp[3] == "-":
        fourth = [0, 1]
    else:
        fourth = [food[temp[3]]]
    
    ret = []
    for i in first:
        for j in second:
            for k in third:
                for l in fourth:
                    ret.append(i*8 + j*4 + k*2 + l)
    
    return ret

def solution(info, query):
    answer = []
    information = []
    idx = [0, 2, 4, 6]
    option = dict()
    option_idx = 0
    for lan in ["cpp", "java", "python"]:
        for end in ["backend", "frontend"]:
            for exp in ["junior", "senior"]:
                for food in ["chicken", "pizza"]:
                    option[option_idx] = []
                    option_idx += 1
    ifm = []
    for mation in info:
        temp = mation.split()
        ifm.append(temp)
    ifm = sorted(ifm, key = lambda x:int(x[-1]))
    for mation in ifm:
        option[get_number(mation)].append(int(mation[-1]))
    for qr in query:
        ans = 0
        temp = qr.replace("and", "").split()
        ls = get_number_query(temp)
        for i in ls:
            ans += len(option[i]) - bisect_left(option[i], int(temp[-1]))
        answer.append(ans)
                
    return answer