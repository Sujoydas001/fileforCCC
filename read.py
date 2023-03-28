print('hell')
filename = "now2.c"
file = open(filename , "r")
# file.write("a for apple ")
# let = file.readline();
dict = {}
for each in file:
    if each not in dict :
        dict[each] = 1
    else:
        int = dict.get(each)
        dict[each] = int + 1 
         

    print(each)


print(dict)
