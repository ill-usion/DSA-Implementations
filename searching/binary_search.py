

def search(arr, el):
    """
    Binary search
    Average complexity: O(floor(log n) + 1) = O(log n)

    Parameters
    ----------
    arr: List of sorted elements
    el: Element to search for

    Returns:
    If `el` exists or not
    """
    left = 0
    right = len(arr) - 1
    it = 0
    while left <= right:
        it += 1
        middle = (left + right) // 2
        if arr[middle] == el:
            return True, it
        elif arr[middle] < el:
            left = middle + 1
        elif arr[middle] > el:
            right = middle - 1

    return False, it

arr = [1, 3, 5, 6, 7, 8, 10, 12, 52]

print("Search space:", arr)
print("search(12):", search(arr, 12))
print("search(1):", search(arr, 1))
print("search(52):", search(arr, 52))
print("search(102):", search(arr, 102))
