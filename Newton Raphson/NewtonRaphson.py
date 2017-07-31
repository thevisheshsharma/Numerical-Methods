def func(x):    #defining function
    return (x**3)-(4*x)-(9) 

def derivative(f, x, error):    #defining derivative
      return (f(x+error) - f(x-error)) / (2.0*error) 

def solve(f, x0, error):    #Applying Newton Raphson method
    X0 = x0
    X1 = X0 + 10*error  
    while (abs(X0 - X1) > error): #checking condition for the method
        newY = func(X1)
        print "f(", X1, ") = ", newY
        X0 = X1
        X1 = X0 - newY / derivative(f, X0, error)
    return X1

xSol = solve(func, 10, 0.01)
print "solution: x = ", xSol