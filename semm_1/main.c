#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){

int fd;
size_t size;
char string[] = "Hello, world!";

/* Îáíóëÿåì ìàñêó ñîçäàíèÿ ôàéëîâ òåêóùåãî ïðîöåññà äëÿ òîãî, ÷òîáû
ïðàâà äîñòóïà ó ñîçäàâàåìîãî ôàéëà òî÷íî ñîîòâåñòâîâàëè ïàðàìåòðó âûçîâà open() */

(void)umask(0);

/* Ïîïûòàåìñÿ îòêðûòü ôàéë ñ èìåíåì myfile â òåêóùåé äèðåêòîðèè òîëüêî
äëÿ îïåðàöèé âûâîäà. Åñëè ôàéë íå ñóùåñòâóåò, ïîïðîáóåì åãî ñîçäàòü ñ ïðàâàìè
äîñòóïà 0666, ò.  å. read-write äëÿ âñåõ êàòåãîðèé ïîëüçîâàòåëåé */

if((fd = open("myfile", O_WRONLY | O_CREAT, 0666)) < 0){

/* Åñëè ôàéë îòêðûòü íå óäàëîñü, ïå÷àòàåì îá ýòîì ñîîáùåíèå è ïðåêðàùàåì ðàáîòó */

printf("Can\'t open file\n");
exit(-1);
}

/* Ïðîáóåì çàïèñàòü â ôàéë 14 áàéò èç íàøåãî ìàññèâà, ò.å. âñþ ñòðîêó "Hello, world!"
âìåñòå ñ ïðèçíàêîì êîíöà ñòðîêè */

size = write(fd, string, 14);

if(size != 14){

/* Åñëè çàïèñàëîñü ìåíüøåå êîëè÷åñòâî áàéò, ñîîáùàåì îá îøèáêå */

printf("Can\'t write all string\n");
exit(-1);
}


/* Çàêðûâàåì ôàéë */

if(close(fd) < 0){
printf("Can\'t close file\n");
}

return 0;
}