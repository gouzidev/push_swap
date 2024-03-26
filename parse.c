#include "push_swap.h"

t_stack	*parse(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*node;
	char	**split_arr;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	i = ac - 1;
	while (i > 0)
	{
		split_arr = ft_split(av[i], ' ', &j);
		if (split_arr == NULL)
			print_exit("Error NULL MALLOC\n");
		while (j > 0)
		{
			if (is_empty(split_arr[j - 1]))
				print_exit("Error (empty)\n");
			if (!valid(split_arr[j - 1]))
				print_exit("Error (not valid)\n");
			else
			{
				node = new (ft_atoi(split_arr[j - 1]));
				if (!node || exists(a, node))
					print_exit("Error Bad Node");
				push(&a, node);
			}
			j--;
		}
		i--;
		free_all(split_arr);
	}
	return (a);
}
