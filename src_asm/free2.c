#include "../includes/corewar.h"

int		del_and_return(void **x, int ret)
{
	ft_memdel(x);
	return (ret);
}

void	free_and_freeall(void **a, void **b, void **c, t_env *env)
{
	if (a != NULL)
		free(a);
	if (b != NULL)	
		free(b);
	if (c != NULL)
		free(c);
	free_all(env, env->header);
}

void	free_error_8(void **a, void **b, void **c, t_env *env)
{
	free_and_freeall(a, b, c, env);
	error(8, -1, -1, NULL);
}

int		return_error_i(int i, int ret)
{
	error_no_exit(i, -1, -1, NULL);
	return (ret);
}