from cs50 import get_int

while True:
    try:
        height = get_int("Height: ")
        if 1 <= height <= 8:
            break
        else:
            print("Enter a number between 1 and 8")
    except ValueError:
        print("Enter a positive number")

for i in range(height):
    for j in range(height - i - 1):
        print(" ", end="")

    for k in range(i + 1):
        print("#", end="")

    print("  ", end="")

    for k in range(i + 1):
        print("#", end="")

    print()
