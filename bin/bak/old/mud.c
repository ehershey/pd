#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

int
main(void)
{
        int pstat; pid_t pid;
        struct sigaction ign, intact, quitact;
        sigset_t newsigblock, oldsigblock;
        chdir("/home/mud/bin");
        signal(SIGQUIT, SIG_IGN);
        signal(SIGHUP, SIG_IGN);
        umask(007);
        if (fork() != 0)
                exit(0);

      seteuid(1010);
      setegid(104);
   if (!fork()) {  execl("/home/mud/bin/addr_server","addr_server","9000",NULL); exit(1); }
  /* infinate loopie loop */
        while(1)
        {
                ign.sa_handler = SIG_IGN;
                sigemptyset(&ign.sa_mask);
                ign.sa_flags = 0;
                sigaction(SIGINT, &ign, &intact);
                sigaction(SIGQUIT, &ign, &quitact);
                sigemptyset(&newsigblock);
                sigaddset(&newsigblock, SIGCHLD);
                sigprocmask(SIG_BLOCK, &newsigblock, &oldsigblock);
                switch(pid = fork()) {
                case -1:
                        sleep(10);
                        break;
                case 0:
                        sigaction(SIGINT, &intact, NULL);
                        sigaction(SIGQUIT,  &quitact, NULL);
                        sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
                        execl("/home/mud/bin/driver", "driver", "/home/mud/bin/conf/primal.mud", NULL);
                        exit(1);
                default:
                        do {
                                pid = wait4(pid, &pstat, 0, (struct rusage *)0);
                        } while (pid == -1 && errno == EINTR);
                        break;
                }
                sigaction(SIGINT, &intact, NULL);
                sigaction(SIGQUIT,  &quitact, NULL);
                sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
		sleep(1);
         }
}

