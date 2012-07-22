#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <err.h>
#include <fcntl.h>

int
main(void)
{
        struct sigaction ign, intact, quitact;
        sigset_t newsigblock, oldsigblock;
        int restarted = 0;
        pid_t pid;
	int fin, fout;
	int amnt_read;
	char buff[1024];

        umask(0077);
        signal(SIGHUP, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);

        if (chdir("/home/primal/mud/bin") == -1)
                err(1, "cannot chdir to mud bin dir");
        if (fork() != 0)
                exit(0);
        close(0);
        close(1);
        close(2);
	if ((pid = fork()) == 0) {
		execl("addr_server", "addr_server", "9000", NULL);
		_exit(1);
	}
loop: //  setproctitle("starting mud");
	fin = open("../libraries/beta-ii/log/debug.log", O_RDONLY);
	fout = open("../libraries/beta-ii/log/debug.old",
			O_WRONLY|O_TRUNC|O_CREAT, 0666);
	amnt_read = 1024;
	while( amnt_read != 0 ) {
		amnt_read = read( fin, buff, 1024 );
		if( amnt_read != 0 )
			write( fout, buff, amnt_read );
	}
	close( fin );
	close( fout );
        ign.sa_handler = SIG_IGN;
        sigemptyset(&ign.sa_mask);
        ign.sa_flags = 0;
        sigaction(SIGINT, &ign, &intact);
        sigaction(SIGQUIT, &ign, &quitact);
        sigemptyset(&newsigblock);
        sigaddset(&newsigblock, SIGCHLD);
        sigprocmask(SIG_BLOCK, &newsigblock, &oldsigblock);
        switch ((pid = fork())) {
                case -1:
                        exit(1);
                case 0:
                        sigaction(SIGINT, &intact, NULL);
                        sigaction(SIGQUIT,  &quitact, NULL);
                        sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
                        execl("driver", "driver", "primal.mud", NULL);
                        _exit(1);
                default:
//                        setproctitle("supervising (%d)", restarted);
                        do {
                                pid = wait4(pid, NULL, 0, NULL);
                        } while (pid == -1 && errno == EINTR);
        }
        sigaction(SIGINT, &intact, NULL);
        sigaction(SIGQUIT,  &quitact, NULL);
        sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
//        setproctitle("sleeping (%d)", restarted++);
        sleep(1);
        goto loop;
}
