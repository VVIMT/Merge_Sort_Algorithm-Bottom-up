#include "Merge_Sort_Bottom_up.h"

int     main()
{
    long	nb_line = 0;
    char	*line = NULL;
    long	**tabs = NULL;

    // Create two tables, import the text file and store the numbers into the first table.
    tabs = store_numbers(NULL, NULL, line, &nb_line);
    long    *C = BottomUpMergeSort(tabs[0], tabs[1], nb_line - 1);

    long    i = -1;
    while (++i < nb_line - 1)
        printf("%li\n", C[i]);

    free(tabs[0]);
    free(tabs[1]);

    return 0;
}
