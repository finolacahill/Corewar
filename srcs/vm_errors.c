#include "../includes/vm.h"

t_process *error_process(t_process *p)
{
	p->start = -1;
	return (p);
}