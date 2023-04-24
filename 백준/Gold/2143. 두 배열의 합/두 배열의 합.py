T = int(input())
n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))
idA, idB = 0, 0
dictA, dictB = {}, {}
for i in range(n):
    sumA = A[i]
    if sumA in dictA:
        dictA[sumA] += 1
    else:
        dictA[sumA] = 1
    for j in range(i+1, n):
        sumA += A[j]
        if sumA in dictA:
            dictA[sumA] += 1
        else:
            dictA[sumA] = 1

for i in range(m):
    sumB = B[i]
    if sumB in dictB:
        dictB[sumB] += 1
    else:
        dictB[sumB] = 1
    for j in range(i + 1, m):
        sumB += B[j]
        if sumB in dictB:
            dictB[sumB] += 1
        else:
            dictB[sumB] = 1

ans = 0
for Akey in dictA.keys():
    if T - Akey in dictB:
        ans += dictA[Akey] * dictB[T - Akey]
print(ans)