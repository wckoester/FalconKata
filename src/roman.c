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
   buf[0]=0;
   return -1;
}
