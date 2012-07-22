#include <std.h>
inherit WEAPON;
#define LEN 1;
static int parry=0;

void start_me();
void stop_me();

create() {
::create();
set_id(({"bladeweave", "blade weave"}));
set_name("bladeweave");
set_short("a %^BOLD%^YELLOW%^B%^BLUE%^lade%^YELLOW%^w%^BLUE%^eave%^RESET%^");
set_long("A device of carnage unlike any you've ever seen before, the bladeweave is the creation of the Raknid.  It is comprised of four blades each measuring nine inches in length and an interweaving set of chains that connect the device together.  The weapon gives the Raknid incredible parrying capability.");
set_weight(24);
set_curr_value("gold",175);
set_wc(11);
set_ac(2);
set_type("blade");
set_hands(4);
set_wield(start_me);
}

start_parry() { write("Oi."); }

void start_me() { parry = 1; call_out("start_parry()", LEN}

void stop_me() { parry = 0; }

int query_auto_load() {return 1; }
