N = int(input())
word = list(input())
ans = 0
for _ in range(N-1):
    new_word = word[:]
    temp = input()
    cor = 0
    for tp in temp:
        if tp in new_word:
            new_word.remove(tp)
        else:
            cor += 1
    if cor < 2 and len(new_word) < 2:
        ans += 1
print(ans)