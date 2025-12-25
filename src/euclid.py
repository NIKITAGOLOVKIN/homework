a, b = int(input('Введите число a ')), int(input('Введите число b '))
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
    orig_a, orig_b = a, b
    prev_r, r = a, b
    prev_x, x = 1, 0
    prev_y, y = 0, 1

    while r:
        q = prev_r // r
        prev_r, r = r, prev_r - q * r
        prev_x, x = x, prev_x - q * x
        prev_y, y = y, prev_y - q * y
    nod = prev_r

    print('НОД =', nod)
    print('Разложение по алгоритму Евклида:', orig_a, '*', prev_x, '+', orig_b, '*', prev_y, '=', nod)