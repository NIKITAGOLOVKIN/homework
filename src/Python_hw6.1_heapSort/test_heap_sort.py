from heap_sort import heap_building, heap_sort


def test_heap_building_basic():
    arr = [10, 5, 3, 2, 4]
    heap_building(arr, len(arr), 0)
    assert arr == [10, 5, 3, 2, 4]

    arr = [3, 10, 5, 2, 4]
    heap_building(arr, len(arr), 0)
    assert arr == [10, 4, 5, 2, 3]

def test_heap_building_with_limit():
    arr = [10, 20, 5, 30, 40]
    heap_building(arr, 3, 0)
    assert arr[:3] == [20, 10, 5]

def test_heap_sort_basic():
    test_cases = [
        [4, 2, 1, 3],
        [1, 3, 2],
        [5, 1, 4, 2, 8],
    ]

    for arr in test_cases:
        expected = sorted(arr)
        heap_sort(arr)
        assert arr == expected

def test_empty_array():
    arr = []
    heap_sort(arr)
    assert arr == []

def test_single_element():
    arr = [42]
    heap_sort(arr)
    assert arr == [42]

def test_two_elements():
    test_cases = [
        [1, 2],
        [2, 1],
        [2, 2],
    ]

    for arr in test_cases:
        expected = sorted(arr)
        heap_sort(arr)
        assert arr == expected

def test_already_sorted():
    arr = [1, 2, 3, 4, 5]
    heap_sort(arr)
    assert arr == [1, 2, 3, 4, 5]

    arr = [5, 4, 3, 2, 1]
    heap_sort(arr)
    assert arr == [1, 2, 3, 4, 5]

def test_all_identical():
    test_cases = [
        [1, 1, 1],
        [0, 0, 0, 0],
        [-1, -1, -1],
    ]

    for arr in test_cases:
        expected = arr
        heap_sort(arr)
        assert arr == expected

def test_with_duplicates():
    test_cases = [
        [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5],
        [1, 2, 3, 2, 1],
        [5, 5, 3, 3, 1, 1],
    ]

    for arr in test_cases:
        expected = sorted(arr)
        heap_sort(arr)
        assert arr == expected

def test_negative_numbers():
    test_cases = [
        [-3, -1, -2],
        [3, -1, 0, -2, 5],
        [-5, -5, -3, -10],
    ]

    for arr in test_cases:
        expected = sorted(arr)
        heap_sort(arr)
        assert arr == expected

def test_floats():
    arr = [3.14, 1.41, 2.71, 0.0, -1.0]
    expected = sorted(arr)
    heap_sort(arr)
    assert arr == expected

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def test_against_other_sorts():
        arr = [1, 5, 2, 4, 3]
        assert bubble_sort(arr) == heap_sort(arr)