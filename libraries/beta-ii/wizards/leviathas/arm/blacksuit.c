# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("dress");
    
set_short("%^BOLD%^%^BLACK%^Black Suit%^RESET%^");
    set_long("The black suit of a gentleman in disguise.");
    set_id(({"suit", "black suit"}));
    set_ac(1);            
    set_mass(2);
    set_type("clothes");   
set_limbs(({"right arm", "left arm", "right leg", "left leg", "torso" }));

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }


