# Подключили функцию get_int
from cs50 import get_int
# Запросили число
while True:
    number = get_int("Number: ")
    if number:
        break

# узнаем длину введёного числа
length = len(str(number))
# создали список для чисел в числе
numbers = []
# заполнили список цифрами числа с конца
for i in range(length):
    numbers.append(number % 10)
    number = number // 10

# суммирование по алгоритму Luhnа


def sumcheck(numbers):
    sum = 0
    for i in range(length):
        if i % 2 != 0:
            sum += numbers[i] * 2 % 10 + numbers[i] * 2 // 10 % 10
        if i % 2 == 0:
            sum += numbers[i]
    return sum % 10


# AE
if length == 15 and (numbers[length-2] == 4 or numbers[length-2] == 7) and numbers[length-1] == 3 and sumcheck(numbers) == 0:
    print('AMEX')
# MC
elif length == 16 and (numbers[length-2] > 0 and numbers[length-2] < 6) and numbers[length-1] == 5 and sumcheck(numbers) == 0:
    print('MASTERCARD')
# Visa
elif (length == 16 or length == 13) and numbers[length-1] == 4 and sumcheck(numbers) == 0:
    print('VISA')
# INVALID
else:
    print('INVALID')