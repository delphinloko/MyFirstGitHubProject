/****************************************************************************
 
* crack.py
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Crack up to 5 signs password 
*
 
***************************************************************************/

# импортировали модуль crypt
import crypt
# импортировали аргументы командной строки
from sys import argv
# импортировали get_string
from cs50 import get_string
# проверили на число аргументов
if len(argv) != 2:
    print('Enter only 2 command-line arguments')
    exit(1)

hash = argv[1]
salt = hash[0] + hash[1]
all_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
password = ""

# проверка 1-буквенного пароля
for i in range (len(all_characters)):
    password = all_characters[i]
    if crypt.crypt(password, salt) == hash:
        print(password)
        exit(0)
print("End 1-st step")

# проверка 2-буквенного пароля
for i in range (len(all_characters)):
    for j in range (len(all_characters)):
        password = all_characters[i] + all_characters[j]
        if crypt.crypt(password, salt) == hash:
            print(password)
            exit(0)
print("End 2-nd step")

# проверка 3-буквенного пароля
for i in range (len(all_characters)):
    for j in range (len(all_characters)):
        for k in range (len(all_characters)):
            password = all_characters[i] + all_characters[j] + all_characters[k]
            if crypt.crypt(password, salt) == hash:
                print(password)
                exit(0)
print("End 3-rd step")

# проверка 4-буквенного пароля
for i in range (len(all_characters)):
    for j in range (len(all_characters)):
        for k in range (len(all_characters)):
            for l in range (len(all_characters)):
                password = all_characters[i] + all_characters[j] + all_characters[k] + all_characters[l]
                if crypt.crypt(password, salt) == hash:
                    print(password)
                    exit(0)
print("End 4-th step")

# проверка 5-буквенного пароля
for i in range (len(all_characters)):
    for j in range (len(all_characters)):
        for k in range (len(all_characters)):
            for l in range (len(all_characters)):
                for m in range (len(all_characters)):
                    password = all_characters[i] + all_characters[j] + all_characters[k] + all_characters[l] + all_characters[m]
                    if crypt.crypt(password, salt) == hash:
                        print(password)
                        exit(0)
print("End 5-th step")

print("Couldn't crack password")