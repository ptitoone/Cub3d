#include "../incls/libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		j;

	j = 0;
	while (*s != 0)
	{
		while (*s != c && *s != 0)
			s++;
		j++;
		while (*s == c && *s != 0)
			s++;
	}
	return (j);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != 0)
		i++;
	if (s[i] == 0)
		return (i);
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static char	**ft_buildstr(char **tab, char *str, char c, int wc)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < wc)
	{
		tab[j] = (char *)malloc(sizeof(char) * ft_wordlen(&str[i], c) + 1);
		if (tab[j] == NULL)
			return (NULL);
		ft_strlcpy(tab[j], &str[i], ft_wordlen(&str[i], c) + 1);
		while (str[i] != 0 && str[i] != c)
			i++;
		while (str[i] != 0 && str[i] == c)
			i++;
		j++;
	}
	tab[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**tab;
	int		wc;
	char	ch[2];

	ch[0] = c;
	ch[1] = 0;
	if (!s)
		return (0);
	str = ft_strtrim((char *)s, ch);
	wc = ft_count_words(str, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (tab == NULL)
		return (NULL);
	ft_buildstr(tab, str, c, wc);
	free(str);
	return (tab);
}
