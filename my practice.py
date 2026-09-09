# for w in range(0,22,2):
#     print(w)
# a=100
# i = 1
#
# while i <= a:
#
#     print(i)
#     i+=1
# #ans 1
# for i in range(3,31,3):
#     print(i)
# #ans 2
# for i in range(5,0,-1):
#     print(i)
# #ans 3
# for i in range(100,19,-20):
#     print(i)
#
#
# # ans 1
# for i in range(1,31):
#     if i %3 == 0 and i %5 == 0:
#         print('FIZZBUZZ')
#
#     elif i % 3 == 0:
#         print("FIZZ")
#     elif i % 5 ==  0:
#         print("BUZZ")
#     else:
#         print(i)
# # ans 2
# num = 0
# for i in range(1,101):
#     if i%2==0:
#         num +=i
# print(num)
#
# # ans 3
# bar = ''
# for i in range(0,11):
#     bar+="#"
#     print(bar)
# # ans 1
# count = 0
# for i in range(1,101):
#     if i %4 ==0 and i %6 == 0:
#         count+=1
# print(count)
# # ans 2
# text = "programming is a great skill"
# count = 0
# for i in text:
#     if i =='a' or i =='e' or i == 'i' or i == 'o' or i == 'u':
#         count+=1
# print(count)
#
#
#
# # ans 3
# for i in range(1,101):
#     if i % 7 == 0 and i%9==0:
#         print(i)
#         break
# # ans 1
# for i in range(1,21):
#     if i%3==0 :continue
#     print(i)
#
# # ans2
# list1 = [1,2,3,4,5]
# sqdlist=[]
#
# for i in list1:
#
#     sqdlist.append(i*i)
# print(sqdlist)
# #ans 3
# ast= ''
# for i in range(3):
#     for j in range(3):
#        print('*',end=" ")
# print()
# # ans 1
# c= 1
#
# while c<=100:
#     print(c)
#     c+=1
# # ans 2
# d=5
# while d>=1:
#     print(d)
#     d-=1
# # ans 3
# a= 2
# while a <=20:
#     if a %2==0:
#         print(a)
#     a+=1
#
#
# # ans 1
# string= 'Quit'
# while True:
#     a=input('say something:\n')
#     print(f'you typed :{a}')
#     if a =='quit':
#         print('quiting the program' )
#         break
# #ans 2
# c1 = 100
# while c1 >1:
#     print(c1)
#
#     c1 = c1 / 2
#
# # ans3
# while True:
#     password = input('Enter the password:\n')
#     if password != 'python_pass':
#         print('Wrong Password Try Again!')
#     elif password =='python_pass':
#         print('Welcome!')
#         break
# # ans 1
# secret_number = 24
# while True:
#     a= (input('guess the number:\n'))
#     guess = int(a)
#     if guess == secret_number:
#         print('Perfect!\n You guessed the number')
#         break
#     elif guess <= secret_number:
#         print('too low')
#     elif guess >= secret_number:
#         print('too High')
# # ans 2
# total = 0
# count = 0
# while total <= 100:
#     total+=8
#     count+=1
#
# print(count)
# # ans 3
# letters =['a','b','c','d']
# while len(letters)>0:
#     a= letters.pop()
#     print(a)
#
# # ans 1
# is_prime= True
# num=int(input('Enter a Number :\n'))
# i = 2
# while i< num:
#         if num % i ==0:
#             is_prime = False
#             print("its not a prime number!")
#             break
#         i+=1
# else:
#     print('its a prime number')
# # ans 2
# a = 0
# b = 1
# while a <= 100 :
#     print(a)
#     a,b = b,a+b
# # STARTING DEF FUNCTIONS NOW!
#
# def my_name(name):
#     print(f"hello there {name}")
#     print(f"This is first def program {name}")
#
#
# my_name(input('enter your name'))
# def addition():
#     a = 12
#     b =3
#     add = a+b
#     print(add)
# addition()
# def sub():
#     a = 15
#     b = 3
#     sub = a - b
#     print(sub)
# def square(number):
#     res = number*number
#     return res
# sqd = square(5)
# sqd2= square(int(input('enter a number to get square root')))
# print(sqd)
# print(sqd2)
#
#
# # ans1
# def say_hello(name):
#     print(f"Hello There {name}")
#     print(f"Have a great day {name}")
# say_hello('mustansir')
#
# # ans2
# def say_hi(name):
#     print(f'hello {name} !')
#     print(f"have a nice day {name}")
# say_hi('mustansir')
#
# # ans3
# def adder(n1,n2):
#
#     adder_res = n1+n2
#     return adder_res
# res=adder(5,15)
# print(res)
#
#
# # ans 1
# def is_even(number):
#         if number %2 ==0:
#             return True
#
#
#         else:
#             return False
#
# fun=is_even(int(input('enter a number ')))
# print(f'the boolean value is :{fun}')
# # ans 2
# def greet(name='Guest'):
#     print(f'Welcome {name}!')
#     print(f'How are You {name}?')
# greet('mustansir')
# greet()
# # ans 3
# def cal_sum(my_list):
#     total = 0
#     for i in my_list:
#         total +=i
#     return total
# my_list = [1, 2, 3, 4, 5]
# sum_result = cal_sum(my_list)
# print(sum_result)
#
# def find_max(numbers):
#     max_so= numbers[0]
#     for num in numbers:
#         if num > max_so:
#             max_so = num
#     return max_so
#
# list1 =[8,9,7,5,6]
# bigg =  find_max(list1)
# print(f"the list{list1}")
# print(f'the biggest number: {bigg}')
#
#
# def odd_counter(numbers):
#     c = 0
#     for num in numbers:
#         if num % 2 != 0:
#             c += 1
#     return c
# lit = [1,2,3,4,5,6]
# lst = odd_counter(lit)
# print(f"helo user:{lst}")
#
#
# def list_printer(items):
#     for item in items:
#         print(item)
#     return item
# lst=['apple','banana','cherry']
# list_printer(lst)
#
# def sum_list(numbers):
#     total = 0
#     for num in numbers:
#         total += num
#     return total
# ls = [1,2,3,4]
# result = sum_list(ls)
# print(result)
#
# def odd(numbers):
#     count =0
#     for num in numbers:
#         if num %2 !=0:
#             count +=1
#     return count
# mu = [1,2,3,4,5,6,7]
# result = odd(mu)
# print(result)
#
#
# # ans 1
# def get_positive(numbers):
#     positive =[]
#     for num in numbers:
#         if num > 0 :
#             positive.append(num)
#     return positive
# heh = [1,-1,-2,2,6,7,-74]
# a = get_positive(heh)
# print(a)
# # ans 2
# def get_square(numbers):
#     sqd = []
#     for num in numbers:
#         sqd_num = num*num
#         sqd.append(sqd_num)
#     return sqd
# i = [1,2,3,4]
# ans = get_square(i)
#
# print(ans)
# def finder(items,value):
#     for num in items:
#         if num == value:
#             return True
#
#     return False
# print(finder(['apple', 'banana', 'cherry'], 'banana'))
# print(finder(['apple', 'banana', 'cherry'], 'orange'))
#
# def join(list_str):
#     result =""
#     for i in list_str:
#         result +=i + ' '
#     return result
# a1=join(['Hello', 'my', 'name', 'is', 'Gemini'])
# print(a1)
#
#
# def is_odd(number):
#     return number % 2 != 0
#
#
# def get_odd_numbers(numbers):
#     odd_list = []
#     for num in numbers:
#
#         if is_odd(num) == True:
#             odd_list.append(num)
#
#     return odd_list
#
#
# my_numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# result = get_odd_numbers(my_numbers)
#
# print(result)
#
# def get_filter(numbers):
#     sqd_lst=[]
#     for num in numbers:
#         if num %2 == 0:
#             sqd = num*num
#             sqd_lst.append(sqd)
#     return sqd_lst
# lst =[1,2,3,4,5,6]
# ll=get_filter(lst)
# print(ll)
# # ans 1
# def cal_avg(numbers):
#     total = 0
#     count = 0
#     for num in numbers:
#         total+=num
#         count+=1
#         result = total / count
#     return result
# lst=[10,20,30,40]
# avg = cal_avg(lst)
# print(avg)
# #ans 2
# def find_long(words,min_len):
#     lst=[]
#     for i in words:
#         if len(i) > min_len:
#             lst.append(i)
#     return lst
# print(find_long(['apple', 'hi', 'banana', 'go', 'cherry'], 4))
# # ans 3
# def format_greetings(names):
#     lst = []
#     for name in names:
#         name=f'hello {name}!'
#         lst.append(name)
#     return lst
# print(format_greetings(['allice' , 'mustansir']))
# # ans 4
# def get_index(items,value):
#     for i in range(len(items)):
#         if items[i] == value:
#             return i
#     return -1
# print(get_index(['a', 'b', 'c', 'd'], 'c'))
# # ans 5
# def get_positives(numbers):
#     lst=[]
#     for num in numbers:
#         if num > 0:
#             double_num = num*2
#             lst.append(double_num)
#     return lst
# print(get_positives([-2,-1,0,1,2,3]))
# # ans 1
# def count_starts(words,letter):
#     count = 0
#     for word in words:
#         if word.startswith(letter) :
#             count+=1
#     return count
# print(count_starts(['apple', 'ant', 'banana', 'apricot'], 'a'))
#
# # ans 2
# def get_length(words):
#     lst = []
#     for word in words:
#         lst.append(len(word))
#     return lst
# print(get_length(['hello' , 'hi' , 'name']))
#
# # ans 3
# def avg_positives(numbers):
#     pt = 0
#     pc = 0
#     for num in numbers:
#         if num > 0:
#             pt+=num
#             pc+=1
#     return round(pt/pc,2)
# print(avg_positives([1, -2, 3, 4, -5]))
# # ans 1
# car={"make":'ford',
#      "model":'Mustang',
#      "year":1964}
# print(car["model"])
# # ans 2
# Person = {"name": 'mustansir','city': 'pune'}
#
# Person['job'] ='Programmer'
# Person['city'] = 'san francisco'
# print(Person)
#
# # ans 3
# stock = {"apples":50, "bananas":50,"oranges":50}
# for key, value in stock.items():
#     print(f"we have {key} {value}")
#
# # ans 1
# stock = {"apples":50, "bananas":50}
# if 'oranges' in stock:
#     print("we have oranges !")
# else:
#     print("we are out of oranges")
#
# # ans 2
# student = {'name':'mustansir','grades':[95,47.7,85]}
# print(student['grades'][2])
# # ans 3
# words = ['apples','banana','oranges']
# dict ={}
# for i in words:
#     # print(len(i))
#     dict[i] = len(i)
#     print(dict)
# count = 0
# while count <21  :
#     print(count)
#     count+=2
# user = {
#     "username": "coder123",
#     "profile": {
#         "first_name": "Alice",
#         "last_name": "Smith"
#     }
# }
#
# print(user["profile"]['last_name'])
# # ans 2
#
# stock={'apples':50, 'oranges':0}
# print(stock.get('apples'))
# print(stock.get('oranges'))
# # ans 3
# votes = ["apple", "banana", "apple", "orange", "banana", "apple"]
# vote_count={}
# for fruits in votes:
#     if fruits not in vote_count:
#         vote_count[fruits] =1
#     else:
#         vote_count[fruits] +=1
# print(vote_count)
#
# student_record = {
#     "name": "Bob",
#     "grades": {
#         "math": 85,
#         "history": 92
#     }
# }
#
# up=student_record["grades"]['math']=90
# print(student_record)
#
# dict1 = {"a": 1, "b": 2}
# dict2 = {"b": 3, "c": 4}
#
# a=dict1.update(dict2)
# print(dict1)
#
# string = 'hello'
# letter = {}
# for char in string:
#     if char not in letter :
#         letter[char] = 1
#     else:
#         letter[char] +=1
# print(letter)
# # ans 1
# numbers = [1,2,2,3, 1, 1, 4, 2]
# empdic={}
# for i in numbers:
#     if i not in empdic:
#         empdic[i] =1
#     else:
#         empdic[i] +=1
#
# print(empdic)
#
# # ans 2
# user = {'name':"alice","age":25,"city":"NYC"}
# removed_age = user.pop('age')
# print(removed_age)
# print(user)
#
# # ans 3
# stock ={'apples':50 , 'banana': 25, 'oranges':45}
# total = 0
# for value in stock.values():
#     total += value
# print(total)
# # ans 4
# def print_pro(pro_dict):
#     for key,value in pro_dict.items():
#         print(f"keys are {key} and values are {value}")
#
# print_pro({'name':"alice","age":25,"city":"NYC"})
# print('')
# print_pro({"name": "Bob", "job": "Plumber"})
# # ans 5
# def create_user(name,age,city):
#     user = {"name": name,"age":age,"city":city}
#     return user
# print(create_user("mustansir",19,"pune"))
# # ans 1
# my_dict ={"a":1,"b":2,'c':3}
# inverted_dict = {}
#
# for key,value in my_dict.items():
#     inverted_dict[value] = key
# print(inverted_dict)
# # ans 2
# stock = {"apples": 50, "bananas": 20, "oranges": 35, "grapes": 10}
# low_stock={}
# for fruit,count in stock.items():
#     if count  < 25:
#         low_stock[fruit] = count
# print(low_stock)
#
# # ans 3
# user_permissions = {"admin": True, "user": True, "guest": False}
# for a in user_permissions.keys():
#     print(a)
#
# #ans 1
# data = [("name", "Alice"), ("job", "Engineer"), ("age", 30)]
# profile = {}
#
# for key,value in data:
#     profile[key] = value
# print(profile)
#
# # ans 2
# error_codes = { 200: "OK", 404: "Not Found", 500: "Server Error", 301: "Moved Permanently" }
# def get_error(code):
#     message = error_codes.get(code,'unknown Error')
#     return message
#
# print(get_error(404))
# print(get_error(101))
# # ans 3
# user_data = {}
# user1_info = {'first':'alice','last':"brown"}
# user_data["alice123"] = user1_info
# user_data["bob_b"] = {"first": "Bob", "last": "Brown"}
# print(user_data)
# user_database = {
#     "alice123": {
#         "first": "Alice",
#         "last": "Smith",
#         "city": "NYC"
#     },
#     "bob_b": {
#         "first": "Bob",
#         "last": "Brown",
#         "city": "London"
#     }
# }
#
# # --- This is the database we start with ---
# user_database = {
#     "alice123": {
#         "first": "Alice",
#         "last": "Smith",
#         "city": "NYC"
#     },
#     "bob_b": {
#         "first": "Bob",
#         "last": "Brown",
#         "city": "London"
#     }
# }
#
#
# def get_user_summary(database, username):
#     if username not in database:
#         return "User not found"
#
#     user_info = database[username]
#
#     first_name = user_info["first"]
#     last_name = user_info["last"]
#     city = user_info["city"]
#
#     return f"{first_name} {last_name} lives in {city}"
#
#
# print(get_user_summary(user_database, "bob_b"))
# print(get_user_summary(user_database, "charlie_d"))
# car = {"make":'ford',
#        "model":"mustang",
#        'year':1964}
# print(car)
#
# person = {"name": "Alice", "city": "New York"}
# person['job'] = 'programmer'
# person['city'] ='los santos'
# print(person)
#
# stock ={"apples":50,
#         'banana':45,
#         "peach":85}
# for key, value in stock.items():
#     print(f'keys are{key} and values are {value}')
#
# stock = {"apples": 50, "bananas": 20}
# if  "oranges"  in stock.items() :
#     print('we have oranges!')
# else:
#     print('we are out of oranges')
#
# student = {"name": "Alice", "grades": [88, 92, 95]}
# print(student["grades"][1])
#
# words = ["apple", "banana", "cherry"]
# wod = {}
# for word in words:
#     len(word)
#     wod[word] = len(word)
# print(wod)
#
# user = {
#     "username": "coder123",
#     "profile": {
#         "first_name": "Alice",
#         "last_name": "Smith"
#     }
# }
#
# print(user["profile"]["last_name"])
#
#
# stock = {"apples": 50}
# print(stock.get('apples'))
# print(stock.get('oranges'))
#
# votes = ["apple", "banana", "apple", "orange", "banana", "apple"]
# vote_count = {}
# for fruit in votes:
#     if fruit not in vote_count:
#         vote_count[fruit] =1
#     else:
#         vote_count[fruit] += 1
# print(vote_count)
#
#
#
# user = {"name": "Alice", "age": 25, "city": "NYC"}
# removed= user.pop("age")
# print(removed)
# print(user)
# stock = {"apples": 50, "bananas": 20, "oranges": 35}
# total = 0
# for values in stock.values():
#     total += values
# print(total)
# def print_profile(pro_dict):
#     for key , value   in pro_dict.items():
#         print(f'keys {key} ,and the values are :{value}')
# print_profile({"name": "Bob", "job": "Plumber"})
#
# def create_user(name,age,city):
#     user = {'name':name,'age':age,'city':city}
#     return user
# new_person = create_user("Eve", 30, "London")
# print(new_person)
#
# student_record = {
#     "name": "Bob",
#     "grades": {
#         "math": 85,
#         "history": 92
#     }
# }
# student_record['grades']['math'] +=5
# print(student_record)
#
#
# my_dict = {"a": 1, "b": 2, "c": 3}
# inverted_dict = {}
# for key,value in my_dict.items():
#     inverted_dict[value] = key
#
# print(inverted_dict)
#
# stock = {"apples": 50, "bananas": 20, "oranges": 35, "grapes": 10}
# low_stock = {}
# for fruit, count in stock.items():
#     if count <25:
#         low_stock[fruit] =count
# print(low_stock)
#
# data = [("name", "Alice"), ("job", "Engineer"), ("age", 30)]
# profile  = {}
# for key,value in data:
#     profile[key] = value
# print(profile)
#
# error_codes = { 200: "OK", 404: "Not Found", 500: "Server Error" }
# def error_msg(code):
#     message = error_codes.get(code,'unknown message')
#     return message
# print(error_msg(404))
#
# print(error_msg(101))
#
# dict1 = {"a": 1, "b": 2}
# dict2 = {"b": 3, "c": 4}
# dict1.update(dict2)
# print(dict1)
#
# prices = {"apple": 0.5, "banana": 0.2, "orange": 0.4}
# sale_prices = {}
# for fruits,price in prices.items():
#     if price <0.4:
#         sale_price=price * 0.9
#         sale_prices[fruits] = sale_price
# print(sale_prices)
#
# def words_start(word):
#     length = len(word)
#     f_letter = word[0]
#     return {"length": length, "first_letter": f_letter}
#
#
# def process_data(data):
#     results = {}
#
#     for word in data:
#         stats = words_start(word)
#
#         results[word] = stats
#
#     return results
#
#
# print(process_data(["hello", "world"]))
# stock = {"apples": 50, "bananas": 20, "oranges": 35}
# for i in stock.keys():
#     stock[i] += 10
# print(stock)
#
# morse_code = {"H": "....", "E": ".", "L": ".-..", "O": "---"}
# message = ["H", "E", "L", "L", "O"]
# morse_message = []
# for letter in message:
#     code  = morse_code[letter]
#     morse_message.append(code)
# print(morse_message)
#
# scores = {"A": 1, "E": 1, "G": 2, "T": 1}
#
# hand = ["A", "E", "G", "T", "A"]
# total_score = 0
#
# for letter in hand:
#     score = scores[letter]
#     total_score += score
# print(total_score)
#
# user_database = {
#     "alice123": {"city": "NYC", "age": 25},
#     "bob_b": {"city": "London", "age": 42}
# }
# #
# def find_user_city(database, username):
#     if username  in database:
#         user_info = database[username]
#         city = user_info['city']
#         return city
#     elif username not in database:
#         return  'User Not Found'
# print(find_user_city(user_database, "alice123"))
#
# print(find_user_city(user_database, "carol_c"))
#
# salaries = {"Alice": 50000, "Bob": 60000, "Carol": 70000}
# for name in salaries.keys():
#     amt = salaries[name]
#     amt+=2000
#     salaries[name] = amt
# print(salaries)
# grades = {"Alice": 85, "Bob": 42, "Carol": 94, "David": 68}
# passing_students = {}
# for student, grade in grades.items():
#     if grade >=60:
#         passing_students[student] =grade
# print(passing_students)
#
#
# def add_item_safely(inventory, item, quantity):
#    if item in inventory:
#        inventory[item]+=quantity
#    elif item not in inventory:
#        inventory[item] = quantity
# my_inventory  = {"apples": 10}
#
# add_item_safely(my_inventory, "bananas", 20)
#
# print(my_inventory)
# add_item_safely(my_inventory, "apples", 5)
# print(my_inventory)
#
#
# users = [
#     {"name": "Alice", "city": "NYC"},
#     {"name": "Bob", "city": "London"},
#     {"name": "Carol", "city": "NYC"},
#     {"name": "David", "city": "Tokyo"}
# ]
# city_counts = {}
# for user in users:
#     city = user["city"]
#     if city not in city_counts:
#         city_counts[city] = 1
#     else:
#         city_counts[city] +=1
#
# print(city_counts)
#
# def update_stock(shop,product,amount):
#     if product in shop:
#         shop[product] += amount
#     else:
#         shop[product] = amount
#
# shop = {"eggs": 12}
# update_stock(shop, "milk", 2)
# print(shop)
# update_stock(shop, "eggs", 6)
# print(shop)
#
# votes = ["yes", "no", "yes", "maybe", "no", "yes"]
# result = {}
# for vote in votes:
#     if vote not in result:
#         result[vote] = 1
#     else:
#         result[vote] +=1
# print(result)
# temperatures = {"London": 15, "Paris": 22, "Oslo": 5, "Madrid": 25}
# warm_cities  = {}
# for city,count in temperatures.items():
#     if count >20 :
#         warm_cities[city] = count
# print(warm_cities)
#
# cart1 = {"apple": 2, "banana": 3}
# cart2 = {"apple": 1, "orange": 5}
# for items,quantities in cart2.items():
#     if items in cart1:
#         cart1[items] += cart2[items]
#
#     else:
#         cart1[items] =quantities
# print(cart1)
#
# words = ["apple", "banana", "apricot", "blueberry", "cherry"]
# grouped = {}
# for word in words:
#     first_word = word[0]
#     if first_word not in grouped:
#         grouped[first_word] = []
#     grouped[first_word].append(word)
# print(grouped)
# #
# votes = {"Alice": 150, "Bob": 200, "Charlie": 120}
# winner = ""
# max_count = 0
# for name,count in votes.items():
#     if count > max_count:
#         max_count = count
#         winner = name
# print(winner)
# numbers = [1, 2, 3, 4, 5, 6]
# grouped = {}
# for number in numbers:
#     if number %2 == 0:
#         key_name = 'even'
#     else :
#         key_name = 'odd'
#
#     if key_name not in grouped:
#         grouped[key_name] = []
#     grouped[key_name].append(number)
# print(grouped)
#
# scores = {"Alice": 85, "Bob": 92, "Charlie": 78, "David": 92}
# best_student = ""
# highest_score = 0
# for student,score in scores.items():
#     if score > highest_score:
#         highest_score = score
#         best_student = student
# print(best_student)
# print(highest_score)
# #
# #
# words = ["cat", "tree", "dog", "bird", "frog"]
# by_length = {}
# for word in words:
#     len_key = len(word)
#
#     if len_key not in by_length:
#         by_length[len_key] = []
#     by_length[len_key].append(word)
#
# print(by_length)
#
# with open('C:/Users/Mustansir/Desktop/skills.txt.txt','w') as f:
#     f.write('I am learning DSA with Python.')
#
# with open('C:/Users/Mustansir/Desktop/skills.txt.txt','r') as f:
#     content = f.read()
#     print(content)
#
# with open('text.txt','w') as f:
#     f.write('fuck you everyone')
# with open('text.txt','a') as f:
#     f.write('\nyes fuck everyone i hate everyone and i am tied as fuck adn my legs are in pain!!')
# with open('log.txt','w') as f:
#     f.write('Day 1: System started\n')
# with open('log.txt','a') as f:
#     f.write('Day 2: User logged in\n')
# with open('log.txt','r') as f:
#     a = f.read()
#     print(a)
#
# new_scores = [100,250,500]
# with open('scores.txt','w') as f:
#     for score in new_scores:
#         if score >200:
#             f.write(str(score)+'\n')
#
# with open("prices.txt", "w") as f:
#     f.write("10\n")
#     f.write("20\n")
#     f.write("30\n")
# total = 0
# with open('prices.txt','r') as f:
#     for line in f:
#         line = line.strip()
#         price = int(line)
#         total += price
# print(total)
# with open("results.txt", "w") as f:
#     f.write("Alice,85\n")
#     f.write("Bob,40\n")
#     f.write("Charlie,65\n")
#     f.write("David,90\n")
#     f.write("Eve,55\n")
#
# pass_count = 0
# with open('results.txt','r') as f:
#     for line in f:
#         line = line.strip()
#         parts = line.split(',')
#         score = int(parts[1])
#         if score >=60:
#             pass_count+=1
# print(pass_count)
# def report_inventory(inventory):
#     for item,count in inventory.items():
#         if count == 0:
#             print(f'WARNING: {item} is out of stock')
#             continue
#         elif count <= 5 :
#             print(f'{item}: LOW STOCK {count}')
#         else:
#             print(f'{item}: In stock {count}')
# inv = report_inventory({'Apples': 10, 'Bananas': 0, 'Oranges': 5, 'Pears': 20})
#
# class Student:
#     def __init__(self,name,grade):
#         self.name = name
#         self.grade = grade
# student1 = Student('Mustansir', 'A')
#
# print(student1.name)
#
# class Book:
#     def __init__(self,title,author):
#         self.title = title
#         self.author = author
# My_book = Book('harry Porter','JK Rowling')
#
# print(f'I am reading {My_book.title}  by {My_book.author}')
#
# class Laptop:
#     def __init__(self,brand):
#         self.brand = brand
#         self.is_on = False
# my_laptop = Laptop("Dell")
#
# print(my_laptop.is_on)
#
# class Person:
#     def __init__(self,name):
#         self.name = name
#     def say_hello(self):
#         print(f'Hello my name is {self.name}')
# name = Person('Mustansir')
# name.say_hello()
#
# class Car:
#     def __init__(self,brand,color):
#         self.brand = brand
#         self.color = color
#     def show_info(self):
#         print(f'This is {self.color} {self.brand}')
# cars = Car('Toyota','Red')
# cars.show_info()
#
# class Counter:
#     def __init__(self):
#         self.count = 0
#     def increment(self):
#         self.count += 1
# my_c= Counter()
# my_c.increment()
# my_c.increment()
# print(my_c.count)
#
#
# class BankAccount:
#     def __init__(self):
#         self.bal = 0
#     def deposit(self , amount):
#         self.bal += amount
# acc = BankAccount()
# acc.deposit(100)
# acc.deposit(50)
# print(acc.bal)
#
# class TodoList:
#     def __init__(self):
#         self.task = []
#     def add(self, task_name):
#         self.task.append(task_name)
# t = TodoList()
# t.add('WORK')
# t.add('PROGRAMME')
# print(t.task)
#
# class Greater:
#     def __init__(self):
#         self.my_name = 'Bot'
#     def greet_Person(self,user_name):
#         print(f'Hello {user_name}, I am {self.my_name}')
# greet = Greater()
# greet.greet_Person('Mustansir')
# # q1
# class Dog:
#     def __init__(self,name,breed):
#         self.name = name
#         self.breed = breed
#         print(f'{self.name} is a {self.breed}')
# Dog('Buddy','Golden Retriever')
# # q2
# class Rectangle:
#     def __init__(self,width,height):
#         self.width = width
#         self.height = height
#     def get_area(self):
#        return self.width * self.height
# area = Rectangle(5,10)
# result = (area.get_area())
# print(result)
#
# # q3
# class Phone:
#     def __init__(self):
#         self.battery = 100
#
#     def use_app(self):
#         self.battery -= 10
# p = Phone()
# p.use_app()
# p.use_app()
# p.use_app()
# print(p.battery)
# # q4
# class  Cart:
#     def __init__(self):
#         self.items =[]
#     def add_item(self,item_name):
#         self.items.append(item_name)
# cart = Cart()
# cart.add_item('apple')
# cart.add_item('banana')
# cart.add_item('milk')
# print(cart.items)
#
#
# # q5
# class Bank:
#     def __init__(self):
#         self.balance = 100
#     def withdraw(self,amount):
#         if amount <= self.balance:
#             print(f'Withdraw {amount}')
#             self.balance -= amount
#         else:
#             print("Insufficient funds!")
# acc = Bank()
# acc.withdraw(150)
# acc.withdraw(50)
# print(acc.balance)
# # q6
# class Student:
#     def __init__(self,name,score):
#         self.name = name
#         self.score = score
#     def is_passing(self):
#         if self.score >=60:
#             return True
#         else:
#             return  False
# s = Student('Mustansir',75)
# print(s.is_passing(),f'{s.name} is Passing!')
# s = Student('luke',55)
# print(s.is_passing(),f'{s.name} is Not Passing!')
# # q7
# class Employee:
#     def __init__(self,name,salary):
#         self.name = name
#         self.salary = salary
#     def give_raise(self,amount):
#          self.salary +=amount
#     def show_info(self):
#         print(f'{self.name} earns {self.salary}')
# emp = Employee('mustansir',50000)
# emp.give_raise(5000)
# emp.show_info()
#
# class Course:
#     def __init__(self,title):
#         self.title = title
# class Student:
#     def __init__(self,name):
#         self.name = name
#     def enroll(self,course):
#         print(f'{self.name}  has enrolled in {course.title}')
# c = Course('Python DSA')
# s = Student('Mustansir')
# print(s.enroll(c))
#
# class Weapon:
#     def __init__(self,name,damage):
#         self.name  = name
#         self.damage = damage
# class Player:
#     def __init__(self,name):
#         self.name = name
#         self.health = 100
#     def take_damage(self,weapon_object):
#         self.health -=weapon_object.damage
#         print(f'{self.name} was hit by {weapon_object.name} for {weapon_object.damage}' )
# w = Weapon('Sword',20)
# p = Player('Mike')
# p.take_damage(w)
#
#
# class Acc:
#     def __init__(self,balance):
#         self.balance = balance
#     def transfer(self,other_acc,amount):
#         self.balance -= amount
#         other_acc.balance +=amount
# a1= Acc(100)
# a2= Acc(0)
# a1.transfer(a2,50)
# print(a1.balance)
# print(f'the balance of account 1 is {a2.balance}')
# print(f'the balance of account 2 is {a1.balance}')
#
# class Car:
#     def __init__(self,model):
#         self.model = model
#         self.is_broken = True
# class Mechanic:
#     def __init__(self,name):
#         self.name = name
#     def repair(self,car_object):
#         car_object.is_broken =False
#         print(f'{self.name} fixed {car_object.model}')
# c =Car('Toyota')
# m = Mechanic('Joe')
# m.repair(c)
#
# class Dog:
#     def __init__(self,name):
#         self.name = name
#         self.happiness = 0
# class Owner:
#     def __init__(self,name):
#         self.name =name
#     def walk_dog(self,dog_object):
#         dog_object.happiness +=10
#         print(f'{self.name} walked {dog_object.name}')
# d = Dog('Buddy')
# o = Owner('Alice')
# o.walk_dog(d)
#
# class Fighter:
#     def __init__(self,name):
#         self.name =name
#         self.hp = 50
# class Healer:
#     def __init__(self,name):
#         self.name = name
#         self.mana = 100
#
#     def heal(self,fighter_object):
#         fighter_object.hp += 20
#         self.mana -=10
# f = Fighter('conon')
# h = Healer('mercy')
# h.heal(f)
# print(f'{f.hp}')
# print(f'{h.mana}')
# # q1
# class Product:
#     def __init__(self ,name ,price):
#         self.name =name
#         self.price = price
# class Customer:
#     def __init__(self,name,money):
#         self.name =name
#         self.money = money
#     def buy(self,product_object):
#         self.money -= product_object.price
#         print(f'{self.name}  bought {self.name} for ${product_object.price}')
# p = Product('laptop',67)
# c = Customer('alice' , 100)
# c.buy(p)
# print(f'alice balance is:${c.money}')
# # q2
# class Person:
#     def __init__(self,name,wallet):
#         self.name = name
#         self.wallet = wallet
# class Thief:
#     def __init__(self,name):
#         self.name =name
#         self.loot = 0
#     def steal(self,victim_object,amount):
#         victim_object.wallet -= amount
#         self.loot +=amount
#         print(f'{self.name} Stole ${amount} from {victim_object.name}')
# p =Person('Frank',500)
# th = Thief('sly')
# th.steal(p,154)
# print(f'{p.wallet} ')
# print(f'{th.loot} ')
# # q3
# class Post:
#     def __init__(self,content):
#         self.content = content
#         self.likes = 0
#
# class User:
#     def __init__(self,username):
#         self.username= username
#
#     def Like_post(self,Post_object):
#         Post_object.likes +=1
#         print(f'{self.username}  Liked the Post :{Post_object.content}')
# P = Post('I Love Python!')
# U =User('Mustansir')
# U.Like_post(P)
# print(f'{P.likes}')
# # q1
# class Vehicle:
#     def __init__(self,brand):
#         self.brand = brand
#     def drive(self):
#         print(f'The {self.brand} is moving')
#
# class car(Vehicle):
#     def honk(self):
#         print('Beep! Beep!')
# my_new = car('toyota')
# my_new.drive()
# my_new.honk()
# # q2
# class Employee:
#     def __init__(self,name,salary):
#         self.name = name
#         self.salary = salary
#     def show_details(self):
#         print(f'{self.name} earns {self.salary}')
# class  Manager(Employee):
#     def fire_someone(self):
#         print('Your Fired')
# so = Manager("Boss",100000)
# so.show_details()
# so.fire_someone()
# # q3
# class Pet:
#     def __init__(self,name):
#         self.name = name
#     def eat(self):
#         print('Munch munch')
# class cat(Pet):
#     pass
#
# s = cat('Kitty')
# # s.eat()
# # q1
# class Bird:
#     def fly(self):
#         print('I am Flying High!')
# class Penguin(Bird):
#      def fly(self):
#          print('I cannot fly,but can swim')
# b = Bird()
# p = Penguin()
# b.fly()
# p.fly()
# # q2
# class Employee:
#     def Calculate_pay(self):
#         print('Calculating basic salary')
# class Intern(Employee):
#     def Calculate_pay(self):
#         print('Interns dont get paid! :(')
# empl = Employee()
# intern = Intern()
# empl.Calculate_pay()
# intern.Calculate_pay()
# # q3
# class Vehicle:
#     def move(self):
#         print('Moving on Road')
# class Plane(Vehicle):
#     def move(self):
#         print('Flying in sky!')
# v = Vehicle()
# p = Plane()
# v.move()
# p.move()
# # q1
# class Employee:
#     def __init__(self,name,salary):
#         self.name =name
#         self.salary = salary
# class Manager(Employee):
#     def __init__(self,name,salary,bonus):
#         super().__init__(name,salary)
#         self.bonus  =bonus
# manager = Manager("alice",50000,10000)
# print(manager.name)
# print(manager.bonus)
# # q2
# class Person:
#     def greet(self):
#         print("Hello!")
# class FriendlyPerson(Person):
#     def greet(self):
#         super().greet()
#         print('How are you Today?')
# friend = FriendlyPerson()
# friend.greet()
# # q3
# class Car:
#     def __init__(self,brand,model):
#         self.brand = brand
#         self.model = model
#     def show_info(self):
#         print(f'{self.brand} {self.model}')
# class ElectricCar(Car):
#     def __init__(self,brand,model,battery_size):
#         super().__init__(brand,model)
#         self.battery_size =battery_size
# EV = ElectricCar('tesla','model S',100)
# EV.show_info()
# n = int(input('enter the number of rows'))
# for i in range(0,n):
#     for j in range(0,i+1):
#         print('* ',end=' ')
#     print()
# class CoffeeMachine:
#     def __init__(self):
#         self.balance = 0
#         self.menu = {"Espresso": 5, "Latte": 10, "Cappuccino": 8}
#     def insert_money(self,amount):
#         self.balance +=  amount
#         print(f'balance: ${self.balance}')
#     def buy_drink(self,drink_name):
#         if drink_name not in self.menu:
#             print("Sorry, we don't have that.")
#             return
#         price = self.menu[drink_name]
#         if self.balance >= price:
#             self.balance -= price
#             print(f'Here is your {drink_name}!')
#             print(f'Remaining Balance: ${self.balance}')
#         else:
#             print("Not enough money.")
# machine =CoffeeMachine()
# machine.insert_money(15)
# machine.buy_drink('Latte')
# machine.buy_drink('Latte')
#
# class User:
#     def __init__(self,username):
#         self.username = username
#         self.friends = []
#     def add_friend(self,other_user_object):
#         if other_user_object in self.friends:
#             print('Already friends!')
#         else:
#             self.friends.append(other_user_object)
#             print(f'{self.username} is now friends with {other_user_object.username}')
#     def show_friends(self):
#         for f in self.friends:
#             print(f.username)
#
# u1 =User('Mustansir')
# u2 =User('Alice')
# u1.add_friend(u2)
# u1.show_friends()
#
# class Pokemon:
#     def __init__(self,name,hp,attack):
#         self.name = name
#         self.hp =hp
#         self.attack = attack
#     def hit(self,enemy_pokemon):
#         enemy_pokemon.hp -= self.attack
#         print(f'{self.name} hit {enemy_pokemon.name}! Enemy HP is now {enemy_pokemon.hp}')
# p1 =Pokemon("Pikachu", 100, 20)
# p2 =Pokemon("Charmander", 100, 25)
# while p1.hp>0 and p2.hp>0:
#     p1.hit(p2)
#     if p2.hp <= 0:
#         break
#     p2.hit(p1)
# print('Game Over!!')
# # STARTING 10 QUESTIONS!!
# class cirle:
#     def __init__(self,radius):
#         self.radius =radius
#     def   get_diameter(self):
#         return self.radius *2
#     def get_circumference(self):
#         return round(2*3.14*self.radius,2)
# c= cirle(5)
# print(c.get_circumference())
# class TrafficLight:
#     def __init__(self):
#         self.color = 'Red'
#
#     def change(self):
#         if self.color =='Red':
#             self.color ='Green'
#             print(self.color)
#         elif self.color =='Green':
#             self.color ='Yellow'
#             print(self.color)
#
#         elif self.color =='Yellow':
#             self.color ='Red'
#             print(self.color)
# t = TrafficLight()
# t.change()
# t.change()
# t.change()
# class MusicPlayer:
#     def __init__(self):
#         self.songs =[]
#     def add_songs(self,song_name):
#         self.songs.append(song_name)
#     def play_all(self):
#         for song in self.songs:
#             print(f'playing {song}')
# s = MusicPlayer()
# s.add_songs('Bohemian Rhapsody')
# s.add_songs('Stairway to Heaven')
# s.play_all()
# class student:
#     def __init__(self,name):
#         self.name = name
#         self.grade = 0
# class Teacher:
#     def __init__(self,name):
#         self.name = name
#     def grade_student(self,student_object ,score):
#         self.score = score
#         student_object.grade = score
#         print(f'{self.name} gave {student_object.name} a {score}')
# stu = student('john')
# t = Teacher('Mr.Smith')
# t.grade_student(stu,95)
#
# class Mouse:
#     def __init__(self,name):
#         self.is_alive = True
#         self.name = name
# class Cat:
#     def __init__(self,name):
#         self.name =name
#     def catch(self,mouse_object):
#         mouse_object.is_alive = False
#         print(f'{self.name} caught {mouse_object.name}')
# c = Cat('Tom')
# m = Mouse('jerry')
# c.catch(m)
#
# class Contacts:
#     def __init__(self,name,phone):
#         self.name = name
#         self.phone = phone
# class Phone:
#     def __init__(self):
#         self.contacts = []
#     def add_contacts(self,contacts_obj):
#         self.contacts.append(contacts_obj)
#     def show_contacts(self):
#         for contact in self.contacts:
#              print(f'{contact.name} :{contact.phone}')
# con = Contacts('Mom','9887825086')
# p = Phone()
# p.add_contacts(con)
# p.show_contacts()
# class Device:
#     def __init__(self,brand):
#         self.brand = brand
#
# class Phone(Device):
#     def __init__(self,brand,model):
#         super().__init__(brand)
#         self.model = model
#         print(f'{self.brand} : {self.model}')
# p = Phone('apple','iphone 17')
# class enemy:
#     def Attack(self):
#         print("Deals 10 damage")
# class Boss(enemy):
#     def Attack(self):
#         print("Deals 50 damage! CRITICAL HIT!")
# att  = Boss()
# att.Attack()
# class Rocket:
#     def __init__(self):
#         self.fuel = 0
#     def add_fuel(self,amount):
#         self.fuel += amount
#         print(f"Fuel added. Current fuel: {self.fuel}")
#     def launch(self):
#         if self.fuel >= 100:
#             print("Lift off!")
#             self.fuel -= 100
#         else:
#             print("Not enough fuel!")
# r = Rocket()
# r.add_fuel(50)
# r.launch()
# r.add_fuel(60)
# r.launch()
# class ATM:
#     def __init__(self):
#         self.balance =1000
#         self.pin =1234
#     def withdrawl(self,entered_pin,amount):
#         if entered_pin != 1234:
#             print('Wrong PIN')
#         elif amount >self.balance:
#             print('Out of Cash')
#         else:
#             self.balance -= amount
#             print(f'Here is your money {amount}')
# atm= ATM()
# atm.withdrawl(int(input('enter the pin\n')),int(input('enter the amount to withdraw\n')))
# class Animal:
#     def __init__(self,species,name):
#         self.species = species
#         self.name = name
# class Zoo:
#     def __init__(self):
#         self.cages = []
#     def add_animal(self, species, name):
#         new_animal = Animal(species,name)
#         self.cages.append(new_animal)
#     def roll_call(self):
#         for c in self.cages:
#             print(f'{c.name} the {c.species}')
# z = Zoo()
# z.add_animal('Lion', 'Simba')
# z.add_animal('Zebra','Marty')
# z.roll_call()
#
# class Student:
#     def __init__(self,name,score):
#         self.name = name
#         self.score = score
# class Gradebook:
#     def __init__(self):
#         self.students = []
#     def add_student(self,name,score):
#         new_student = Student(name,score)
#         self.students.append(new_student)
#     def class_average(self):
#         total = 0
#         for stu in self.students:
#             total +=stu.score
#             print(total/len(self.students))
# g =Gradebook()
# g.add_student('alice',95)
# g.add_student('Bob',85)
# g.class_average()
# class Expense:
#     def __init__(self,item,cost):
#         self.item = item
#         self.cost = cost
# class Wallet:
#     def __init__(self):
#         self.expense =[]
#     def by_item(self,item,cost):
#         new_Expense = Expense(item,cost)
#         self.expense.append(new_Expense)
#         self.save_to_file()
#     def save_to_file(self):
#         with open('expenses.txt','w') as f:
#             for exp in self.expense:
#                 f.write(f'{exp.item}: ${exp.cost}\n')
# w = Wallet()
# w.by_item('Laptop',55000)
# w.by_item('Tablet',45000)
# w.save_to_file()
# # # STARTING MODULES
# import math
# number =25
# print(math.sqrt(number))
# print(math.pow(2,3))
# import random
# for i in range(3):
#     i = random.randint(1,6)
#     print(f'Rolled a {i}')
# import time
# print('starting...')
# time.sleep(2)
# print('finished')
# # DAY 8
# for i in range(0,21):
#     if i >= 15:
#         print(f'High: {i}')
#     else:
#         print(f'Low: {i}')
# def multiply(lis):
#     total = 1
#     for num in lis:
#         total *= num
#     return total
# result = multiply([2,3,4])
# print(result)
# profile = {"name": "Mustansir", "skills": ["Python", "HTML"]}
# print(profile['skills'][1])
# with open('day8.txt','w') as f:
#     f.write('Start of Day 8')
# class Cat:
#     def __init__(self,name,color):
#         self.name = name
#         self.color = color
#     def meow(self):
#         print(f'{self.name} say meow!')
# c = Cat('luna','black')
# c.meow()
# votes = ["A", "B", "A", "C", "A"]
# counts = {}
# for vote in votes:
#     if vote not in counts:
#         counts[vote] = 1
#     else:
#         counts[vote] += 1
# print(counts)
# prices = [5, 20, 3, 100, 50]
# exp = []
# for p in prices:
#     if p >= 10:
#         exp.append(p)
# print(exp)
# class box:
#     def __init__(self,item):
#         self.item = item
# class Person:
#     def __init__(self,name):
#         self.name = name
#     def take(self, box_object):
#         print(f'{self.name} took the {box_object.item}!!')
# b = box('Gold')
# p = Person('Thief')
# p.take(b)
# with open('day8.txt','a') as f:
#     f.write('\nUpdate: Batch 1 Complete')
# password = ''
# while True:
#     password = input('Enter:')
#     if password =='secret':
#         print('Access Granted!')
#         break
#     else:
#         print('Try Again!')
# users = {
#     "alice": {"age": 25, "city": "NYC"},
#     "bob": {"age": 30, "city": "London"}
# }
# print(users['bob']['city'])
# class Animal:
#     def speak(self):
#         print('sound')
# class Dog(Animal):
#         pass
# a= Dog()
# a.speak()
# class Bird:
#     def move(self):
#         print('flying')
# class Penguin(Bird):
#     def move(self):
#         print('swimming')
#
# p = Penguin()
# p.move()
# def analyze_word(word):
#     r = {'words':word,'length':len(word)}
#     return r
# a = analyze_word('python')
# print(a)
# with open('day8.txt','r') as f:
#     content= f.read()
# print(f'file says {content}')
# class Parent:
#     def __init__(self,name):
#         self.name = name
# class Child(Parent):
#     def __init__(self,name,age):
#         super().__init__(name)
#         self.age = age
# kid =Child("Samual",1)
# print(kid.name)
# print(kid.age)
# scores = {"Alice": 50, "Bob": 80, "Charlie": 65}
# max_score = 0
# winner = ''
# for name,score in scores.items():
#     if max_score < score:
#         max_score = score
#         winner = name
# print(winner)
# class Wallet:
#     def __init__(self,money):
#         self.money = money
#     def give(self,other_wallet,amount):
#         self.money -= amount
#         other_wallet.money += amount
# w1 = Wallet(100)
# w2  =Wallet(0)
# print(w1.money)
# w1.give(w2,50)
# print(w2.money)
# print(w1.money)
# # with open('nums.txt' , 'w') as f:
# #     f.write('10\n20\n30')
# total = 0
#
# with open('nums.txt','r') as f:
#     for line in f:
#         clean = line.strip()
#         number = int(clean)
#         total+=number
# print(total)
# number = [1, 2, 3, 4, 5, 6]
# evens = []
# for num in number:
#     if num % 2 == 0 :
#         evens.append(num)
# # print(evens)
# import my_tools
# from MINE.my_tools import connect
#
# result = my_tools.add(5,10)
# print(result)
#
# from my_tools import hello
# hello()
# import my_tools as db
# db.connect()
# import my_tools as pd
# print(pd.version)
# from my_tools import *
# connect()
# hello()
# import random
# prizes = ["Car", "Money", "Vacation"]
# result = random.choice(prizes)
# print(result)
# import datetime
# now  =datetime.datetime.now()
# print(now)
# # import os
# # os.remove('useless rishabh')
# import math
# print(math.pi)
# import json
# data = {"name": "Mustansir", "score": 100}
# json_string  = json.dumps(data)
# print(json_string)
# x = 10
# y = 0
# try:
#     print(x / y)
# except ZeroDivisionError:
#     print('cannot divide by zero')
# try:
#     int('hello')
# except ValueError:
#     print('That is not a number')
# try:
#     open("ghost_file.txt", "r")
# except FileNotFoundError:
#     print('the file does not exists')
# data = {'a':1}
# try:
#     print(data['b'])
# except KeyError:
#     print('that key is not in the dict')
# try:
#     import super_advanced_math
# except ImportError:
#     print('module not installed')
# print('calculator ready')
#
# st ='how are you today'
# print(st[6])
# nums = [1, 2, 3, 4, 5]
# double = [n * 2 for n in nums]
# print(double)
# numbers = [1, 2, 3, 4, 5, 6]
# even_squares = [n*n for n in numbers if n % 2 == 0]
# print(even_squares)
# names =[" alice ", " bob ", "charlie"]
# clean_names = [name.strip() for name in names]
# print(clean_names)
# matrix = [[1, 2], [3, 4]]
# flat = [num for row in matrix for num in row]
# print(flat)
# square  = lambda x: x * x
# print(square(5))
# prices = [10,20,30]
# lst = list(map(lambda num: num+5 ,prices))
# print(lst)
# ages = [12, 18, 25, 10, 30]
# lst1 = list(filter(lambda age: age>=18,ages))
# print(lst1)
# names = ["Alice", "Bob"]
# ages = [25, 30]
# for name, age in zip(names, ages):
#     print(f"{name} is {age}")
# racers = ["Sam", "Tom", "Alex"]
# for i,name in enumerate(racers):
#     print(f'Rank {i+1}: {name}')
# products = ["Laptop", "Mouse"]
# prices = [1000, 20]
# for pro,pri in zip(products,prices):
#     print(f'{pro} costs ${pri}')
# keys = ["name", "age", "job"]
# k = {k:'unknown' for k in keys}
# print(k)
# numbers = [1, 2, 3, 4]
# dic ={num:num*num for num in numbers }
# print(dic)
# pairs = [(1, 10), (3, 5), (2, 8)]
# pairs.sort(key=lambda num:num[1])
# print(pairs)
# nums = [10, 3, 20, 5]
# lis = ['high' if n > 9 else 'low' for n in nums]
# print(lis)
# sentence = 'Hello World Python'
# I = [len(i) for i in sentence.split()]
# print(I)
# # tasks = ["Wash dishes", "Dry clothes", "Fold laundry"]
# # for i,value in enumerate(tasks):
# #     print(f'{i+1} : {value}')
# # names = ["Alice", "Bob"]
# # scores = [85,92]
# # dic = (zip(names,scores))
# # print(dic)
#
# dic_by_3 = [a for a in range(0,21) if a % 3 == 0]
# print(dic_by_3)
# phrase = "National Aeronautics Space Administration"
# lst =[a[0:1] for a in phrase.split()]
# print(lst)
# animals =["Elephant", "Cat", "Hippo", "Dog"]
# animals.sort(key=lambda a: len(a))
# print(animals)
# prices = {"Laptop": 1000, "Mouse": 20, "Monitor": 200}
# dic = {k:v/1*0.9 for k,v in prices.items()}
# print(dic)
# data = [10, "error", 20, "bug", 30]
# lst = [item for item in data if isinstance(item,int) ]
# print(lst)
# class Rectangle:
#     def __init__(self,width,height):
#         self.width = width
#         self.height = height
#     def area(self):
#         return  self.width * self.height
# a = Rectangle(5,10)
# print(a.area())
# class Clicker:
#     def __init__(self):
#         self.count = 0
#     def click(self):
#         self.count += 1
#         return self.count
# c = Clicker()
# i = [print(c.click()) for i in range(5)]
# class Student:
#     def __init__(self,name,score):
#         self.name = name
#         self.score =score
#     def check(self):
#         if self.score >50:
#             return  'pass'
#         else:
#             return 'fail'
# c =Student('Tom',40)
# print(c.check())
# class wallet:
#     def __init__(self,money):
#         self.money  =money
#     def pay(self,amount):
#         self.money -= amount
# w =wallet(1500)
# w.pay(570)
# print(w.money)
# class Car:
#     def __init__(self,brand):
#         self.brand = brand
# brands = ["Toyota", "Ford", "BMW"]
# garage = []
# for b in brands:
#     new_car = Car(b)
#     garage.append(new_car)
# for car in garage:
#     if car.brand == "Ford":
#         print("Found the Ford!")
# c= (Car(["Toyota", "Ford", "BMW"]))
# print(c.brand)
# class Animal:
#     def __init__(self,name):
#         self.name = name
# class Dog(Animal):
#     def __init__(self,name,breed):
#         super().__init__(name)
#         self.breed = breed
# d =Dog('vashu','Xoloitzcuintli')
# print(d.name)
# print(d.breed)
# class Time:
#     def __init__(self,time):
#         self.time = time
#     def Get(self):
#         total_minutes = self.time
#         hr = total_minutes // 60
    #         mins = total_minutes % 60
#         return f'{hr} hrs and {mins} mins left!!'
# t = Time(int(input('enter the no_of Mins\n')))
# print(t.Get())
# class Phone:
#     def __init__(self,brand,model):
#         self.brand = brand
#         self.model = model
#     def show_info(self):
#         print(f'{self.brand} {self.model}')
# p = Phone('samsung','s21')
# p.show_info()
#
# class Rectangle:
#     def __init__(self,width,height):
#         self.width = width
#         self.height = height
#     def add_perimeter(self):
#         return (self.width + self.height) * 2
# r = Rectangle(25,15)
# print(r.add_perimeter())
# class ToDolist:
#     def __init__(self,):
#         self.tasks = []
#     def add_task(self,task):
#         self.tasks.append(task)
#         return self.tasks
# t = ToDolist()
# print(t.add_task('Focus on yourself'))
# class LightHouse:
#     def __init__(self,):
#         self.is_one = False
#     def Flick(self):
#         self.is_one = not self.is_one
#         print(self.is_one)
# l = LightHouse()
# l.Flick()
# l.Flick()
# class Calculator:
#
#     def Power(self,a,b):
#         return a**b
# cal = Calculator()
# print(cal.Power(5,5))
# class User:
#     def __init__(self,username):
#         self.username = username
#     def Login(self):
#         print(f'{self.username} has logged in!')
# u  = User('mustansir')
# u.Login()
#
# class Square:
#     def __init__(self,side):
#         self.side  = side
#     def area(self):
#         return self.side * self.side
# s = Square(5)
# print(s.area())
# class Lamp:
#     def __init__(self):
#         self.is_on = False
#     def Toggle(self):
#         self.is_on =  not self.is_on
#         print(self.is_on)
# l = Lamp()
# l.Toggle()
# l.Toggle()
# class Bank:
#     def __init__(self):
#         self.balance = 0
#     def deposit(self,amount):
#          self.balance += amount
# b = Bank()
# b.deposit(200)
# print(b.balance)
# class Book:
#     def __init__(self,title):
#         self.title = title
#         self.page = 0
#     def read(self,pages):
#         self.page += pages
#         print(f'current Page is:{self.page}')
# b = Book('Ikigai')
# b.read(1)
# b.read(5)
# b.read(10)
# class Roster:
#     def __init__(self):
#         self.player = []
#     def add(self,name):
#         self.player.append(name)
#         print(self.player)
# r = Roster()
# r.add('mustansir')
# r.add('adnan')
# class Animal:
#     def __init__(self,name):
#         self.name = name
#     def speak(self):
#         print(f'{self.name} says :Mow!')
# class Dog(Animal):
#     def __init__(self,name):
#         super().__init__(name)
#     def speak(self):
#         print(f'{self.name} says:Woof!')
# a = Dog('Dog')
# a.speak()
# class chef:
#     def __init__(self,name):
#         self.name = name
#     def cook(self,dish):
#         print(f'{self.name} cooks: {dish}')
# c = chef('ramsey')
# c.cook('beef hamilton')
# class Printer:
#     def __init__(self,model):
#         self.model = model
#     def Print_page(self,text):
#         print(f'{self.model} printing : {text}')
# p  =Printer('snake-eyes')
# p.Print_page('YOUR DONE 10 QUESTIONS')
# class Battery:
#     def __init__(self):
#         self.level = 100
#     def use(self):
#         if self.level >= 0:
#             self.level -= 10
#             self.level = max(0, self.level)
#             return self.level
# b = Battery()
# print(b.use())
# print(b.use())
# print(b.use())
# print(b.use())
# print(b.use())
# print(b.use())
# print(b.use())
# print(b.use())
# print(b.use())
# print(b.use()) # wont go below 0!!
# class Wallet:
#     def __init__(self,money):
#         self.money  = money
#     def can_buy(self,cost):
#         if self.money >=cost:
#             return True
#         else:
#             return False
# w = Wallet(120)
# print(w.can_buy(100))
# class Product:
#     def __init__(self,price):
#         self.price = price
#     def Discount(self,percentage):
#         p = self.price * (percentage/100)
#         self.price -= p
#         print(p)
# p = Product(1500)
# p.Discount(20)
# class Team:
#     def __init__(self):
#         self.members = []
#     def recruit(self,name):
#         if name not in self.members:
#             self.members.append(name)
#             print(self.members)
#         else:
#             print(f'{name} is  already a member!')
# t =Team()
# t.recruit('mustansir')
# t.recruit('adnan')
# t.recruit('adnan') # won't add the member!!
# class Lock:
#         def __init__(self,code):
#             self.code = code
#             self.status = 'Locked'
#         def unlock(self,try_code):
#             if try_code == self.code:
#                 self.status = 'Open'
#                 print('Open')
#             else:
#                 print('Wrong and your DONE!')
# l = Lock(1234)
# l.unlock(1234)
# l.unlock(9999) # won't open
# def safe_divide(a, b):
#     try:
#         print(a/b)
#     except ZeroDivisionError:
#         print("Error: Cannot divide by zero.")
#     finally:
#         print("Division attempt complete.")
# safe_divide(10,2)
# safe_divide(10,0)
# sum1 = 1
# i =1
# while i < 6  :
#     sum1 *= i
#     i+=1
# print(sum1)

# a = 10
# b= 20
# temp = a
# a = b
# b = temp
#
#
# print(a,b)
# for i in range(0,11):
#     i+=1
#     for j in range(i):
#         print('*',end=' ')
#     print()
n = 5
# for a in range(1,n,+1):
#     for i in range(n-a):
#         print(' ',end='')
#     for j in range(a * 2 - 1):
#         print('*',end='')
#     print()
# for a in range(n-1,0,-1):
#     for i in range(n-a):
#         print('',end=' ')
#     for j in range(1):
#         print('*'*(a*2-1) ,end=' ')
#     print()
# for i in range(5):
#     i+=1
#     for j in range(i):
#         print('#' ,end =' ')
#     print()
# N = 5
# for a in range(1,n+1):
#     for i in range(n-a):
#         print(' ',end = '')
#     for j in range(a*2-1):
#         print('*' ,end='')
#     print()
# for a in range(n-1,0,-1):
#     for i in range(n-a):
#         print(' ',end = '')
#     for j in range(a*2-1):
#         print('*',end = '')
#     print()
A = 5
B = 9

A = A + B

B = A - B

A = A - B
print(A)

n=  17
print(n%5)