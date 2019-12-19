#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

t_label     *new_label()
{
    t_label   *new;

    new = (t_label*)malloc(sizeof(t_label));
    new->label = NULL;
    new->adress = 0;
    new->size = 0;
    new->next = NULL;
    return (new);
}

t_instruc   *new_instruct()
{
    t_instruc *new;

    new = (t_instruc*)malloc(sizeof(t_instruc));
    new->opcode = 0;
    new->params = NULL;
    new->ocp = 0;
    new->adress = 0;
    new->label = new_label();
    new->is_ocp = 0;
    new->hexa_params = NULL;
    new->hexa_instruc = NULL;
    new->next = NULL;
    new->index = 0;
    new->for_direct = 0;
    new->nbr_params = 0;
    return (new);
}

t_env   *init_env()
{
    t_env *new;

    new = (t_env*)malloc(sizeof(t_env));
    new->header = (header_t*)malloc(sizeof(header_t));
    new->instruc = new_instruct();
    new->line = 0;
    new->column = 0;
    new->label = new_label();
    return (new);
}