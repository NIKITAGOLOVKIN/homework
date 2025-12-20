import inspect

def summa(a, b, c):
    return a + b + c

def multi(a, b, c, d):
    return a * b * c * d

def curry(func, n):
    if not isinstance(n, int):
        raise TypeError("арность должна быть целым числом")
    if n < 0:
        raise ValueError("арность не может быть отрицательной")

    arity = len(inspect.signature(func).parameters)
    if n != arity:
        raise ValueError(f"Указанная арность {n} != фактической арности функции {arity}")

    def curried(*args):
        if len(args) >= n:
            return func(*args[:n])
        return lambda x: curried(*(args + (x, )))
    return curried

def uncurry(func, n):
    if not isinstance(n, int) or n < 0:
        raise ValueError("Недопустимая арность для uncurry")

    def uncurried(*args):
        if len(args) != n:
            raise TypeError(f"Ожидается {n} аргументов, получено {len(args)}")

        result = func
        for arg in args:
            result = result(arg)
        return result
    return uncurried

if __name__ == "__main__":
    curried_summa = curry(summa, 3)                  # создаем каррированную версию функций
    uncurried_summa = uncurry(curried_summa, 3)      # создаем каррированную версию функций
    curried_multi = curry(multi, 4)                  # создаем декаррированную версию функций
    uncurried_multi = uncurry(curried_multi, 4)      # создаем декаррированную версию функций

    print("Обычный вызов функции summa ", summa(3, 4, 5))
    print("Каррированная функция summa ", curried_summa(3)(4)(5))
    print("Декаррированная функция summa ", uncurried_summa(3, 4, 5))
    print()

    print("Обычный вызов функции multi ", multi(1, 2, 3, 4))
    print("Каррированная функция multi ", curried_multi(1)(2)(3)(4))
    print("Декаррированная функция multi ", uncurried_multi(1, 2, 3, 4))