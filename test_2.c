#include "types.h"
#include "pstat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int curr_pid = getpid();
  struct pstat * ps = malloc(sizeof(struct pstat));

  getpinfo(ps);

  for(int i = 0; i < NPROC; i++)
  {
      if(curr_pid == ps->pid[i])
      {
        printf(1, "found my proc\n");
        if(1 == ps->tickets[i])
        {
          printf(1, "default ticket 1 is correct\n");
        } else
        {
          printf(1, "default ticket 1 is NOT CORRECT\n");
        }
      }
  }

  int ticket_amount = 13;
  settickets(ticket_amount);
  printf(1,"called settickets\n");


  getpinfo(ps);

  for(int i = 0; i < NPROC; i++)
  {
      if(curr_pid == ps->pid[i])
      {
        printf(1, "found my proc\n");
        if(ticket_amount == ps->tickets[i])
        {
          printf(1, "settickets worked\n");
        } else
        {
          printf(1, "settickets did not work\n");
        }
      }
  }
  free(ps);
  exit();
}
