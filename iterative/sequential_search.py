
def search(l, k):
    """
    Sequential search
    Compexity: O((n+1)/2) = O(n)
    Parameters
    ----------
    l: Sorted list of keys and values
    k: Key to search for

    Returns
    -------
    Value if key was found otherwise None
    """
    it = 0
    for ki, vi in l:
        it += 1
        if ki == k:
            return vi, it
        elif ki > k:
            return None, it

arr = [
        (1, 'm'),
        (3, 'x'),
        (4, 'a'),
        (9, 'e'),
]

print("Search space:", arr)
print("search(3):", search(arr, 3))
print("search(6):", search(arr, 6))
