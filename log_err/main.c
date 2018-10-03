#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
    FILE * texxt;
    texxt = fopen(argv[1], "r+");
    int nstr = 0, nwor = 0;
    char * sttr = malloc(1000 * sizeof(char));
    char * wo;
    while (fgets(sttr, 995, texxt) != NULL){
        nstr++;
        wo = strtok(sttr, " ,.;?!:");
        while (wo != 0){
            nwor++;
            wo = strtok(NULL, " ,.;?!:\n");
        }
    }
    printf("strs: %d\nwords: %d\n", nstr, nwor);
    return 0;
}