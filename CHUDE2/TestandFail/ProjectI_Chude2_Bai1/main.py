from datetime import datetime
import sys

sys.setrecursionlimit(10000000)

def partition_2_way(array, low, high):
    #dat pivot la phan tu cuoi cung
    pivot = array[high]
    #con tro vi tri
    i = low - 1
    for j in range(low, high):
        #neu so do nho hon pivot
        if array[j] < pivot:
            i = i + 1
            #dua ve lan luot tu dau list
            (array[i], array[j]) = (array[j], array[i])

    #dua pivot ve dung vi tri
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    #tra ve vi tri pivot
    return i + 1


def quick_sort_2_way(array, low, high):
    if low >= high:
        return

    pi = partition_2_way(array, low, high)
    #lap lai quick sort 2 ben
    quick_sort_2_way(array, low, pi - 1)
    quick_sort_2_way(array, pi + 1, high)


def partition_3_way(array, low, high, start, mid):
    #pivot la phan tu cuoi cung
    pivot = array[high]
    end = high

    #dua mid va start ve dung vi tri
    while(mid[0] <= end):

        if(array[mid[0]] < pivot):
            array[mid[0]], array[start[0]] = array[start[0]], array[mid[0]]
            mid[0] = mid[0] + 1
            start[0] = start[0] + 1

        elif(array[mid[0]] > pivot):
            array[mid[0]], array[end] = array[end], array[mid[0]]
            end = end - 1

        else:
            mid[0] = mid[0] + 1


def quick_sort_3_way(array, low, high):
    if low >= high:
        return

    #neu con hai so
    if(high == low + 1):
        if(array[low] > array[high]):
            array[low], array[high] = array[high], array[low]
            return

    #start-mid la gia tri pivot, mang vi co the co nhieu gia tri
    start = [low]
    mid = [low]
    partition_3_way(array, low, high, start, mid)
    #sort hai ben pivot
    quick_sort_3_way(array, low, start[0] - 1)
    quick_sort_3_way(array, mid[0], high)


# f = open('10000.txt', 'r')
# n = int(f.readline())
# a = []
# for i in range(n):
#     a.append(int(f.readline()))
# f.close()

############################################################################################

n = 10000
a = []
f = open('10000.txt')
for line in f:
   a.append(int(line))
f.close()

start2 = datetime.now()
quick_sort_2_way(a, 0, n - 1)
end2 = datetime.now()

print("2 way partition quick sort time with 10000 numbers: ", end2 - start2)

b = []
f = open('10000.txt')
for line in f:
   b.append(int(line))
f.close()

start3 = datetime.now()
quick_sort_3_way(b, 0, n-1)
end3 = datetime.now()

print("3 way partition quick sort time with 10000 numbers: ", end3 - start3)

############################################################################################

n = 100000
a = []
f = open('100000.txt')
for line in f:
   a.append(int(line))
f.close()

start2 = datetime.now()
quick_sort_2_way(a, 0, n - 1)
end2 = datetime.now()

print("2 way partition quick sort time with 100000 numbers: ", end2 - start2)

b = []
f = open('100000.txt')
for line in f:
   b.append(int(line))
f.close()

start3 = datetime.now()
quick_sort_3_way(b, 0, n-1)
end3 = datetime.now()

print("3 way partition quick sort time with 100000 numbers: ", end3 - start3)

############################################################################################

n = 200000
a = []
f = open('1000000.txt')
for line in f:
   a.append(int(line))
f.close()

start2 = datetime.now()
quick_sort_2_way(a, 0, n - 1)
end2 = datetime.now()

print("2 way partition quick sort time with 200000 numbers: ", end2 - start2)

b = []
f = open('1000000.txt')
for line in f:
   b.append(int(line))
f.close()

start3 = datetime.now()
quick_sort_3_way(b, 0, n-1)
end3 = datetime.now()

print("3 way partition quick sort time with 200000 numbers: ", end3 - start3)

############################################################################################

# n = 500000
# a = []
# f = open('1000000.txt')
# for line in f:
#    a.append(int(line))
# f.close()
#
# start2 = datetime.now()
# quick_sort_2_way(a, 0, n - 1)
# end2 = datetime.now()
#
# print("2 way partition quick sort time with 1000000 numbers: ", end2 - start2)

##############################################################################################

n = 1000000
b = []
f = open('1000000.txt')
for line in f:
   b.append(int(line))
f.close()

start3 = datetime.now()
quick_sort_3_way(b, 0, n-1)
end3 = datetime.now()

print("3 way partition quick sort time with 1000000 numbers: ", end3 - start3)

############################################################################################

# n = 10000000
# a = []
# f = open('10000000.txt')
# for line in f:
#    a.append(int(line))
# f.close()
#
# start2 = datetime.now()
# quick_sort_2_way(a, 0, n - 1)
# end2 = datetime.now()
#
# print("2 way partition quick sort time with 10000000 numbers: ", end2 - start2)

######################################KEEEP THIS#####################################################

n = 10000000
b = []
f = open('10000000.txt')
for line in f:
   b.append(int(line))
f.close()

start3 = datetime.now()
quick_sort_3_way(b, 0, n-1)
end3 = datetime.now()

print("3 way partition quick sort time with 10000000 numbers: ", end3 - start3)

##############################################################################################

print("Divide 1000000.txt file to 10 parts, each part have 100000 numbers")

n = 100000
sum = datetime.now()
temp = sum
f = open('1000000.txt')
for i in range(10):
    a = []
    for j in range(100000):
        a.append(int(f.readline()))

    start2 = datetime.now()
    quick_sort_2_way(a, 0, n - 1)
    end2 = datetime.now()
    sum = sum + (end2 - start2)

f.close()

print("2 way partition quick sort time with 10 parts of 100000 numbers: ", sum - temp)

############################################################################

sum = datetime.now()
temp = sum
f = open('1000000.txt')
for i in range(10):
    a = []
    for j in range(100000):
        a.append(int(f.readline()))

    start2 = datetime.now()
    quick_sort_3_way(a, 0, n - 1)
    end2 = datetime.now()
    sum = sum + (end2 - start2)

f.close()

print("3 way partition quick sort time with 10 parts of 100000 numbers: ", sum - temp)

##############################################################################################

print("Divide 10000000.txt file to 100 parts, each part have 100000 numbers")

n = 100000
sum = datetime.now()
temp = sum
f = open('10000000.txt')
for i in range(100):
    a = []
    for j in range(100000):
        a.append(int(f.readline()))

    start2 = datetime.now()
    quick_sort_2_way(a, 0, n - 1)
    end2 = datetime.now()
    sum = sum + (end2 - start2)

f.close()

print("2 way partition quick sort time with 100 parts of 100000 numbers: ", sum - temp)

############################################################################

sum = datetime.now()
temp = sum
f = open('10000000.txt')
for i in range(100):
    a = []
    for j in range(100000):
        a.append(int(f.readline()))

    start2 = datetime.now()
    quick_sort_3_way(a, 0, n - 1)
    end2 = datetime.now()
    sum = sum + (end2 - start2)

f.close()

print("3 way partition quick sort time with 100 parts of 100000 numbers: ", sum - temp)


