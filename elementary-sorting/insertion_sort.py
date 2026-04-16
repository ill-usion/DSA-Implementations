
a = [68, 34, 15, 126, 59, 6, 83, 29, 10]

def insertion_sort(a):
    temp = 0
    j = 0

    for i in range(1, len(a)):
        temp = a[i]
        j = i
        while (j > 0) and (a[j-1] > temp):
            a[j] = a[j-1]
            j -=1

        a[j] = temp

def insertion_sort_desc(a):
    temp = 0
    j = 0

    for i in range(len(a) - 2, 0):
        temp = a[i]
        j = i
        while (j < len(a) - 1) and (a[j-1] < temp):
            a[j] = a[j+1]
            j +=1

        a[j] = temp

a1 = a.copy()
print("Before sort:", a)
insertion_sort(a1)
print("After sort:", a1)
a2 = a.copy()
insertion_sort_desc(a)
print("After sort descending:", a)
