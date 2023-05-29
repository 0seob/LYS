from collections import defaultdict

N, d, k, c = map(int, input().split())
left, right = 1 - k, 0
sushi, ans = [], []
for _ in range(N):
    sushi.append(input())
sushi_dict = defaultdict(int)
for i in range(left, right+1):
    sushi_dict[sushi[i]] += 1
for i in range(N):
    if str(c) not in sushi_dict:
        ans.append(len(sushi_dict) + 1)
    else:
        ans.append(len(sushi_dict))
    sushi_dict[sushi[left]] -= 1
    if sushi_dict[sushi[left]] == 0:
        sushi_dict.pop(sushi[left])
    left += 1
    right += 1
    sushi_dict[sushi[right%N]] += 1
print(max(ans))