def encode(msg: str):
    table = {}
    for char in msg:
        if char not in table:
            table[char] = msg.count(char)   # определяем вхождения символов в строку

    nodes = []
    for char, count in table.items():
        nodes.append((count, char, None, None))     # формируем список с узлами
    nodes.sort(key=lambda x: x[0])

    while len(nodes) > 1:
        left = nodes.pop(0)
        right = nodes.pop(0)                                    # формируем что-то вроде дерева - кортеж в котором
        nodes.append((left[0] + right[0], None, left, right))   # хранятся частоты символов и все зависимости между
        nodes.sort(key=lambda x: x[0])                          # узлами и листьями

    table = get_code(nodes[0])
    encode_str = "".join(table[char] for char in msg)    # формируем выходную строку
    return encode_str, table

def get_code(node):
    codes = {}

    def coding(current, code):
        if current[1] is not None:
            codes[current[1]] = code
        else:
            coding(current[2], code + "0")    # рекурсивно проходим по дереву и строим код
            coding(current[3], code + "1")

    if node[1] is not None:
        return {node[1]: "0"}

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

def encoding_file(input_path, output_path):
    with open(input_path, 'r') as file:
        msg = file.read()
    encoded_str, table = encode(msg)

    with open(output_path, 'w') as file:
        file.write(str(len(table)) + '\n')  # Записываем размер таблицы
        for char, code in table.items():
            file.write(f"{char}:{code}\n")
        file.write(encoded_str)

def decoding_file(input_path, output_path):
    with open(input_path, 'r') as file:
        count = int(file.readline().strip())  # Читаем размер таблицы

        table = {}
        for i in range(count):
            line = file.readline().rstrip('\n')
            char, code = line.split(':', 1)  # Делим только по первому двоеточию
            table[char] = code
        encoded_str = file.read()
    decoded_str = decode(encoded_str, table)
    with open(output_path, 'w') as file:
        file.write(decoded_str)
    return decoded_str


if __name__ == "__main__":
    # Пример использования (можно удалить перед сдачей)
    test_msg = input("Введите строку для тестирования: ")
    encoded, table = encode(test_msg)
    print("Закодировано:", encoded)
    print("Декодировано:", decode(encoded, table))