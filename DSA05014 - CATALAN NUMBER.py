def catalan_number(n):
    if n <= 1:
        return 1
    catalan = [0] * (n + 1)
    catalan[0] = 1
    catalan[1] = 1
    for i in range(2, n + 1):
        catalan[i] = 0
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i - j - 1]
    return catalan[n]
if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        print(catalan_number(n))