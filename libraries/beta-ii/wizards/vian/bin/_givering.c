#include <std.h>
inherit DAEMON;
#define RING "/wizards/vian/expring.c"
int cmd_givering() {
    foreach (object player in users()) {
        new(RING)->move(player);
message("info", "%^BOLD%^%^BLACK%^A magical ring of Experience appears in your inventory!  What a wonderful treat!", player);
}     
 return 1;
}  

