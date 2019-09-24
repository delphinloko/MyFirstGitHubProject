/****************************************************************************
 
* vigenere.py
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Cipher text via vigenere cipher
*
 
***************************************************************************/

# импортировали аргументы командной строки
from sys import argv
# импортировали get_string
from cs50 import get_string
# проверили на число аргументов
if len(argv) != 2:
    print('Enter only 2 command-line arguments')
    exit(1)

key = argv[1]
# проверка на буквенную строку
for c in key:
    if not c.isalpha():
        print('Key should consists only alphabetic characters')
        exit(1)

plaintext = get_string('plaintext: ')
print('ciphertext: ', end="")

# получаем число, на которую сдвигаем букву
def get_key(word, counter):
    n = len(word)
    index = counter % n
    if word[index].isupper():
        return (ord(word[index]) - 65)
    elif word[index].islower():
        return (ord(word[index]) - 97)
    else:
        print('Ошибочный ключ')
        exit(1)

j = 0
for i in range (len(plaintext)):
    if plaintext[i].isupper():
        ai0 = ord(plaintext[i]) - 65
        ai1 = (ai0 + get_key(key,j)) % 26
        j = j+1
        ci = 65 + ai1
        print(chr(ci), end="")
    elif plaintext[i].islower():
        ai0 = ord(plaintext[i]) - 97
        ai1 = (ai0 + get_key(key,j)) % 26
        j = j+1
        ci = 97 + ai1
        print(chr(ci), end="")
    else:
        print(plaintext[i], end="")
print()
exit(0)
