def digit_to_bin(num):
    ans = ""
    while num > 0:
        ans += str(num % 2)
        num //= 2
    ans = ans[::-1]
    tree_len = 2
    while tree_len - 1 < len(ans):
        tree_len *= 2
    ans = (tree_len - 1 - len(ans)) * '0' + ans
    return ans

def is_it_bin_tree(num):
    if len(num) == 1:
        return 1
    center = len(num) // 2
    if num[center] == '0' and not all(n == '0' for n in num):
        return 0
    return is_it_bin_tree(num[:center]) and is_it_bin_tree(num[center+1:])
        
def solution(numbers):
    answer = []
    for num in numbers:
        answer.append(is_it_bin_tree(digit_to_bin(num)))
    return answer