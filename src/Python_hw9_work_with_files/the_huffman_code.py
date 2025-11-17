def encode(msg: str):
    table = {}
    for char in msg:
        if char not in table:
            table[char] = msg.count(char)   # определяем вхождения символов в строку

    nodes = []
    for char, count in table.items():
        nodes.append((char, count))     # формируем список с узлами
    nodes.sort(key=lambda x: x[1])

    while len(nodes) > 1:
        left = nodes.pop(0)
        right = nodes.pop(0)                                    # формируем что-то вроде дерева - кортеж в котором
        nodes.append((None, left[1] + right[1], left, right))   # хранятся частоты символов и все зависимости между
        nodes.sort(key=lambda x: x[1])                          # узлами и листьями

    table = get_code(nodes[0])
    encode_str = "".join(table[char] for char in msg)    # формируем выходную строку
    return encode_str, table



def get_code(node):
    if node[0] is not None:     # если в кортеже один символ возвращаем 0
        return {node[0]: "0"}

    codes = {}

    def coding(current, code):
        if current[0] is not None:
            codes[current[0]] = code
        else:
            coding(current[2], code + "0")    # рекурсивно проходим по дереву и строим код
            coding(current[3], code + "1")
    coding(node, "")

    return codes       # возвращаем словарь с символами и их кодами



def decode(code, table):
    reverse_table = {char: i for i, char in table.items()}  # формируем перевернутый словарь код->символ
    decode_str = ""
    current_code = ""
    for char in code:
        current_code += char              #   прибавляем кодовую последовательность и, если она есть в словаре,
        if current_code in reverse_table: #   сопоставляем ей символ
            decode_str += reverse_table[current_code]
            current_code = ""

    return decode_str



def encoding_file(file):                   #функция для кодирования текстового файла
    encode_str, table = encode(file.read())
    return encode_str, table


def decoding_file(file, count):            #функция для декодирования текстового файла
    table = {}
    arr = []
    for i in range(count):
        arr.append(file.readline().replace("\n", "").split(": "))

    for i in arr:
        table[i[0]] = i[1]

    s = file.readline()
    msg = decode(s, table)
    return msg






msg = "ABRACADABRA"
print(f"Исходная строка: {msg}")
encode_str, table = encode(msg)
print(f"Закодированная строка: {encode_str}")

decode_str = decode(encode_str, table)
print(f"Декодированная строка: {decode_str}")




with open("input.txt") as file:         #читаем файл и кодируем его
    encode_file, table = encoding_file(file)

with open("output.txt", "w") as file:
    file.writelines(f"{char}: {code}\n" for char, code in table.items())       #записываем таблицу и код в output
    file.write(encode_file)
count_of_symbols = len(table.keys())




with open("output.txt") as file:
    decode_file = decoding_file(file, count_of_symbols)   #читаем таблицу и код из output и декодируем


with open("input.txt", "w") as file:                      #записываем результат в input
    file.write(decode_file)
