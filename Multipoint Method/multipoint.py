def func(x):   #defining function
    return (x**3)-(4*x)-(9)

def derivative(f, x, error):    #defining first derivative
    return (f(x+error) - f(x-error)) / (2.0*error) 

def solve(f, x0, error):    #applying multipoint method
    X0 = x0
    X1 = X0 + 10*error  
    while (abs(X0 - X1) > error):   #checking condition
        newY = f(X1)
        print "f(", X1, ") = ", newY
        X0 = X1
        toPass = (X0 - (0.5*(func(X0)/derivative(f,X0,error)))) #parameter to be passed in formula
        X1 = X0 - (func(X0)/derivative(f,toPass,error)) #formula for multipoint method
    return X1

xSol = solve(func, 10, 0.01)
print "solution: x = ", xSol