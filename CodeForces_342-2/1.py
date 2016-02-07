#All test cases Passed 

n = input()
a = input()
b = input()
c = input()

t1 = n/a
t2 = 0
t3  = 0
 
if (n >= a) :
    t2 = (n-a)/a 
    rem = a+(n-a)%a
    t21 = (rem-b)/(b-c)
    t21 += 1 
    t2 += t21
if (n >= b): 
    t3 = (n-b)/(b-c)
    rem = b+((n-b)%(b-c))
    #print rem 
    t31 = max(1,(rem)/a)
    t32 = 0 
    while (rem >= b):
        
        t32 += 1
        rem -= b
        rem += c
       # print rem 
    t32 += rem/a      
    t3 += max(t32,t31) 
#print t1 , t2 , t3 
ans = max(t1,max(t2,t3))
print ans 