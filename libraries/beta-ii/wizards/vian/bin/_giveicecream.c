#include <std.h>
inherit DAEMON;
#define icecream "/wizards/vian/icecream.c"
int cmd_giveicecream() {
    foreach (object player in users()) {
        new(icecream)->move(player);
        message("info", "It must be your lucky day!  An %^BOLD%^ice cream cone%^RESET%^ dipped in %^BOLD%^%^BLACK%^chocolate syrup%^RESET%^ finds its way into your inventory.",
player);
}     
 return 1;
}  
