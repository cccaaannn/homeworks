pizza_names = ["a","b","c"]
pizza_counts = {}


def add_pizza():
    new_pizza = input("pizza name")
    pizza_names.append(new_pizza)


def order_pizza():
    for index, pizza_name in enumerate(pizza_names):
        print("{}-){}".format(index+1,pizza_name))

    pizza_number = int(input("pizza number"))

    pizza_name = pizza_names[pizza_number-1]

    if(pizza_name in pizza_counts):
        pizza_counts.update({pizza_name:pizza_counts[pizza_name]+1})
    else:
        pizza_counts.update({pizza_name:1})


def show_ordered():
    for pizza_count in pizza_counts:
        print(pizza_count, pizza_counts[pizza_count])



while True:
    i = int(input("""
    0 add pizza
    1 order pizza
    2 show ordered
    """))

    if(i == 0):
        add_pizza()
    elif(i == 1):
        order_pizza()
    elif(i == 2):
        show_ordered()





