def numOfPieces(cuts):
    if cuts%2 == 0:
        return (cuts/2)**2          #square of half of the cuts..
    else:
        return cuts//2 * (cuts//2 +1)

 
n = int(input("Enter the number of inputs: "))
for i in range(n):
    cuts = int(input("\nEnter a cuts needed for 1 by 1 piece: "))
    print("Number of 1 by 1 pieces of chocolate bar: ", int(numOfPieces(cuts)))