#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void    create_file_cor(char *file_name, header_t *header)
{
    char *new_name;
    int len;

    len = ft_strlen(file_name) - 2;
    new_name = ft_strnew(len);
    ft_memcpy(new_name, file_name, len);
    printf("%s\n", new_name);
    new_name = ft_strjoin_fr(new_name, ".cor", 1);
    printf("%s\n", new_name);
    header->fd = open(new_name, O_WRONLY | O_CREAT, 0777);
    ft_strdel(&new_name);
}

void    every_go(char *av, t_env *env)
{
    //int error;
    int     fd;
    char    *line;
    int     i;
    
    i = 0;
    fd = open(av, O_RDONLY);
    get_next_line(fd, &line);
    //{
        i = get_label(line, env);
        printf("line apres get_label ==%s\n", &line[i]);
        i = i + get_instruc(&line[i], env);
        get_params(&line[i], env);
       // get_instruct(line, env);
        //error = label(env);
        i = 0;
        free(line);
    //}
    print_label(env->label);
    print_instruc(env->instruc);
    close(fd);
}

int main(int ac, char **av)
{
    header_t *header;
    t_env    *env;
    int i;

    i = 1; 
    env = init_env();
    if (ac == 1)
        return (-1);
    if (!(header = malloc(sizeof(header_t))))
        return (-1);
    while (av[i])
    {
        //create_file_cor(av[i], header);
        every_go(av[i], env);
        i++;
    }
    
    //free(header);
    return (0);
}
