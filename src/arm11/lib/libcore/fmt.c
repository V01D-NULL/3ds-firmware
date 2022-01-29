#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

static int strlen(const char *s)
{
	int n = 0;
	while (*s++)
		n++;
	return n;
}
char itoc(int num) { return '0' + num; }

char itoh(int num, bool upper)
{
	if (upper)
		return num - 10 + 'A';
	return num - 10 + 'a';
}

char *strrev(char *src)
{
	static char temp;
	int src_string_index = 0;
	int last_char = strlen(src) - 1;

	for (; src_string_index < last_char; src_string_index++)
	{
		temp = src[src_string_index]; // Save current character
		src[src_string_index] =
			src[last_char];	   // Swap out the current char with the last char
		src[last_char] = temp; // Swap out last character with the current character
		last_char--;
	}

	src[strlen(src) - 1 + 1] = '\0';

	return src;
}

#include <core/fb.h>
void itoa(int num, char *str, int base, bool upper)
{
	int buffer_sz = 20;
	int counter = 0;
	int digit = 0;

	while (num != 0 && counter < buffer_sz - 1)
	{
		digit = (num % base);
		if (digit > 9)
		{
			str[counter++] = itoh(digit, true);
		}
		else
		{
			str[counter++] = itoc(digit);
		}

		num /= base;
	}

	str[counter] = '\0';
	strrev(str);
}

int vsnprintf(char *str, int size, const char *fmt, va_list ap)
{
	int buff_sz = 0;

	for (int i = 0; i < size; i++)
	{
		switch (fmt[i])
		{
		case '%':
		{
			switch (fmt[i + 1])
			{
			case 'c':
				str[i] = va_arg(ap, int);
				i++;
				buff_sz++;
				break;

			case 's':
			{
				char *arg = va_arg(ap, char *);
				int len = strlen(arg);
				for (int j = 0; j < len; j++)
					*str++ = arg[j];

				buff_sz += len;
				i++;
				break;
			}

			case 'i':
			case 'd':
			{
				int arg = va_arg(ap, int);
				if (arg == 0)
				{
					*str++ = '0';
					buff_sz++;
				}
				else
				{
					char res[20];
					itoa(arg, res, 10, false);

					int len = strlen(res);
					for (int j = 0; j < len; j++)
						*str++ = res[j];

					buff_sz += len;
				}
				i++;
				break;
			}

			case 'x':
			{
				int arg = va_arg(ap, int);
				if (arg == 0)
				{
					*str++ = '0';
					buff_sz++;
				}
				else
				{
					char res[20];
					itoa(arg, res, 16, false);

					int len = strlen(res);
					for (int j = 0; j < len; j++)
						*str++ = res[j];

					buff_sz += len;
				}
				i++;
				break;
			}

			case 'X':
			{
				int arg = va_arg(ap, int);
				char res[20];
				if (arg == 0)
				{
					*str++ = '0';
					buff_sz++;
				}
				else
				{
					itoa(arg, res, 16, true);

					int len = strlen(res);
					for (int j = 0; j < len; j++)
						*str++ = res[j];

					buff_sz += len;
				}
				i++;
				break;
			}
			}

			break;
		}

		default:
			if (fmt[i] == '\0')
				goto end;
			*str++ = fmt[i];
			buff_sz++;
			break;
		}
	}
end:
	*str++ = '\0';
	return buff_sz;
}