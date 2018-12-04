if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        up_to = a[0]
        min_up_to = min(0, a[0])
        best_diff = a[0] - min_up_to
        sum_gt_0 = max(0, a[0])

        for i in range(1, n):
            if a[i] > 0:
                sum_gt_0 += a[i]
            up_to += a[i]
            if up_to - min_up_to > best_diff:
                best_diff = up_to - min_up_to
            elif up_to < min_up_to:
                min_up_to = up_to

        if sum_gt_0 > 0:
            print(best_diff, sum_gt_0)
        else:
            print(max(a), max(a))

