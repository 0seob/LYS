def solution(numbers):
    answer = [-1] * len(numbers)
    stack = []
    for idx, num in enumerate(numbers):
        while len(stack) != 0:
            if stack[-1][1] < num:
                answer[stack[-1][0]] = num
                stack.pop()
            else:
                break
        stack.append([idx, num])
    return answer