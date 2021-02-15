#include "Merge_Sort_Bottom_up.h"

long*   BottomUpMergeSort(long *A, long *B, long n)
{
    long    *tmp;

    // Each 1-element run in A is already "sorted".
    // Make successively longer sorted runs of length 2, 4, 8, 16...
    // until the whole array is sorted.
    for (long width = 1; width < n; width = 2 * width)
    {
        for (long i = 0; i < n; i = i + 2 * width)
        {
            // [iLeft.........iRight][iRight.........iEnd]
            B = BottomUpMerge(A, i, min(i + width, n), min(i + 2 * width, n), B);
        }
        tmp = A;
        A = B;
        B = tmp;
    }
    return (A);
}

long*   BottomUpMerge(long *A, long iLeft, long iRight, long iEnd, long *B)
{
    long    i = iLeft;
    long    j = iRight;

    for (long k = iLeft; k < iEnd; k++)
    {
        // If left run head exists and is <= existing right run head.
        if (i < iRight && (j >= iEnd || A[i] <= A[j]))
            B[k] = A[i++];
        else
            B[k] = A[j++];
    }
    return (B);
}

long    min(long iRight, long iEnd)
{
    if (iRight <= iEnd)
        return (iRight);
    else
        return (iEnd);
    return (1);
}

long    **store_numbers(long *A, long *B, char *line, long *nb_line)
{
    long    **tabs = NULL;
    long    valid;

    if (!(tabs = ft_memalloc(sizeof(A) * 2)))
        exit (-1);

    valid = 1;
    while (valid == 1)
    {
        valid = get_next_line(0, &line);
        if (valid && !isspace(*line))
        {
            if (!(A = realloc(A, (*nb_line + 1) * sizeof(A))))
                exit (-1);
            A[*nb_line] = ft_latoi(line);
        }
        if (line != NULL)
        {
            free(line);
            line = NULL;
        }
        (*nb_line)++;
    }
    if (!(B = ft_memalloc(sizeof(B) * (*nb_line))))
        exit (-1);

    tabs[0] = A;
    tabs[1] = B;

    return tabs;
}
