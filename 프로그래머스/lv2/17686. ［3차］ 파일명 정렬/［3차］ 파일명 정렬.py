def solution(files):
    answer = []
    all_files = []
    for idx, file in enumerate(files):
        isdigit = False
        ischar = False
        ftemp = []
        temp = ''
        for i, ch in enumerate(file):
            if ischar == False:
                if isdigit == ch.isdigit():
                    temp += ch
                elif isdigit == False and ch.isdigit():
                    ftemp.append(temp)
                    temp = ch
                    isdigit = True
                elif isdigit == True and not ch.isdigit():
                    ftemp.append(temp)
                    temp = ch
                    ischar = True
            else:
                temp += ch
                
            if i == len(file) - 1:
                if ischar == False:
                    ftemp.append(temp)
                    ftemp.append('')
                else:
                    ftemp.append(temp)
                ftemp.append(idx)
        all_files.append(ftemp)
    all_files = sorted(all_files, key = lambda x : (x[0].lower(), int(x[1])))
    for af in all_files:
        answer.append(''.join(af[:3]))
    return answer