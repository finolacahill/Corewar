/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:37:22 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 12:30:42 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/* This function checks if it is time to decrease the constant Cycles to die, in accordance with Corewar's rules. 
** If we have surpassed maximum lives per check or maximum checks without decrease, we decrease 
** cycles to die by cycles delta. Otherwise we increase total checks. We reset lives since check to 0.
*/
static void			check_cycle_decrease(t_all *vm)
{
	if (vm->nbr_live_since_check >= NBR_LIVE
		|| vm->total_checks + 1 >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		if (vm->flag_v == 16)
			ft_printf("Cycles to die is now %d at %d.\n",
			vm->cycles_to_die, vm->cycles);
		vm->total_checks = 0;
	}
	else
		++vm->total_checks;
	vm->nbr_live_since_check = 0;
}

/* Kill process from our process loop. If it is the head of our linked list, 
** the next process is now head, otherwise we link prev to next, to retain
** the continuity of the linked list.
*/
static t_process	*kill_process(t_all *vm, t_process **p, t_process *t,
					t_process *prev)
{
	if (prev == NULL)
	{
		(*p) = t->next;
		free_process(vm, t);
		t = (*p);
	}
	else
	{
		prev->next = t->next;
		free_process(vm, t);
		t = prev->next;
	}
	return (t);
}

/* Check if each process has made a live call in the last cycles to die number of cycles. 
** If not, we kill the process.
*/
t_process			**kill_dead_process(t_all *vm,
					t_process **p, t_process *prev)
{
	t_process		*t;
	int				i;

	t = *p;
	i = 0;
	while (t != NULL && vm->total_process - vm->dead > 0)
	{
		if (t->live_calls <= vm->cycles - vm->cycles_to_die)
		{
			t = kill_process(vm, p, t, prev);
		}
		else
		{
			prev = t;
			t = t->next;
		}
	}
	return (p);
}

/* Counts how many champs have called live in the previous cycle to dies' cycles.
** Equally if that was the last champ alive (alive == 0), we kill all remaining proccesses. 
*/
static int			check_champs(t_all *vm, t_process *p, int alive)
{
	int				i;

	i = -1;
	while (++i < vm->total_champ)
	{
		if (vm->champs[i].last_live >= vm->cycles - vm->cycles_to_die)
			++alive;
	}
	if (alive == 0)
		free_all_process(vm, p);
	return (alive);
}

/* This function verifies if in the past memory loop (of length cycles to die)
** which proccesses have and have not declared themselves alive. It then 
** kills and frees the dead processes, checks if we need to decrease the 
** constant cycles to die and returns 1 if there is at least one champ alive, 
** or zero if all champs are dead.
*/
int					check_alive(t_all *vm, t_process **p)
{
	int				alive;

	alive = 0;
	if (vm->cycles == 0)
		return (1);
	alive = check_champs(vm, (*p), alive);
	p = kill_dead_process(vm, p, NULL);
	check_cycle_decrease(vm);
	if (alive > 0)
		return (1);
	return (0);
}
