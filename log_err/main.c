#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numb;


void url_nulling(char * str, int lenght){
    strcpy(str, "wget ");
    for(int i = 5; i < lenght; i++){
        str[i] = '\0';
    }
}


int main(int argc, char **argv, char **envp) {
    numb = 0;
    FILE * logg;
    logg = fopen(argv[1], "r+");
    FILE * mylog;
    mylog = fopen("my_log.log", "w+");
    char * sttr = malloc(2000 * sizeof(char));
    char * wo;
    char * fullurl = malloc(500 * sizeof(char));
    while (fgets(sttr, 1995, logg) != NULL){
        char * uurl = strstr(sttr, "http://");
        if(strstr(sttr, "ERROR") != NULL && uurl != NULL){
            url_nulling(fullurl, 499);
            strncpy(fullurl+5, uurl, strcspn(uurl, " "));
            while (uurl != NULL){
                system(fullurl);
                numb++;
                url_nulling(fullurl, 499);
                uurl = strstr(uurl+5, "http://");
                if(uurl != NULL)
                    strncpy(fullurl+5, uurl, strcspn(uurl, " "));
            }
        }
    }
    return 0;
}