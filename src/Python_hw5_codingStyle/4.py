def exchange_of_coins(summa, coin1, coin2, coin3):
    if summa == 0:
        print("-42!")        #если сумма равна 0 то ее разменять нельзя
        return

    for count_coin3 in range(summa // coin3, -1, -1):
        for count_coin2 in range(summa // coin2, -1, -1):   #берем сколько возможно монет разным номиналом и перебираем
            for count_coin1 in range(summa // coin1, -1, -1):
                if count_coin3*coin3 + count_coin2*coin2 + count_coin1*coin1 == summa:  #если получили сумму,
                    print("Можно разменять сумму", summa, end=" ")                      #печатаем размен
                    if count_coin3 != 0:
                        print(count_coin3, "монетами номиналом", coin3, end=" ")
                    if count_coin2 != 0:
                        print(count_coin2, "монетами номиналом", coin2, end=" ")        #печать размена
                    if count_coin1 != 0:
                        print(count_coin1, "монетами номиналом", coin1)
                    break
            else:
                continue
            break
        else:
            continue
        break


    if count_coin3 == 0 and count_coin2 == 0 and count_coin1 == 0:     #если не получилось разменять печатаем -42!
        print("-42!")







name = "nikita"
surname = "golovkin"                                   #определяем монеты
ot = "viktorovic"
coin1, coin2, coin3 = len(name), len(surname), len(ot)


s = "1234567890"
while True:
    summa = input("Введите число ")     #не пропускаем пользователя дальше пока он не введет неотрицательное целое число
    for i in summa:
        if i not in s:
            break
    else:
        summa = int(summa)
        break


exchange_of_coins(summa, coin1, coin2, coin3)
