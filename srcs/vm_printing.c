/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:33:31 by adietric          #+#    #+#             */
/*   Updated: 2020/01/07 09:06:11 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void			print_top_line(int len)
{
	int				z;

	z = -1;
	ft_printf("\n        ");
	while (++z < len)
		ft_printf("%02d ", z);
	ft_putchar('\n');
	ft_printf("\n--------------------------------------------------------");
	ft_printf("-------------");
	ft_printf("------------------------------------------------------");
	ft_printf("------------------\n");
}

static void			print_line(t_all *vm, int len, int start)
{
	int				x;

	x = 0;
	while (++start < len)
	{
		if (start >= vm->champs[x].start &&
			start < vm->champs[x].start + (int)vm->champs[x].len_exec_code)
		{
			ft_printf("\033[0;35m%02x ", vm->arena[start]);
			if (start == vm->champs[x].start
				+ (int)vm->champs[x].len_exec_code - 1)
				++x;
		}
		else
		{
			if (vm->arena[start] != 0)
				ft_printf("\033[0;35m%02x ", vm->arena[start]);
			else
				ft_printf("\033[0m%02x ", vm->arena[start]);
		}
	}
}

static void			print_hex(int start)
{
	ft_printf("\033[0m%#05x : ", start);
}

void				ft_print_arena(t_all *vm, int len)
{
	int				start;

	start = 0;
	print_top_line(len);
	while (start < MEM_SIZE)
	{
		print_hex(start);
		print_line(vm, len + start, start - 1);
		ft_putchar('\n');
		start += len;
	}
}
