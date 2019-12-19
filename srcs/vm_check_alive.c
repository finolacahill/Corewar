#include "../includes/vm.h"

static void	check_cycle_decrease(t_all *vm)
{
 	if (vm->nbr_live_since_check >= NBR_LIVE
		|| vm->total_checks >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->total_checks = 0;
	}
	else
	{
		++vm->total_checks;
	}
	vm->nbr_live_since_check = 0; 
}

static t_process	*kill_process(t_all *vm, t_process **p, t_process *t, t_process *prev)
{
	if (prev == NULL)
	{
		ft_printf("\t\tkilling a process of id %d\n", t->id);
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

t_process	**kill_dead_process(t_all *vm, t_process **p, t_process *prev)
{
	t_process	*t;
	int			i;

	t = *p;
	i = 0;
	while (vm->total_process >= 0 && t != NULL)
	{	
		if (vm->champs[t->id - 1].last_live == -2
			|| t->live_calls < vm->cycles - vm->cycles_to_die)
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

static int	check_champs(t_all *vm, t_process *p, int alive)
{
	int i;

	i = -1;
 	while (++i < vm->total_champ)
	{
		if (vm->champs[i].last_live != -2)
		{
			if (vm->champs[i].last_live < vm->cycles - vm->cycles_to_die)
			{
				vm->champs[i].last_live = -2;
				ft_printf("\t\tChamp %d is dead.\n", i + 1);
			}
			else
				++alive;
		}
	}
	return (alive);
}

int         check_alive(t_all *vm, t_process **p)
{	
	int alive;

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