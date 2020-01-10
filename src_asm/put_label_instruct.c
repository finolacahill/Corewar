#include "../includes/corewar.h"

int		free_empty_exit(char *empty)
{
	free(empty);
	return (return_error_i(8, -1));
}

int		put_label_instruc(t_instruc *instruc, char *label, int16_t adress,
int size)
{
	t_label	*tmp;
	char	*empty;

	if (!(empty = ft_strdup("#")))
		return (return_error_i(8, -1));
	tmp = instruc->label;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->label = ft_strdup(label)))
		return (free_empty_exit(empty));
	tmp->adress = adress;
	tmp->size = size;
	if (new_label(&(tmp->next)) == -1)
		return (free_empty_exit(empty));
	while (--size > 0)
		if (!(empty = ft_strjoin_fr(empty, "#", 1)))
			return (return_error_i(8, -1));
	if (instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, empty, 1);
	else
		instruc->hexa_instruc = ft_strdup(empty);
	if (instruc->hexa_instruc == NULL)
		return (free_empty_exit(empty));
	ft_strdel(&empty);
	return (0);
}
