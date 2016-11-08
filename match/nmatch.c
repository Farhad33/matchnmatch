
#include <stdio.h>

int	nmatch(char *s1, char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
  if (*s1 == '\0' && *s2 == '*')
    return (nmatch(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    return (nmatch(s1 + 1, s2 + 1));
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    return (1);
  return (0);
}

int		main(void)
{
	printf("%i", nmatch("abcbd", "*b*"));
	printf("\n");
	printf("%i", nmatch("abc", "a**" ));
	printf("\n");
	return (0);
}
