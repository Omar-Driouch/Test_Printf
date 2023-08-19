#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	char spec[6] = {'i', 'd', 'c', 's', 'b', 'o'};
	char ignore[3] = {'%', '!','K'};
	int total_written = 0;
	int i = 0, j = 0;

	va_start(args, format);

	if (format[0] == '\0')
	{
		va_end(args);
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{

			for (j = 0; j < 6; j++)
			{
				if (format[i + 1] == spec[j])
				{
					total_written += get_right_func(format + i + 1)(args);
					i += 2;
					break;
				}
				else if (ignore[j] == format[i + 1] && j < 3)
				{
					total_written += _putchar(format[i]);
					if (ignore[j] != '%')
						total_written += _putchar(ignore[j]);
					i += 2;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			total_written++;
			i++;
		}
	}
	va_end(args);
	return (total_written);
}
