def g(x):
	return ((x**3)-(4*x)-(9)) #defining function 

def bisec(f,a,b,error): #using a as x0, b as x1
	z=(a+b)/2	#z -> midpoint
	count=0;
	while (((b-a))>error):
		if f(z)==0:
			return z
		elif (f(z)*f(a)<0): #checking for opposite signs
			b=z
		else:
			a=z

		z=(a+b)/2
		count+=1
	return z,count


m,n,error=2,3,0.01  #m -> x0 (intial first point) ; n -> x1 (intial second point)
print (bisec(g,m,n,error))