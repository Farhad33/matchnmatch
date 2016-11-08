#include <stdio.h>
int		nmatch(char *s1, char *s2);
void	test(char *s1, char *s2)
{
	printf("%s & %s -> %d\n", s1, s2, nmatch(s1, s2));
}

int		main(void)
{
	test("main.c", "*.c");
	test("cat ", "*a*");
	test("catfffffff", "*a*");
	test("asoghaoihjeroijgoisdjgoija", "*a");
	test("ajjjjjjjjajjjjjajjja", "a*");
	test("ajjjjjjajjjjajjja", "*a*");
	test("abcbc", "*b*");
	test("abc", "a**");
	test("abc", "a**b**c**d");
	test("abc", "a**b**c**");
	test("ab", "a**");
	test("ab", "**b");
	test("aaaaaaaba", "**b**");
	test("test", "*s");
	test("abcabc", "bc*");
	test("bccc", "b***");
	test("bbbbb", "***b***");
	test("", "");
	test("", "*");
	test("abc", "*");
	test("abc", "");
	test("*********r****", "****r*********");
  return 0;
}
