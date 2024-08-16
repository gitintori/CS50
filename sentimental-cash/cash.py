from cs50 import get_float

quarter = 25
dime = 10
nickel = 5
penny = 1

coins = 0

while True:
    amount = get_float("Change: ")
    if amount > 0:
        break

amount = round(amount * 100)

coins += amount // quarter
amount %= quarter

coins += amount // dime
amount %= dime

coins += amount // nickel
amount %= nickel

coins += amount // penny

print(int(coins))
