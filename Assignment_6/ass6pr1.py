class Password_manager:
    def __init__(self):
        self.old_pass=[]
    def get_password(self):
        return self.old_pass[-1] if self.old_pass else None
        #self.old_pass[-1] will return last element
        #if self.old_pass else None= is empty then return None instead of error
    def set_password(self,new_pass):
        if new_pass not in self.old_pass:
            self.old_pass.append(new_pass)  
    def is_correct(self,password):
        return password==self.get_password()
    

k=Password_manager()
while(True):  
    print("1.get password\n2.set password\n3.check password\n4.Exit")
    n=int(input("Enter the number : "))
    if n==1:
        print(k.get_password())
    elif n==2:
        password=input("Enter password : ")
        k.set_password(password)
    elif n==3:
        password=input("Enter password : ")
        if k.is_correct(password):
            print("Password is right.")
        else:
            print("Password you have entered is wrong.")
    elif n==4:
        print("Exiting Loop...")
        break
    else:
        print("Please Enter valid Number")