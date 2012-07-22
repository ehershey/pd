#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"staff","lava staff"}));
    set_name("Lava Staff");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^S%^RESET%^%^RED%^t"
              "%^BOLD%^%^RED%^a%^RESET%^%^RED%^f%^BOLD%^%^RED%^f");
    set_long( "%^RED%^ This staff is one of a kind, that could only "
              "be found in the firey deeps..");
    set_mass(13);
    set_curr_value("gold", 58);
    set_wc(10);

    set_type("blunt");
    set_hands(1);
}                        

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
