#ifndef COREWAR_H
# define COREWAR_H

typedef struct s_label
{
    char *label;
    int adress;
    int size;
    struct s_label *next;
}           t_label;

typedef struct s_instruc
{
    int  opcode;
    int *params;
    int nbr_params;
    int   ocp;
    int adress;
    int is_ocp;
    char *hexa_instruc;
    char *hexa_params;
    int  for_direct;
    int index;
    struct s_instruc *next;
    struct s_label *label;
}           t_instruc;

typedef struct s_env
{
    struct s_instruc *instruc;
    struct s_label   *label;
    struct header_s   *header;
    int line;
    int column;
    
}               t_env;

typedef struct s_op
{
    char *instruc;
    int nbr_params;
    int param_type[3];
    int opcode;
    int i_dont_know;
    char *real_name;
    int registre;
    int for_direct;
}               t_op;

typedef struct s_error
{
    int type;
    char *message;
    int line;
    int column;
    int params;
    int label;
}               t_error;

typedef struct s_error_cmd
{
    int type;
    char *message;

}              t_error_cmd;

t_env   *init_env();
t_instruc   *new_instruct();
t_label     *new_label();
int       get_label(char *line, t_env *env);
void    print_instruc(t_instruc *instruc);
void    print_label(t_label *labels);
int get_instruc(char *line, t_env *env);
int     get_params(char *line, t_env *env);
int     get_ocp(t_instruc *instruc);
int     bi_to_dec(char *bi);
int     ft_strtol(char *str, int base, int size);
t_instruc *get_last_intruct(t_instruc *instruc);
void    next_instruc(t_env *env);
int     dec_to_hexa(int i);
void    error(int i, int line, int column, char *name);
int     line_ispoint(char *line);
void    go_cmd(t_env *env, char *line);
int     line_empty(char *line);
int     len_instruc(t_instruc *instruc);
void    free_all(t_env *env, header_t *header);
void    remplace_empty(t_instruc *instruc, int res);
int     get_adress(t_instruc *instruc, t_instruc *working);
int     line_iscomment(char *line);
char	*get_params_with_opcode(int ocp);
int     is_label(char *label);
int     check_numbers(char *str);
void    last_verif(t_env *env);
void    error_cmd(int type, char *cmd, int line);
#endif