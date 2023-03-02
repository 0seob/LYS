from itertools import permutations
import math

def is_prime_number(number):
    for i in range(2, int(math.sqrt(number))+1):
        if number % i == 0:
            return False
    return True

def solution(numbers):
    data = []
    permute = []
    value = []
    answer = 0
    for i in range(len(numbers)):
        data.append(numbers[i])
    for i in range(1, len(data)+1):
        permute.extend(list(permutations(data, i)))
    for per in permute:
        value.append(int(''.join(per)))
    value = list(set(value))
    print(value)
    for val in value:
        if val > 1 and is_prime_number(val) == True:
            answer += 1
    
    return answer