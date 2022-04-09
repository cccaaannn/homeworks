#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE       1024
void exit_failure(const char *msg);
int main(int argc, char **argv)
{
    FILE *fs, *fd;
    char buf[BUF_SIZE];
    size_t result;
    char* cat;

    if ((fd = fopen(argv[argc-1], "w")) == NULL)
        exit_failure("Can not open destination file");

    for (int i = 1; i < argc-1; i++){
        if ((fs = fopen(argv[i], "r")) == NULL)
            exit_failure("Can not open source file");

        while ((result = fread(buf, 1, BUF_SIZE, fs)) > 0)
            fwrite(buf, 1, result, fd);
        fclose(fs);
    }
    
    fclose(fd);
    return 0;
}
void exit_failure(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}