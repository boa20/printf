

/**
 * out_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int out_hex(va_list ap, params_t *params)
{
	unsigned long h;
	int c = 0;
	char *str;

	if (params->l_modifier)
		h = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		h = (unsigned short int)va_arg(ap, unsigned int);
	else
		h = (unsigned int)va_arg(ap, unsigned int);

	str = convert(h, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && h)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * out_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int out_HEX(va_list ap, params_t *params)
{
	unsigned long H;
	int c = 0;
	char *str;

	if (params->l_modifier)
		H = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		H = (unsigned short int)va_arg(ap, unsigned int);
	else
		H = (unsigned int)va_arg(ap, unsigned int);

	str = convert(H, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && H)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * out_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int out_binary(va_list ap, params_t *params)
{
	unsigned int b = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && b)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * out_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int out_octal(va_list ap, params_t *params)
{
	unsigned long o;
	char *str;
	int c = 0;

	if (params->l_modifier)
		o = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		o = (unsigned short int)va_arg(ap, unsigned int);
	else
		o = (unsigned int)va_arg(ap, unsigned int);
	str = convert(o, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && o)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
