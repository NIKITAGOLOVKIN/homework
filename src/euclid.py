a, b = int(input('Введите число a ')), int(input('Введите число b '))
ostatki, x, y = [], [], []
q = 0
if a == 0 or b == 0:
    if a == 0 and b == 0:
        print('Error!!!', 'Невозможно посчитать НОД для двух чисел равных 0')
    elif a == 0:
        print('НОД =', b)
        print('Разложение по алгоритму Евклида:', a, '*', 0, '+', b, '*', 1, '=', b)
    else:
        print('НОД =', a)
        print('Разложение по алгоритму Евклида:', a, '*', 1, '+', b, '*', 0, '=', a)
else:
    ostatki.append(max(a, b))
    ostatki.append(min(a, b))
    x.append(1)
    x.append(0)
    y.append(0)
    y.append(1)
    i = 2


    while ostatki[i-2] % ostatki[i-1] > 0:
        q = ostatki[i-2] // ostatki[i-1]
        ostatki.append(ostatki[i-2] - (q * ostatki[i-1]))      #Тут происходит сам алгоритм Евклида
        x.append(x[i-2] - (q * x[i-1]))
        y.append(y[i-2] - (q * y[i-1]))
        i += 1


    ostatki.append(ostatki[i-2] - (q * ostatki[i-1]))         #Проходим последнюю итерацию алгоритма вне цикла
    x.append(x[i-2] - (q * x[i-1]))
    y.append(y[i-2] - (q * y[i-1]))


    print('НОД =', ostatki[-2])
    print('Разложение по алгоритму Евклида:', ostatki[0], '*', x[-2], '+', ostatki[1], '*', y[-2], '=', ostatki[-2])