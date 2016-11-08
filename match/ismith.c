#include <stdio.h>

int     match(char *s1, char *s2);

void    test(char *s1, char *s2, int should)
{
    int        result;

    result = match(s1, s2);
    if (result == should)
        printf("\e[42m\e[30mPASS\e[0m\n");
    else
        printf("\e[5m\e[41mFAIL\e[0m\n");
    printf("%s\n%s\n\n", s1, s2);
}

int        main(void)
{
    test("a", "b", 0);
    test("c", "c", 1);
    test("d", "dd", 0);
    test("d", "*d", 1);
    test("d", "*d*", 1);
    test("d", "d*", 1);
    test("dd", "d*d", 1);
    test("abcccd", "*ccd", 1);
    test("mississipissippi", "*issip*ss*", 1);
    test("xxxx*zzzzzzzzy*f", "xxxx*zzy*fffff", 0);
    test("xxxx*zzzzzzzzy*f", "xxx*zzy*f", 1);
    test("xxxxzzzzzzzzyf", "xxxx*zzy*fffff", 0);
    test("xxxxzzzzzzzzyf", "xxxx*zzy*f", 1);
    test("xyxyxyzyxyz", "xy*z*xyz", 1);
    test("mississippi", "*sip*", 1);
    test("xyxyxyxyz", "xy*xyz", 1);
    test("mississippi", "mi*sip*", 1);
    test("ababac", "*abac*", 1);
    test("ababac", "*abac*", 1);
    test("aaazz", "a*zz*", 1);
    test("a12b12", "*12*23", 0);
    test("a12b12", "a12b", 0);
    test("a12b12", "*12*12*", 1);
    test("*", "*", 1);
    test("a*abab", "a*b", 1);
    test("a*r", "a*", 1);
    test("a*ar", "a*aar", 0);
    test("XYXYXYZYXYz", "XY*Z*XYz", 1);
    test("missisSIPpi", "*SIP*", 1);
    test("mississipPI", "*issip*PI", 1);
    test("xyxyxyxyz", "xy*xyz", 1);
    test("miSsissippi", "mi*sip*", 1);
    test("miSsissippi", "mi*Sip*", 0);
    test("abAbac", "*Abac*", 1);
    test("abAbac", "*Abac*", 1);
    test("aAazz", "a*zz*", 1);
    test("A12b12", "*12*23", 0);
    test("a12B12", "*12*12*", 1);
    test("oWn", "*oWn*", 1);
    test("bLah", "bLah", 1);
    test("bLah", "bLaH", 0);
    return (0);
}
