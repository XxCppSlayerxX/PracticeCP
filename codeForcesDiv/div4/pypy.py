def construct_array(a):
    n = len(a)
    b = [0] * n
    b[0] = a[0]

    for i in range(1, n):
        if a[i] == a[i - 1]:
            b[i] = b[i - 1]
        else:
            b[i] = i

    return b

# Test cases
test_cases = [
    [1, 2],
    [1, 1, 1, 2],
    [4, 5, 5, 5, 1, 1, 2, 1],
    [1, 1, 2, 2, 1, 1, 3, 3, 1, 1]
]

for a in test_cases:
    b = construct_array(a)
    print(b)