#include <std.h>
inherit DAEMON;
#define BROWNIE "/wizards/vian/brownie.c"
int cmd_givebrownie() {
    foreach (object player in users()) {
        new(BROWNIE)->move(player);
        message("info", "A flash of %^GREEN%^green light%^RESET%^ magically moves a %^GREEN%^special%^RESET%^ brownie into your hands!", player);
}     
 return 1;
}  
