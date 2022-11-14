#include "get_next_line.h"

char *get_next_line(int fd);

int    main(int argc, char **argv)
{
    int fd;
    int fd2;
    char *line;
    char *line2;

    fd = open("music.txt", O_RDONLY);
    line = "";
    (void)argc;
    fd2 = open(argv[1], O_RDONLY);
    line2 = "";
    if (fd < 0)
        printf("Erro no arquivo txt\n");
    if (fd2 < 0)
        printf("Erro no arquivo do input\n"); 
    if (fd > 1)
    {
        printf("Teste de arquivo iniciado\n\n");
        while (line != 0)
        {
            line = get_next_line(fd);
            printf("%s", line);
        }
        printf ("#####TESTE DO ARQUIVO FINALIZADO##### \n\n\n");
    }
    if (fd2 > 0)
    {    
        printf("#####TESTE DO INPUT INICIADO#####\n\n");
        while (line2 != 0)
        {
            line2 = get_next_line(fd2);
            printf("%s", line2);
        }
        printf("\n#####TESTE DO INPUT FINALIZADO#####");
    }    
}