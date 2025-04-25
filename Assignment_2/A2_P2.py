# Write a program that repeatedly asks the user to enter product names and prices. Store all
# of these in a dictionary whose keys are the product names and whose values are the prices.
# When the user is done entering products and prices, allow them to repeatedly enter a
# product name and print the corresponding price or a message if the product is not in the
# dictionary.

products = {}

while(True):
    product_name = input("Enter product name or 0 to exit: ")
    
    if product_name=='0': 
        break
    
    product_price = input("Enter the price of product: ")
    products[product_name] = product_price

# print(f"avlaible products are {products}")

while(True):
    product_name = input("Enter name of product to find its price or 0 to exit: ")
    
    if product_name=='0': 
        exit()
    
    product_price = products.get(product_name)
    
    if product_price: 
        print("price is", product_price)
    else: 
        print("Product is not in the dictionary")
