#include <std.h>
inherit DAEMON;
#define CAKE "/wizards/vian/cake.c"
int cmd_givecake() {
    foreach (object player in users()) {
        new(CAKE)->move(player);
        message("info", "%^BOLD%^Vian's hand appears, giving you a birthday cake in honor of Sugarcandy!%^RESET%^", player);
}     
 return 1;
}  
