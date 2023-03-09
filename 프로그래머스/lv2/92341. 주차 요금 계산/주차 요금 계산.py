def cal_fee(fees, time):
    if time <= fees[0]:
        return fees[1]
    else:
        mok = (time - fees[0]) // fees[2]
        if (time - fees[0]) % fees[2] != 0:
            mok += 1
        return fees[1] + mok * fees[3]

def cal_time(re_str):
    temp = re_str.split(":")
    return int(temp[0]) * 60 + int(temp[1])

def solution(fees, records):
    record = [rec.split() for rec in records]
    print(record)
    record = sorted(record, key=lambda record: record[1])
    print(record)
    car_number = dict()
    fee = dict()
    for re in record:
        if re[1] not in car_number:
            car_number[re[1]] = cal_time(re[0])
        else:
            past = car_number.pop(re[1])
            now = cal_time(re[0])
            if re[1] not in fee:
                fee[re[1]] = now - past
            else:
                fee[re[1]] += now - past
    for cn in car_number:
        now = 1439
        if cn not in fee:
            fee[cn] = now - car_number[cn]
        else:
            fee[cn] += now - car_number[cn]
    for fe in fee:
        fee[fe] = cal_fee(fees, fee[fe])
    answer = list(map(lambda x:x[1], sorted(fee.items())))
    return answer