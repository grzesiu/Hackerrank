def stockmax(prices):
    curr_max = 0
    profit = 0

    for i in range(len(prices) - 1, -1, -1):
        if prices[i] >= curr_max:
            curr_max = prices[i]
        profit += curr_max - prices[i]

    return profit


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        # bug in test cases
        input()
        prices = list(map(int, input().split()))
        print(stockmax(prices))

