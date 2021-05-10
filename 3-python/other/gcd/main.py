def computeGCD(x, y):
   while(y):
       x, y = y, x % y
   return x

def menu():
    while True:
        try:
            choice = int(input("\nMenu\n1-Calculate GCD\n2-Exit\n:"))
            if(choice == 2):
                return
            elif(choice == 1):
                nums = (input("Please enter 2 integers (separate with ','): ")).split(",")
                result = computeGCD(int(nums[0]), int(nums[1]))
                print("result is:", result)
            else:
                raise
        except:
            print("wrong value entered")

menu()
