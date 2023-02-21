def solution(users, emoticons):
    answer = [0, 0]
    dl = []
    discount = []
    discount_percent = [10, 20, 30, 40]

    # 이모티콘 번호, 할인율, 지금까지 금액을 받아 계산 값을 return
    def dfs(num, discount_list, emoticons):
        if(num == emoticons):
            discount.append(list(discount_list))
            return
        for dp in discount_percent:
            discount_list.append(dp)
            dfs(num+1, discount_list, emoticons)
            discount_list.pop()
            
    dfs(0, dl, len(emoticons))
    
    for dis in discount:
        add_service = 0
        sales = 0
        for user in users:
            emo_price = [(100-x)*y//100 for x, y in zip(dis, emoticons) if x >= user[0]]
            if sum(emo_price) >= user[1]:
                add_service += 1
            else:
                sales += sum(emo_price)
        if add_service > answer[0]:
            answer[0] = add_service
            answer[1] = sales
        elif add_service == answer[0] and sales > answer[1]:
            answer[1] = sales
    return answer