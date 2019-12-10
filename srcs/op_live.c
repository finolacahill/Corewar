#include "../includes/vm.h"

void op_live(t_all *vm, t_process *p)
{
	int p1;
	
	vm->arena[p->pc + 1] = 0;
	vm->arena[p->pc + 2] = 0;
	vm->arena[p->pc + 3] = 0;
	vm->arena[p->pc + 4] = 4;
//	get_next_bytes(vm, p, &p1, 4);
//	printf("\tp1 = %x\n", p1);
	p1 = read_arena(vm, p->pc, 4);
	printf("\tp1 = %x\n", p1);

}