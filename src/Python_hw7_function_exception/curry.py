import inspect


def summa(a, b, c):
    return a + b + c


def multi(a, b, c, d):
    return a * b * c * d


def curry(func, n):
    def curried(*args):
        if len(args) >= n:
            return func(*args)
        def f(*args2):
            return curried(*args, *args2)
        return f
    return curried


def uncurry(func):
    def uncurried(*args):
        result = func
        for arg in args:
            result = result(arg)
        return result
    return uncurried



count_args_summa = len(inspect.signature(summa).parameters) #считаем кол-во аргументов в функциях
count_args_multi = len(inspect.signature(multi).parameters)


curried_summa = curry(summa, count_args_summa)       #создаем каррированную версию функций
uncurried_summa = uncurry(curried_summa)             #создаем каррированную версию функций
curried_multi = curry(multi, count_args_multi)       #создаем декаррированную версию функций
uncurried_multi = uncurry(curried_multi)             #создаем декаррированную версию функций


print("Обычный вызов функции summa", summa(3, 4, 5))
print("Каррированная функция summa", curried_summa(3)(4)(5))
print("Каррированная функция summa", curried_summa(3)(4, 5))           #проверка результатов
print("Каррированная функция summa", curried_summa(3, 4)(5))
print("Декаррированная функция summa", uncurried_summa(3, 4, 5))
print()

print("Обычный вызов функции multi", multi(1, 2, 3, 4))
print("Каррированная функция multi", curried_multi(1)(2)(3)(4))
print("Каррированная функция multi", curried_multi(1, 2)(3)(4))         #проверка результатов
print("Каррированная функция multi", curried_multi(1, 2)(3, 4))
print("Декаррированная функция multi", uncurried_multi(1, 2, 3, 4))
