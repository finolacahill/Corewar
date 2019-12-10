#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 10480

int main (int ac, char **av)
{

	int					ocp_value = {0 | 12 | 115};

	int	r = -1;
	while (++r < 10000)
	{
		if ((r ^ ocp_value) == ocp_value)
			printf("%d est ok\n", r);
	}
	// int			fd;
	// uint8_t		buff[BUFF_SIZE + 1];
	// int			ret;
	// size_t		cor_size;
	// uint8_t		*cor_content;
// 
	// cor_content = NULL;
	// fd = open(av[1], O_RDONLY);
	// ret = read(fd, buff, BUFF_SIZE);
	// cor_size = ret;
														// printf("ret = %d\n", ret);
														// int it = -1;
														// while (++it < 20)
															// printf("|%d| ", buff[2192 + it]);
														// buff[2192] = 25;
// 
	// buff[ret] = '\0';
	// close(fd);
	// char	*str = "test_faux.cor";
	// FILE *fichier;
	// fichier = fopen(str, "w");
	// fd = open(str, O_RDWR);
	// write(fd, buff, ret);
	// close(fd);
	return (0);
}