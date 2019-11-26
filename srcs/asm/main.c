#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>

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

int main(int ac, char **av)
{
    header_t *header;
    int i;

    i = 1;
    header = malloc(sizeof(header_t));
    if (ac == 1)
        return (-1);
    while (av[i])
    {
        create_file_cor(av[i], header);
        i++;
    }
    free(header);
    return (0);
}
