#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	output_len;
	size_t	str_len;

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

char	**free_all(char **res, int w)
{
	while (w-- > 0)
		free(res[w]);
	free(res);
	return (NULL);
}

int	count_words(char const *s1, char c)
{
	int	count;

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

char	**handle_null_malloc(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ((char **)malloc((count_words(s, c) + 1) * sizeof(char *)));
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**res;
	int		i;
	int		j;

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
			break ;
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