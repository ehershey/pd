#include <daemons.h>
#include <flags.h>
#include <ansi.h>
#define CLS ESC+"[H"+ESC+"[2J"

inherit DAEMON;
static int amt;

int cmd_lockterm(string str) {
    amt=0;

    write(CLS+"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
      "\n\n\n\n\n\n[ Primal Darkness v2.0 ]\n"
      " - Terminal locked -\nPassword: ");
    input_to("pass", I_NOECHO | I_NOESC);
    return 1;
}

int pass(string str) {
    string pass;
    pass = this_player()->query_password();

    if (crypt(str,pass)!=pass && oldcrypt(str,pass) != pass) {
	write("Password: ");
	input_to("pass", I_NOECHO | I_NOESC);
	amt++;
	return 0;
    }
    if(amt)
	write("Warning!  There were "+amt+" password attempts before you "
	  "entered the correct password.\n");
    else write("- Terminal unlocked -\n");
    return 1;
}

int help() {
    write("Syntax: <lockterm>\n\nThis will lock your terminal from "
      "entering any commands.  To unlock it, enter your password at the "
      "prompt.");
}

