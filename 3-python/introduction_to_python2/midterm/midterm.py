# 1
word = "racecar"
if(word.lower()[::-1] == word):
    print("{} is a palindrome.".format(word))
else:
    print("{} is not a palindrome.".format(word))


# 2
import random
d = {}
for _ in range(10):
    num = random.randint(1, 50)
    if(num not in d):
        d.update({num:num%10})

print("Dictionary: {}".format(d))

l = []
for num in d.keys():
    if(num % 4 == 0 or num % 7 == 0):
        l.append(d[num])

print("The list is: {}".format(l))


# 3
print("*** Rock, Paper, Scissors Game ***")
for turn in range(1,4):
    firstp = input("Player1 enter your move: ").lower()
    secondp = input("Player2 enter your move: ").lower()

    if(firstp == secondp):
        print("No winners for round {}".format(turn))

    else:
        if("rock" not in [firstp, secondp]):
            if firstp == "scissors":
                print("fist player wins")
                break
            else:
                print("second player wins")
                break

        if("paper" not in [firstp, secondp]):
            if firstp == "rock":
                print("fist player wins") 
                break
            else:
                print("second player wins") 
                break

        if("scissors" not in [firstp, secondp]):
            if firstp == "paper":
                print("fist player wins") 
                break
            else:
                print("second player wins") 
                break
else:
    print("---- GAME OVER ----\ndraw")

