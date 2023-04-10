def solution(players, callings):
    answer = []
    dt = {}
    for idx, p in enumerate(players):
        dt[p] = idx
    for c in callings:
        idx = dt[c]
        temp = players[idx]
        players[idx] = players[idx-1]
        players[idx-1] = temp
        dt[players[idx]] = idx
        dt[c] = idx-1
    return players