#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit OBJECT;

void create() {
 ::create();
set_id(({"statue"}));
set_name("statue");
set_long("A statue dedicated to the Merkkirri God %^BOLD%^BLACK%^Asmodeus%^RESET%^.  It stands nearly 20 feet tall and is made of dark jade.");
set_short("A statue of Asmodeus");
set_weight(100000000);
   set("value", 90000);
}

int get() { return 0; }
