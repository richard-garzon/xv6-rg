#include "types.h"
#include "pstat.h"
#include "user.h"

void
ps()
{
    struct pstat *p = malloc(sizeof(struct pstat));
    getpinfo(p);

    printf(1, "pid\t\tin use\t\ttickets\t\tticks\n");
    int i;
    for(i = 0; i < NPROC; i++)
    {
        if(p->pid[i] > 0)
        {
            printf(1, "%d\t\t%d\t\t%d\t\t%d\t\t\n", p->pid[i], p->inuse[i], p->tickets[i], p->ticks[i]);
        }
    }

    free(p);

    exit();
}

int
main(int argc, char *argv[])
{
    if(argc > 1)
    {
        printf(1, "ps doesn't support any arguments yet!\n");
        exit();
    }

    ps();
    exit();
}
