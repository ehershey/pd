#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"fangs","Snake fangs"}));
    set_name("Snake fangs");
    set_short("Snake fangs");
    set_long( "Two long snake fangs.");
    set_mass(15);
    set_curr_value("gold", 40);
    set_wc(6);

    set_type("knife");
    set_hands(1);
}                            
