/****************************************************************************
 
* cash.py
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Count number of coins to change
*
 
***************************************************************************/

# Подключили функцию get_float
from cs50 import get_float
# Запросили число
while True:
    change = get_float("Change owned: ")
    if change >= 0:
        break

cents = round(change * 100)
coins = 0
coins = coins + cents//25
cents = cents % 25
coins = coins + cents//10
cents = cents % 10
coins = coins + cents//5
cents = cents % 5
coins = coins + cents

print(coins)