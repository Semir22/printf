#include "main.h"

/*
 *_printf - Printf function
 *@format: format
 *Return: Printed chars
 */


int _printf(const char *format, ...)
{
    va_list ap;
    int x, printed_chars;
    const int len = strlen(format);
    char *words;
    words = (char *)malloc(len);
    va_start(ap, format);
    for (x = 0; format[x] != '\0'; x++)
    {
        if (format[x] == '%')
        {
            if (format[x + 1] == 'c')
            {
                int y = 0;
                char *tempString = (char*)malloc(sizeof(va_arg(ap, char*)));
                tempString = va_arg(ap, char*);
                words[x] = tempString[y];
                putchar(words[x]);
                printed_chars++;
                ++x;
            }
            else if (format[x + 1] == 's')
            {
                int y = 0, z = x;
                char *tempString = (char*)malloc(sizeof(va_arg(ap, char*)));
                tempString = va_arg(ap, char*);
                while(tempString[y] != '\0') {
                  words[z] = tempString[y];
                  y++;
                  putchar(words[z]);
                  printed_chars++;
                }
                ++x;
            }
        }
        else
        {
            words[x] = format[x];
            putchar(words[x]);
            printed_chars++;
        }
    }
    va_end(ap);
    return (printed_chars);
}
