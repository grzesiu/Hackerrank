if __name__ == '__main__':
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    s1 = set(a)
    s2 = set([i + k for i in a])
    print(len(s1 & s2))

