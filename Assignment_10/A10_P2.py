def generate_magic_square(n):
    if n % 2 == 1:
        return generate_odd_magic_square(n)
    elif n % 4 == 0:
        return generate_doubly_even_magic_square(n)
    else:
        return generate_singly_even_magic_square(n)

def generate_odd_magic_square(n):
    magic_square = [[0] * n for _ in range(n)]
    i, j = 0, n // 2

    for num in range(1, n * n + 1):
        magic_square[i][j] = num
        i_new, j_new = (i - 1) % n, (j + 1) % n
        if magic_square[i_new][j_new]:
            i += 1
        else:
            i, j = i_new, j_new

    return magic_square

def generate_doubly_even_magic_square(n):
    magic_square = [[(i * n) + j + 1 for j in range(n)] for i in range(n)]

    for i in range(n):
        for j in range(n):
            if (i % 4 == j % 4) or (i % 4 + j % 4 == 3):
                magic_square[i][j] = n * n + 1 - magic_square[i][j]

    return magic_square

def generate_singly_even_magic_square(n):
    half_n = n // 2
    sub_square_size = half_n * half_n
    sub_square = generate_odd_magic_square(half_n)

    magic_square = [[0] * n for _ in range(n)]

    for i in range(half_n):
        for j in range(half_n):
            magic_square[i][j] = sub_square[i][j]
            magic_square[i + half_n][j + half_n] = sub_square[i][j] + sub_square_size
            magic_square[i + half_n][j] = sub_square[i][j] + 2 * sub_square_size
            magic_square[i][j + half_n] = sub_square[i][j] + 3 * sub_square_size

    k = (n - 2) // 4
    for i in range(half_n):
        for j in range(k):
            magic_square[i][j], magic_square[i + half_n][j] = magic_square[i + half_n][j], magic_square[i][j]
        for j in range(n - k + 1, n):
            magic_square[i][j], magic_square[i + half_n][j] = magic_square[i + half_n][j], magic_square[i][j]

    for i in range(k):
        magic_square[i][k], magic_square[i + half_n][k] = magic_square[i + half_n][k], magic_square[i][k]
        magic_square[i][k + half_n], magic_square[i + half_n][k + half_n] = magic_square[i + half_n][k + half_n], magic_square[i][k + half_n]

    return magic_square

def print_magic_square(square):
    for row in square:
        print(" ".join(f"{num:2}" for num in row))
    print()

if __name__ == "__main__":
    for n in [4, 5, 6, 7, 8]:
        print(f"Magic Square for N={n}:")
        magic_square = generate_magic_square(n)
        print_magic_square(magic_square)
