#include <mjungle.h>
#include <std.h>
inherit OBJECT;

void create() {
 ::create();
set_id(({"symbol", "arcane symbol"}));
set_name("symbol");
set_long("This symbol is left by Merkkirri Necromancers.  It warns that here the dead walk as if alive...");
set_short("An arcane symbol painted on the wall");
set_weight(10000000);
   set("value", 90000);
}

int get() { return 0; }
