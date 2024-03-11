#include "push_swap.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t i;
	size_t j;
	size_t output_len;
	size_t str_len;

	if (!s)
		return (NULL);
	str_len = 0;
	while (s[str_len])
		str_len++;
	i = 0;
	j = start;
	while (len - i > 0 && j <= str_len && s[j++])
		i++;
	output_len = i;
	sub = (char *)malloc((output_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	j = start;
	while (i < output_len)
		sub[i++] = s[j++];
	sub[i] = '\0';
	return ((char *)sub);
}

char **free_all(char **res, int w)
{
	while (w-- > 0)
		free(res[w]);
	free(res);
	return (NULL);
}

int count_words(char const *s1, char c)
{
	int count;

	count = 0;
	while (*s1)
	{
		if (*s1 == '\0')
			return (count);
		else if (*s1 && *s1 == c)
		{
			while (*s1 && *s1 == c)
				(s1)++;
		}
		else if (*s1)
		{
			count++;
			while (*s1 && *s1 != c)
				s1++;
		}
	}
	return (count);
}

char **handle_null_malloc(char const *s, char c)
{
	char **res;

	if (!s)
		return (NULL);
	res = ((char **)malloc((count_words(s, c) + 1) * sizeof(char *)));
	return (res);
}

int is_num(char c)
{
	return (c <= '9' && c >= '0');
}
int is_sign(char c)
{
	return (c == '+' || c == '-');
}
int is_space(char c)
{
	return (c == ' ');
}
void check_format(char *s)
{
	int i;
	int found_num;

	i = 0;
	found_num = 0;
	if (!is_num(s[0]) && !(is_sign(s[0]) && is_num(s[1])))
		print_exit("Error in formatting");
	i++;
	while (s[i])
	{
		if (is_num(s[i]))
			i++;
		else if (is_space (s[i]) && is_num(s[i + 1]))
			i+=2;
		else if (is_space (s[i]) && is_sign(s[i + 1]) && is_num(s[i + 2]))
			i+=3;
		else
			print_exit("Error");
	}
}

char **ft_split(char const *s, char c)
{
	int w;
	char **res;
	int i;
	int j;

	i = 0;
	res = handle_null_malloc(s, c);
	if (res == NULL)
		return (NULL);
	w = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break;
		j = 0;
		while (s[i] && s[i] != c && ++j)
			i++;
		res[w++] = ft_substr(s, i - j, j);
		if (res[w - 1] == NULL)
			return (free_all(res, w - 1));
	}
	res[w] = 0;
	return (res);
}
