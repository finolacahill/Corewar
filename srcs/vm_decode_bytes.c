#include "../includes/vm.h"

static int		if_no_code(t_process *p)
{
	if (p->op == 0 || p->op == 1 ||
		p->op == 9 || p->op == 12 || p->op == 15)
		return (1);
	return (0);
}

t_process	*ft_decode_byte(unsigned char c, t_process *p)
{
	if (if_no_code(p) == 0)
	{
		p->decode[0] = c >> 6;
		c = (c << 2);
		p->decode[1] = c >> 6;
		c = (c << 2);
		p->decode[2] = c >> 6;
		c = (c << 2);
		p->decode[3] = c >> 6;
	}
 	return (p);
}

static void	get_direct_bytes(t_process *p, int *bytes)
{
	if (p->op == 0)
		bytes[0] = 0;
	if (p->op == 1)
		bytes[0] = 4;
	if (p->op == 9 || p->op == 12 || p->op == 15)
		bytes[0] = 2;
}

static int is_direct_two(t_process *p)
{
		if (p->op == 14 || p->op == 12 || p->op == 11 || p->op == 10)
			return (1);
		return (0);
}

void	calc_bytes(t_process *p, int *bytes)
{
	int i;
	int dir;

	dir = 0;
	i = -1;
	if (if_no_code(p) == 1)
	{
		get_direct_bytes(p, bytes);
		return ;
	}
	if (is_direct_two(p) == 1)
		dir = 2;
	while (++i < 4)
	{
		if (p->decode[i] == REG_CODE)
			bytes[0] += 1;
		if (p->decode[i] == DIR_CODE)
			bytes[0] += 4 - dir;
		if (p->decode[i] == IND_CODE)
			bytes[0] += 2;
	}
	++bytes[0];
}
