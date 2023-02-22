cache = dict()

def lru(cacheSize, city):
    # city가 cache에 존재하는지 확인하여
    # 있으면 기존 값보다 작은 것들을 1씩 증가시키고 city를 0으로 변경
    if city in cache.keys():
        low_val = [key for key in cache if cache[city] > cache[key]]
        for val in low_val:
            cache[val] += 1 
        cache[city] = 0
        return 1
    # 없으면 기존 것들을 1씩 증가시키고 city를 0으로 하여 추가
    else:    
        for key in cache:
            cache[key] += 1
        out_val = [key for key in cache if cache[key] == cacheSize]
        if len(out_val) == 1:
            cache.pop(out_val[0])
        cache[city] = 0
        return 5
    

def solution(cacheSize, cities):
    answer = 0
    if cacheSize == 0:
        return len(cities) * 5
    cache = dict()
    for city in cities:
        answer += lru(cacheSize, city.lower())
    
    return answer