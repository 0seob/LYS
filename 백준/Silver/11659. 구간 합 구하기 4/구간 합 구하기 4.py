import sys
input = sys.stdin.readline

N, M = map(int, input().split())
N_list = list(map(int, input().split()))

# # 1번 제출
# for _ in range(M):
#     ans = 0
#     i, j = map(int, input().split())
#     for idx in range(j - i + 1):
#         ans += N_list[i-1+idx]
#     print(ans)

# # 2번 제출
# for _ in range(M):
#     i, j = map(int, input().split())
#     print(sum(N_list[i-1:j]))
    
# 3번 제출
prefix_sum = [0]

temp = 0
for tmp in N_list:
    temp += tmp
    prefix_sum.append(temp)  
for _ in range(M):
    i, j = map(int, input().split())
    print(prefix_sum[j] - prefix_sum[i-1])