#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE       1024
void exit_failure(const char *msg);
int main(int argc, char **argv)
{
    FILE *fs, *fd;
    char buf[BUF_SIZE];
    size_t result;
    if (argc != 4)
        exit_failure("Invalid arguments");
    if ((fs = fopen(argv[1], "r")) == NULL)
        exit_failure("Can not open source file");
    if ((fd = fopen(argv[2], "w")) == NULL)
        exit_failure("Can not open destination file");
    if (argv[3] == NULL)
        exit_failure("Buffer size not specified");
    while ((result = fread(buf, 1, atoi(argv[3]), fs)) > 0)
        fwrite(buf, 1, result, fd);
    if (ferror(fs))
        exit_failure("Error occurred while reading");
    fclose(fs);
    fclose(fd);
    return 0;
}
void exit_failure(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}