/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:44:25 by arodgers          #+#    #+#             */
/*   Updated: 2023/08/02 11:44:12 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	new = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!new)
	{
		return (0);
	}
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*new;
	int			i;

	new = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!new)
		return (0);
	i = 0;
	while (av[i] != 0 && i < ac)
	{
		new[i].size = ft_strlen(av[i]);
		new[i].str = av[i];
		new[i].copy = ft_strdup(av[i]);
		i++;
	}
	new[i].str = 0;
	return (new);
}

/*
int	main(void)
{
	t_stock_str	*test_struct;
	char	*str[] = {"good", "morning", "to", "you"};
	int i = 0;
	test_struct = ft_strs_to_tab(3, str);

	while (i < 3)
	{
		printf("Size = %d\tStr = %s\tCopy = %s", 
		test_struct[i].size, test_struct[i].str, test_struct[i].copy);
		printf("\n");
		i++;
	}
	return (0);
}

typedef struct s_stock_str
{
	int	size;
	char	*str;
	char	*copy;
}		t_stock_str;
*/
