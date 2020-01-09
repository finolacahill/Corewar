#include "../includes/vm.h"

static int	check_ind(t_process *p, int i)
{
	if (i == 0)
		if (p->op == 2 || p->op == 6
			|| p->op == 7 || p->op == 8 || p->op == 10
			|| p->op == 13 || p->op == 14)
			return (1);
	if (i == 1)
		if (p->op == 2 || p->op == 6
			|| p->op == 7 || p->op == 8 || p->op == 11)
			return (1);
	return (0);
}
static int	check_dir(t_process *p, int i)
{
	if (i == 0)
		if (p->op == 1 || p->op == 2
			|| p->op == 6 || p->op == 7 || p->op == 8
			|| p->op == 9 || p->op == 10 || p-> op == 12
			|| p->op == 13 || p->op == 14 || p->op == 15)
			return (1);
	if (i == 1)
		if (p->op == 6 || p->op == 7 || p-> op == 8
			|| p->op == 10 || p->op == 11 || p->op == 14)
			return (1);
	if (i == 2)
		if (p->op == 11)
            return (1);
	return (0);
}

static int	get_direct_bytes(t_process *p, int *bytes)
{
	if (p->op == 0)
		bytes[0] = 0;
	if (p->op == 1)
		bytes[0] = 4;
	if (p->op == 9 || p->op == 12 || p->op == 15)
		bytes[0] = 2;
	return (1);
}

static int	check_reg(t_process *p, int i)
{
	if (i == 0)
		if (p->op == 3 || p->op == 4 || p-> op == 5
			|| p->op == 6 || p->op == 7 || p->op == 8
			|| p-> op == 10 || p->op == 11 || p->op == 14
			|| p->op == 16)
			return (1);
	if (i == 1)
		if (p->op == 2 || p->op == 3 || p-> op == 4
			|| p->op == 5 || p->op == 6 || p->op == 7
			|| p-> op == 8 || p->op == 10 || p->op == 11
			|| p->op == 13 || p->op == 14)
			return (1);
	if (i == 2)
		if (p->op == 4 || p-> op == 5
            || p->op == 6 || p->op == 7 || p->op == 8
            || p-> op == 10 || p->op == 11 || p->op == 14)
            return (1);
	return (0);
}

static int	is_direct_two(t_process *p)
{
	if (p->op == 14 || p->op == 12 || p->op == 11 || p->op == 10)
		return (1);
	return (0);
}

int		recalc_bytes(t_process *p, int *bytes)
{
	int		dir;
	int		i;

	i = -1;
	dir = 0;
	bytes[0] = 1;

	if (if_no_opcode(p) == 1)
		return (get_direct_bytes(p, bytes - 1));
	if (is_direct_two(p) == 1)
		dir = 2;;
	while (++i < 3)
	{
	//	ft_printf("i = %d bytes= %d\n", i, bytes[0]);
		if (p->decode[i] == REG_CODE)
		{
			bytes[0] += 1;
		//	if (check_reg(p, i) == 0)
		//		return (0);
		}
		if (p->decode[i] == DIR_CODE)
		{
			bytes[0] += 4 - dir;
		//	if (check_dir(p, i) == 0)
			//	return (0);
		}
		if (p->decode[i] == IND_CODE)
		{
			bytes[0] += 2;
		//	if (check_ind(p, i) == 0)
			//	return (0);
		}
	}
	return (1);
}