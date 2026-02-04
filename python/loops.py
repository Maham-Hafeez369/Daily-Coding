#print numbers from
#1 to 100
#100 to 1
i=0
while i<=100:
    print(i)
    i+=1
while i>=1:
    print(i)
    i-=1    

#table of any number
i=1
num=int(input("Enter a number: "))  
while i<=10:
    print(num*i)
    i+=1

#find index of an element in a list
list1=[1,2,3,4,5,6,7,8,9,10]
i=0
num=5
while i<len(list1):
    if list1[i]==num:
        print("found at index", i)
        break
    i+=1