
#include "stdio.h"

int		match(char *s1, char *s2)
{
	printf("Start\n");
	printf(" s1: %c  s2: %c  Zero!\n", *s1, *s2);
	if (*s1 == 0 && *s2 == 0)
	{
		printf(" s1: %c  s2: %c  One!\n", *s1, *s2);
		return (1);
	}


	else if (*s1 != *s2 && *s2 != '*')
	{
		printf(" s1: %c  s2: %c  Two!\n", *s1, *s2);
		return (0);
	}



	else if (*s1 == *s2 && *s1 != '*')
	{
		printf(" s1: %c  s2: %c  Three!\n", *(s1 + 1), *(s2 + 1));
		return (match(s1 + 1, s2 + 1));
	}



	else if (*s2 == '*')
	{
		printf(" s1: %c  s2: %c  Four!\n", *s1, *s2);
		if (*s1 == 0)
		{
			printf(" s1: %c  s2: %c  Five!\n", *s1, *(s2 + 1));
			return (match(s1, s2 + 1));
		}
		printf(" s1: %c  s2: %c  Six!\n", *s1, *s2);
		return ((match(s1 , s2 + 1)) + (match(s1 + 1, s2)));
	}


	else
	{
		printf(" s1: %c  s2: %c  Seven!\n", *s1, *s2);
		return (0);
	}
	printf("End\n" );
}

int		main() {
	printf("The result is %d\n", match("bccc", "b***"));
	return 0;
}
