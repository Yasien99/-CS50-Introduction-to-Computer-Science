from cs50 import get_int

n = get_int("height=")

while n <= 0 or n > 8:
    n = get_int("height=")
    
for i in range(n):
    for j in range(n):
        if (i + j) < (n - 1):
            print(" ",end="")
        else:
            print("#", end="")
    print()    
            