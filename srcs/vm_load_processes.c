#include "../includes/vm.h"

//char    decode_byte(unsigned char encoded, int pair)
//{
/*	if (pair == 2)
		encoded <<= 2;
	if (pair == 3)
		encoded <<= 4;
	if (pair == 4)
		encoded <<= 6;
	encoded >>= 6;
	printf("%x\n", encoded);
	return (encoded);*/
	int		*ft_decode_byte(unsigned char c, int *tab)
{
	tab[0] = c >> 6;
	c = (c << 2);
	tab[1] = c >> 6;
	c = (c << 2);
	tab[2] = c >> 6;
	c = (c << 2);
	tab[3] = c >> 6;
	return (tab);
}

void				calc_bytes(int *decode, int *bytes)
{
	int i;

	*bytes = 0;
	i = -1;

	while (++i < 4)
	{
		if (decode[i] == REG_CODE)
			bytes[0] += 1;
		if (decode[i] == DIR_CODE)
			bytes[0] += 4;
		if (decode[i] == IND_CODE)
			bytes[0] += 2;
	}
}

t_process *error_process(t_process *p)
{
	p->start = -1;
	return (p);
}

t_process *init_process(t_all *vm, t_champs *c, t_process *p)
{
	int i;

	i = 0;
	printf("id = %d exec0 - %d\n", c->id, c->exec_code[0]);
	if (!(p = ft_memalloc(sizeof(t_process))))
		return (error_process(p));
	p->name = c->name;
	p->id = c->id;
	p->carry = 0;
	p->r[0] = p->id;
	p->pc = 0;
	while (++i < REG_NUMBER)
		p->r[i] = 0;
	p->live_calls = -1;
	p->op = c->exec_code[0];
	p->program = c->exec_code;
	p->start = c->start;
	p->next = NULL;
	return (p);
}

t_process *load_processes(t_all *vm, t_process *head)
{
	t_process   *new;
	int         i;

	i = 0;
	head = malloc(sizeof(t_process));
	new = init_process(vm, &vm->champs[0], new);
	head->next = new;
	while (++i < vm->total_champ)
	{
		if (new->start == -1)
			return (error_process(new));
		new->next = init_process(vm, &vm->champs[i], new->next);
		new = new->next;
	}
	head = head->next;
	return (head);
}

int 	run_processes(t_all *vm, t_process *head)
{
	t_process *tracker;

	tracker = head;
	while (tracker != NULL)
	{
		printf("parent id = %d first process = %d\n", tracker->id, tracker->op);
		tracker = tracker->next;
	}
	vm->cycles++;
	return(0);
}

int     run_vm(t_all *vm)
{
	unsigned char c = 68;
	int bytes = 0;
	int *decode;
	t_process *process;

	process = load_processes(vm, process);
	if (process->start == -1)
		return (-1);
	run_processes(vm, process);
	if (!(decode = malloc(sizeof(int) * 4)))
		return (-1);
	decode = ft_decode_byte(c, decode);
	calc_bytes(decode, &bytes);
	return (0);
}