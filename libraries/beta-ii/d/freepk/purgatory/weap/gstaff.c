#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);
 
create() {
    ::create();
   set_id( ({"staff"}) );
   set_name("%^ORANGE%^A gnarled old staff%^RESET%^");
   set_short("%^ORANGE%^A gnarled old staff%^RESET%^");
   set_long ("%^ORANGE%^This staff looks like it was cut from a crossgrained tree"
             "%^ORANGE%^ by a blind woodsman who had WAY too much to drink"
             "%^ORANGE%^ in the middle of the night with a dull hunk of iron.");
   set_weight(10);
   set_curr_value("gold", 111);
   set_wc(7);
   set_ac(2);
   set("skill level", 150);
   set_type("blunt");
   set_hit((: weapon_hit :));
   set_decay_rate(1500);
   set_wield("%^ORANGE%^You try to find a spot for your hands to grip.");
   set_unwield("Frustrated, you throw the staff down.");
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^Your hands fumble as you crack "+atk->query_cap_name()+" on the head.");
        say(""+(string)this_player()->query_cap_name()+"'s staff slips and smacks "+atk->query_cap_name()+" upside the head.");
       
result= (random(55)+(this_player()->query_level()));
   }
}
int query_auto_load() { if (this_player()->query_level() > 60) return 1; }
int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 55) return 0;
   write("Only a fool would take this nasty stick into combat.");
   say(this_player()->query_cap_name()+" breaks a twig.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
