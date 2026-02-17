def Lagrange(x,fx,value):
    n = len(x)
    result = 0.0
    
    for i in range(n):
        term = fx[i]
        for j in range(n):
            if j != i:
                term = term*(value - x[j])/(x[i]-x[j])
        
        result = result + term
    
    return result
        
x = [1,2,3]
fx = [2,3,5]
value = 1.5

result = Lagrange(x,fx,value)
print("x = ",value," result = ", result)
 
            
             