def lexographicallyNext(word):
    words = [ord(i) for i in word]
    i = len(words)-1
    while (i != 0):
        if words[i] > words[i-1]:
            words[i], words[i-1] = words[i-1], words[i]
            return "".join([chr(word) for word in words])
        i -= 1
    return("no answer")

 
n = int(input("Enter the number of inputs: "))
for i in range(n):
    words = input("\nEnter the words: ")
    print("Next lexographical number: ", lexographicallyNext(words))