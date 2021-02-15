#include "Merge_Sort_Bottom_up.h"

int	main()
{
    long    nb_line = 0;
    char    *line = NULL;
    long    **tabs = NULL;

    tabs = store_numbers(NULL, NULL, line, &nb_line);
    long    *C = BottomUpMergeSort(tabs[0], tabs[1], nb_line - 1);

    long    i = -1;
    while (++i < nb_line - 1)
        printf("%li\n", C[i]);

    if (tabs[0] != NULL)
        ft_memdel((void **)tabs[0]);
    if (tabs[1] != NULL)
        ft_memdel((void **)tabs[1]);
    if (tabs != NULL)
        ft_memdel((void **)tabs);

    return 0;
}
