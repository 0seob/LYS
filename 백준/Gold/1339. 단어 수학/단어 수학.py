from collections import defaultdict

N = int(input())
word = [input() for _ in range(N)]
word.sort(key=lambda x: [-len(x), x])
word_dict = defaultdict(int)
max_len = max(map(len, word))
for idx in range(N):
    leng = len(word[idx])
    for i in range(leng):
        word_dict[word[idx][leng - 1 - i]] += 10 ** i

word_list = sorted(word_dict.items(), key=lambda x: x[1], reverse=True)
num, ans = 9, 0
for wl in word_list:
    ans += wl[1] * num
    num -= 1
print(ans)
