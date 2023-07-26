#include "shell.h"

/**
 * it_oa - Function to convert int to string
 * @num: Length of string
 * @str: String
 * Return: An int
 */
int it_oa(int num, char *str)
{
	int div, start, end, i = 0;
	char temp;

	if (num == 0)
	{
	str[i++] = '0';
	str[i] = '\0';
	return (i);
	}
	while (num != 0)
	{
	div = num % 10;
	str[i++] = div + '0';
	num = num / 10;
	}
	str[i] = '\0';
	start = 0;
	end = i - 1;
	while (start < end)
	{
	temp = str[start];
	str[start] = str[end];
	str[end] = temp;
	start++;
	end--;
	}
	return (i);
}

/**
 * pr_f - Custom fprintf function to printf to stderr
 * @fd: File descriptor
 * @format: Format of what is to be written to stderr
 * Return: An int
 */
int pr_f(int fd, const char *format, ...)
{
	char buffer[256], *str;
	int num, len, i = 0, nc = 0, slen;
	va_list args;

	va_start(args, format);
	while (format[i] != '\0' && nc < (int)(sizeof(buffer) - 1))
	{
	if (format[i] == '%')
	{
		i++;
	if (format[i] == 'd')
	{
		num = va_arg(args, int);
		len = it_oa(num, buffer + nc);
		nc += len;
	}
	else if (format[i] == 's')
	{
		str = va_arg(args, char *);
		slen = 0;
	while (str[slen] != '\0' && nc + slen < (int)(sizeof(buffer) - 1))
	{
	buffer[nc++] = str[slen++];
	}
	}
	else
	{
		buffer[nc++] = '%';
		buffer[nc++] = format[i];
	}
	}
	else
	{
		buffer[nc++] = format[i];
	}
	i++;
	}
	va_end(args);
	buffer[nc] = '\0';
	return (write(fd, buffer, nc));
}
