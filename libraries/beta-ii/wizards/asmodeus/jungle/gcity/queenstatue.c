#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit OBJECT;

void create() {
 ::create();
set_id(({"statue"}));
set_name("statue");
set_long("A golden statue dedicated to the Merkkirri Queen.  It stands nearly 12 feet tall.");
set_short("A statue of Shallzaea");
set_weight(100000000);
   set("value", 90000);
}

int get() { return 0; }
