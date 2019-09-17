from cs50 import get_string
from sys import argv


def main():
    # проверили на число аргументов
    if len(argv) != 2:
        print('Enter only 2 command-line arguments')
        exit(1)

    # завели лист для слов из txt
    words = []
    # открыли файл и перенесли из него слова в words
    file = open(argv[1], "r")
    for line in file:
        words.append(line.rstrip("\n"))
    file.close()

    # запросили строку у пользователя
    print('What message whould you loke to censor?')
    censortext = get_string('').split()

    for word in censortext:
        if word.lower() in words:
            print('*' * len(word), end = "")
            print(' ', end = "")
        else:
            print('{} '.format(word), end="")
    print()
    #print(words)
    #print(censortext)

if __name__ == "__main__":
    main()
