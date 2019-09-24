/****************************************************************************
 
* caesar.py
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Cipher text via caesar cipher
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

k = int(argv[1])
text = get_string('plaintext: ')
print('ciphertext: ', end = "")

# шифрование
for c in text:
    if c.isupper():
        aiold = ord(c) - 65
        ainew = (aiold + k) % 26
        ci = 65 + ainew
        print (chr(ci), end="")
    elif c.islower():
        aiold = ord(c) - 97
        ainew = (aiold + k) % 26
        ci = 97 + ainew
        print (chr(ci), end="")
    else:
        print (c, end="")

print()