def egcd(a,b): # a >= b >= 0
	if (b==0):
		return (a,1,0)
	(d,xp,yp) = egcd(b,a%b)
	(x,y) = (yp, xp-(a/b)*yp) # to be completed
	return (d,x,y)
	
print(egcd(252,198))
