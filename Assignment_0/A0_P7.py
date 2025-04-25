print("Oranage cap")

#For input of Dhoni's run 
a1 = int(input("Enter dhoni's runs in first match : "))
a2 = int(input("Enter dhoni's runs in second match : "))

#For input of kohli's run
b1 = int(input("Enter kohli's runs in second match : "))
b2 = int(input("Enter kohli's runs in second match : "))

#for input of sachin's run
c1 = int(input("Enter sachin's runs in second match : "))
c2 = int(input("Enter sachin's runs in second match : "))

#printing total runs by each player
print(f"Total run scored by dhoni is {a1+a2}")
print(f"Total run scored by kohli is {b1+b2}")
print(f"Total run scored by sachin is {c1+c2}")

a = a1 + a2     #dhoni's total runs
b = b1 + b2     #kohli's total runs
c = c1 + c2     #sachin's total runs

if a > b :
    if a > c : 
        result = "dhoni" 
        run = a
    else: 
        result = "sachin" 
        run = c
else : 
    if b > c : 
        result = "kohli" 
        run = b
    else : 
        result = "sachin" 
        run = c

print(f"Orange cap goes to {result} with score of {run}")



