def f(x):
	return (x**3)-(4*x)-(9) #defining function f(x)

xi,xi1=6.,77. #random initial approximations.

count=0 

def secant(f,x0,x1,error):
	global count
	
	while (abs(f(x0)-f(x1))>error): #checking if difference of value of function is under the error range
		count+=1
		xx=x1 #declarign xx to facilitate variable value swap
		x1=x1-(f(x1)*((x1-x0)/(f(x1)-f(x0)))) #formula for secant
		x0=xx
	return x1,count

print(secant (f,xi,xi1,0.001))