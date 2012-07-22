#include <std.h>
inherit DAEMON;

#define ALE "/wizards/vian/ale.c"

int cmd_giveale() {
    foreach (object player in users()) {
	new(ALE)->move(player);
	message("info", "Vian pops into existence, hands you an ale, "
	  "and pops out again.", player);
	return 1;
    }
    return 1;
}  
