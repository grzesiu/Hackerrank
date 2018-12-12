def get_counts(n, s):
    counts = [[s[0], 1]]
    for i in range(1, n):
        if counts[-1][0] == s[i]:
            counts[-1][1] += 1
        else:
            counts.append([s[i], 1])
    return counts

def count_same(counts):
    sums = [0]
    for i in range(1, max(list(zip(*counts))[1]) + 1):
        sums.append(i + sums[-1])
    acc = 0
    for _, count in counts:
        acc += sums[count]
    return acc

def count_different_middle(counts):
    acc = 0
    for i in range(1, len(counts) - 1):
        if counts[i][1] == 1 and counts[i - 1][0] == counts[i + 1][0]:
            acc += min(counts[i - 1][1], counts[i + 1][1])
    return acc

if __name__ == '__main__':
    n = int(input())
    s = input()
    counts = get_counts(n, s)
    total = count_same(counts) + count_different_middle(counts)
    print(total)
