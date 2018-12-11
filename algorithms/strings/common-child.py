def lcs(s1, s2):
    a = [0] * (len(s2) + 1)
    for i in range(1, len(s1) + 1):
        t = 0
        for j in range(1, len(s2) + 1):
            tl = t
            t = a[j]
            a[j] = max(a[j - 1], t, tl + (s1[i - 1] == s2[j - 1]))
    return a[-1]

if __name__ == '__main__':
    s1 = raw_input()
    s2 = raw_input()
    print(lcs(s1, s2))
