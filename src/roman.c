#include <stdio.h>
#include <string.h>

static int value(char r)
{
   switch(r)
   {
      case 'I':
         return 1;
      case 'V':
         return 5;
      case 'X':
         return 10;
      case 'L':
         return 50;
      case 'C':
         return 100;
      case 'D':
         return 500;
      case 'M':
         return 1000;
      default:
         return -1;
   }
}

int romanToInt(char *s)
{
    int i;
    int result = 0;
 
    for (i=0; i<strlen(s); i++)
    {
        int s1 = value(s[i]);
 
        if (i+1 < strlen(s))
        {
            int s2 = value(s[i+1]);
 
            if (s1 >= s2)
            {
                result = result + s1;
            }
            else
            {
                result = result + s2 - s1;
                i++; 
            }
        }
        else
        {
            result = result + s1;
            i++;
        }
    }
    return result;
}

int intToRoman (int num, char *buf) 
{
    char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int   size[] = { 0,   1,    2,     3,    2,   1,    2,     3,      4,    2};

    while (num >= 1000) {
        *buf++ = 'M';
        num -= 1000;
    }

    strcpy (buf, huns[num/100]); buf += size[num/100]; num = num % 100;
    strcpy (buf, tens[num/10]);  buf += size[num/10];  num = num % 10;
    strcpy (buf, ones[num]);     buf += size[num];

    // Finish string off.

    *buf = '\0';
}
