#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		put_instruc_params(t_instruc *instruc, int j)
{
	int i;

	i = 0;
	instruc->params = (int*)malloc(sizeof(int) * (op_tab[j].nbr_params + 1));
	while (i != op_tab[j].nbr_params)
	{
		instruc->params[i] = op_tab[j].param_type[i];
		i++;
	}
	instruc->params[i] = 0;
	return (1);
}

int		put_instruc(t_instruc *instruc_env, int j)
{
	t_instruc *tmp;

	tmp = get_last_intruct(instruc_env);
	tmp->opcode = op_tab[j].opcode;
	//printf("op_code params %d\n", op_tab[j].param_type[1]);
	put_instruc_params(tmp, j);
	tmp->for_direct = op_tab[j].for_direct;
	return (1);
}

int	check_instruc(char *instruc, t_env *env)
{
	int j;

	j = 0;
	while (op_tab[j].instruc)
	{
		if (ft_strcmp(instruc, (const char*)op_tab[j].instruc) == 0)
		{
			put_instruc(env->instruc, j);
			ft_strdel(&instruc);
			return (1);
		}
		j++;
	}
	ft_strdel(&instruc);
	exit(0); // instruction mauvaise
}

int get_instruc(char *line, t_env *env)
{
    int i;
    char *instruc;
	int j;

	j = 0;
	while (line[j] && line[j] <= ' ')
		j++;
	if (!line[j])
		return (0);
	i = j;
    while (line[i] && ft_isalpha(line[i]))
        i++;
	//ft_printf("i || j == %d | %d\n", j, i - j);
    if (i == 0 || !(instruc = ft_strsub(line, j, i - j)))
		exit(0); // mettre lexique error;
	//ft_printf("instruct ? %s\n", instruc);
	if (!check_instruc(instruc, env))
		return (-1);
	return (i);
}