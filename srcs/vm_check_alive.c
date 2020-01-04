#include "../includes/vm.h"

static void	check_cycle_decrease(t_all *vm)
{
 	if (vm->nbr_live_since_check >= NBR_LIVE
		|| vm->total_checks  + 1 >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		if (vm->flag_v == 16)
			ft_printf("Cycles to die is now %d at %d.\n", vm->cycles_to_die, vm->cycles);
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
			if (vm->flag_v == 8)
				ft_printf("Process pid %d id %d hasn't lived for %d (cycles to die %d, cycle %d)\n", (t)->pid, (t)->id, vm->cycles - t->live_calls, vm->cycles_to_die, vm->cycles);
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
			if (vm->champs[i].last_live >= vm->cycles - vm->cycles_to_die)
				++alive;
	}
	return (alive);
}

int         check_alive(t_all *vm, t_process **p)
{	
	int alive;

	alive = 0;
	if (vm->cycles == 0)
		return (1);
//	ft_printf("CHECKING at %d, cycles to die is %d, nb_lives %d, nb_checks %d\n", vm->cycles, vm->cycles_to_die, vm->nbr_live_since_check, vm->total_checks);
	alive = check_champs(vm, (*p), alive);
	p = kill_dead_process(vm, p, NULL);
	check_cycle_decrease(vm);
	if (alive > 0)
		return (1);
	return (0);
}