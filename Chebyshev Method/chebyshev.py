def func(x):    #defining function
    return (x**3)-(4*x)-(9)

def derivative(f, x, error):    #defining first derivative (generalised)
    return (f(x+error) - f(x-error)) / (2.0*error) 

def double_derivative(x):   #defining second derivative (not generalised)
    return 6*x

def solve(f, x0, error):    #applying chebyshev method
    X0 = x0
    X1 = X0 + 10*error  
    while (abs(X0 - X1) > error): #checking for condition satisfaction
        newY = f(X1)
        print "f(", X1, ") = ", newY
        X0 = X1
        X1 = X0 - (newY / derivative(f, X0, error)) - ((double_derivative(X0))*((X1-X0)**2)/(derivative(f,x0,error)))   #chebyshev formula
    return X1

xSol = solve(func, 10, 0.01)
print "solution: x = ", xSol