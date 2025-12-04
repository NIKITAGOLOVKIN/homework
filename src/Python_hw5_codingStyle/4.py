def inputing():
    while True:
        amount = input("Введите число ")     #не пропускаем пользователя дальше пока он
        for i in amount:                     #не введет неотрицательное целое число
            if not (i.isdigit()):
                break
        else:
            return int(amount)




def exchange_of_coins(amount, coin1, coin2, coin3):
    if amount == 0:
        print("-42!")        #если сумма равна 0 то ее разменять нельзя
        return

    for count_coin3 in range(amount // coin3, -1, -1):
        for count_coin2 in range(amount // coin2, -1, -1):   #берем сколько возможно монет разным номиналом и перебираем
            for count_coin1 in range(amount // coin1, -1, -1):
                if count_coin3*coin3 + count_coin2*coin2 + count_coin1*coin1 == amount:
                    print("Можно разменять сумму", amount, end=" ")
                    if count_coin3 != 0:
                        print(count_coin3, "монетами номиналом", coin3, end=" ")
                    if count_coin2 != 0:
                        print(count_coin2, "монетами номиналом", coin2, end=" ")
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





NAME = "nikita"
SURNAME = "golovkin"                                   #определяем монеты
PATRONYMIC = "viktorovic"
coin1, coin2, coin3 = len(NAME), len(SURNAME), len(PATRONYMIC)

amount = inputing()
exchange_of_coins(amount, coin1, coin2, coin3)