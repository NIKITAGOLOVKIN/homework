def heap_building(arr, n, i):
    maximum = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[maximum]:
        maximum = left

    if right < n and arr[right] > arr[maximum]:
        maximum = right

    if maximum != i:
        arr[i], arr[maximum] = arr[maximum], arr[i]
        heap_building(arr, n, maximum)
    return arr



def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heap_building(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heap_building(arr, i, 0)
    return arr



if __name__ == "__main__":
    arr = [13, -9, -47, 0, 3, 1, 88]
    print("Массив до сортировки:", arr)

    print("Массив после сортировки:", heap_sort(arr))