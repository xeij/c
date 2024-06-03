long int factorial (n)
int n;
{
	long int result;
	if(n==0)
	   result = 1;
	else
	   result = n*factorial(n-1);
	return (result);
}

main () {
	for(int j=0; j<11; ++j)
		printf("%2d! = %ld\n", j, factorial(j));
}
