#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]){

/* Ìû áóäåì çàïóñêàòü êîìàíäó cat c àðãóìåíòîì êîìàíäíîé ñòðîêè 03-2.ñ áåç èçìåíåíèÿ ïàðàìåòðîâ ñðåäû,
ò.å. ôàêòè÷åñêè âûïîëíÿòü êîìàíäó "cat 03-2.c", êîòîðàÿ äîëæíà âûäàòü ñîäåðæèìîå äàííîãî ôàéëà íà ýêðàí.
Äëÿ ôóíêöèè execle â êà÷åñòâå èìåíè ïðîãðàììû ìû óêàçûâàåì åå ïîëíîå èìÿ ñ ïóòåì îò êîðíåâîé äèðåêòîðèè.
Ïåðâîå ñëîâî â êîìàíäíîé ñòðîêå ó íàñ äîëæíî ñîâïàäàòü ñ èìåíåì çàïóñêàåìîé ïðîãðàììû. Âòîðîå ñëîâî â êîìàíäíîé ñòðîêå - ýòî èìÿ ôàéëà, ñîäåðæèìîå êîòîðîãî ìû õîòèì ðàñïå÷àòàòü.*/

    (void) execl("/home/ilya/progi/user_env/cmake-build-debug/test_1", "/home/ilya/progi/user_env/cmake-build-debug/test_1", "ilya", 0);

/* Ñþäà ïîïàäàåì òîëüêî ïðè âîçíèêíîâåíèè îøèáêè */

    printf("Error on program start\n");
    exit(-1);

    return 0; /* Íèêîãäà íå âûïîëíÿåòñÿ, íóæåí äëÿ òîãî, ÷òîáû êîìïèëÿòîð íå âûäàâàë warning */
}