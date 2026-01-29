list1 = []
list2 = list("apple")
list3 = [1,2,3,4,5]
list4 = ["apple", "lemon", "strawberry"]
list5 = [1,"banna", 3.14]

list5[0] = 100
list_x = list2 + list3

print(list1) # []
print(list2) # ['a', 'p', 'p', 'l', 'e'] 
print(list3)  # [1,2,3,4,5]
print(list4) # ['apple', 'lemon', 'strawberry']
print(list5) # [100, 'banna', 3.14]
print(list_x) # ['a', 'p', 'p', 'l', 'e', 1, 2, 3, 4, 5]

#슬라이스 
print(list_x[2:4]) # ['p', 'l']