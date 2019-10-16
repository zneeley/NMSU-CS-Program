     /* 
        Name: Zachary Neeley
        Class: cs370
        Date: 1/18/19
        Description: This lab will use LEX to read input counting the number of words in
                     taken though input and will also count the numbers in the input using LEX to handle the counting.
                     
                     Input: Any file given to the program with words and numbers to count.
                     
                     Output: Using console this program will print out the lenth of the
                             words and how many time a word of that length occured. Also
                             the program will print out the amount of numbers in the file.
     */
	int lgths[100];
	int nums = 0;      // Int used to store the amount of numbers in the input.
%%
[a-zA-Z]+	{lgths[yyleng]++;}
[0-9]+    { /* Add 1 for each number found. */ nums++;}
.	|
\n	;
%%
yywrap()
{
	int i;
	printf("Length  No. words\n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
		
	}
	
	// Print the amount of numbers in the input.
	printf("Times a number occured: %5d\n",nums);
	return(1);
}

main()
{  yylex();

}
