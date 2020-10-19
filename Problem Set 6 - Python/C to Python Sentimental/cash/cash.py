from cs50 import get_float

quaters = 0
dimes = 0
nickels = 0
pennies = 0
coins = 0 

n = get_float("owed: ")
while n < 0:
    n = get_float("owed: ")
n = n * 100
n = round(n)

# counting quaters
while n >= 25:
    n = n - 25
    quaters += 1
    
# counting dimes
while n >= 10:
    n = n - 10
    dimes +=1
    
# counting nickels
while n >= 5:
    n = n - 5
    nickels +=1

# counting pennies
while n >= 1:
    n = n - 1
    pennies +=1
    
coins = quaters + dimes + nickels + pennies 
print(coins)