import sys
sys.setrecursionlimit(10000)

def get_pass(ps, attempt):
    visited = [False] * len(attempt)

    def crack(i):
        if not visited[i]:
            visited[i] = True
            for p in ps:
                if attempt[i:].startswith(p):
                    j = i + len(p)
                    if j == len(attempt):
                        return [p]
                    else:
                        ans = crack(j)
                        if ans:
                            return  [p] + ans
        return None

    ans = crack(0)
    return " ".join(ans) if ans else "WRONG PASSWORD"


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ps = input().split()
        attempt = input()
        print(get_pass(ps, attempt))

