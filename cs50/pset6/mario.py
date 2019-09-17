# Подключили функцию get_int
from cs50 import get_int
# Запросили число от 1 до 8
while True:
    height = get_int("Height: ")
    if height < 9 and height > 0:
        break
# Напечатали 2 пирамиды
for i in range(height):
    for j in range(height-i-1):
        print(" ", end="")
    for j in range(i+1):
        print("#", end="")
    print(" " * 2, end="")
    for j in range(i+1):
        print("#", end="")
    print()
