#ifndef MERGE_SORT_BOTTOM_UP_H
# define MERGE_SORT_BOTTOM_UP_H

# define _GNU_SOURCE
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include <pthread.h>
# define NUM_THREADS 4
# define ERRORCHECK(x) if (!x) return (-1)
# define BUFF_SIZE 100

typedef struct		s_gnl
{
	char			*content;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

long*               BottomUpMergeSort(long *A, long *B, long n);
long*               BottomUpMerge(long *A, long iLeft, long iRight, long iEnd, long *B);
long                min(long iRight, long iEnd);
long				**store_numbers(long *A, long *B, char *line, long *nb_line);
long                ft_latoi(const char *str);
int                 get_next_line(const int fd, char **line);

#endif
