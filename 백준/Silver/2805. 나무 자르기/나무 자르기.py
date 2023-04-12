N, M = map(int, input().split())
H = list(map(int, input().split()))
H.sort()


def tree_height(tree):
    high = tree[-1]
    height_diff = []
    for i in range(len(tree)-1, 0, -1):
        height_diff.append(tree[i] - tree[i-1])
    height_diff.append(tree[0])
    # print(height_diff)
    cut_tree, height, last = 0, 0, 0
    for idx, cut in enumerate(height_diff):
        last = idx+1
        height += cut
        cut_tree += last * cut
        # print(cut_tree)
        if cut_tree >= M:
            break
    while cut_tree > M:
        cut_tree -= last
        height -= 1
        # print(cut_tree)
    if cut_tree != M:
        height += 1
    return high - height


print(tree_height(H))