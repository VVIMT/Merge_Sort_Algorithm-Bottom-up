#include "Merge_Sort_Bottom_up.h"

int	main()
{
    unsigned long long int  start_ns; // Milliseconds
    time_t                  start_s;  // Seconds
    unsigned long long int  stop_ns; // Milliseconds
    time_t                  stop_s;  // Seconds
    struct timespec         spec;

    clock_gettime(CLOCK_MONOTONIC, &spec);
    start_s  = spec.tv_sec;
    start_ns = floor(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds

    long    nb_line = 0;
    char    *line = NULL;
    long    **tabs = NULL;

    tabs = store_numbers(NULL, NULL, line, &nb_line);
    long    *C = BottomUpMergeSort(tabs[0], tabs[1], nb_line - 1);

    long    i = -1;
    while (++i < nb_line - 1)
//        printf("%li\n", C[i]);
        if(C)
            continue;

    if (tabs[0] != NULL)
    {
        free(tabs[0]);
        tabs[0] = NULL;
    }
    if (tabs[1] != NULL)
    {
        free(tabs[1]);
        tabs[1] = NULL;
    }
    if (tabs != NULL)
    {
        free(tabs);
        tabs = NULL;
    }

    clock_gettime(CLOCK_MONOTONIC, &spec);
    stop_s  = spec.tv_sec;
    stop_ns = ((spec.tv_nsec));// / 1.0e6)); // Convert nanoseconds to milliseconds
    stop_ns %= (unsigned long long int)1e9;
    printf("Elapsed time: %"PRIdMAX" seconds and %llu nanoseconds\n", \
    (intmax_t)stop_s - (intmax_t)start_s, stop_ns - start_ns);

    return 0;
}
