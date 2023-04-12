import sys
input = sys.stdin.readline

N = int(input())
data = list(map(int, input().split()))
data.sort()


def bin_search(data):
    low, ret_low = 0, 0
    high, ret_high = len(data) - 1, len(data) - 1
    like_zero = 2000000001
    while low < high:
        # print(low, high, data[low], data[high])
        if like_zero > abs(data[low] + data[high]):
            like_zero = abs(data[low] + data[high])
            ret_low = low
            ret_high = high
        if data[low] + data[high] < 0:
            low += 1
        elif data[low] + data[high] > 0:
            high -= 1
        else:
            return low, high
    return ret_low, ret_high


low, high = bin_search(data)
print(data[low], data[high])
