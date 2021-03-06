#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("spirit");
   set_id( ({ "ghost", "spirit" }) );
   set("short", "a spirit of hate");
    set("aggressive", 2);
   set_level(9);
   set("long", "The spirit is a blood red, misty creature. "
        "It seeks to avenge any wrongs done to it during life. "
        "Horrid black light forms the being's eyes and wicked fanged "
        "mouth.");
   set_alignment(-400);
   set("race", "undead");
   set_undead(1);
   set_property("no_corpse", 1);
   if (random(10) > 5) set_gender("male");
   else set_gender("female");
   set_money("platinum",random(5));
   set_body_type("human");
   set_die( "The spirit %^RED%^vanishes%^RESET%^ before you." );
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(sscanf(str, "%s gives you %s.", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
	    tell_room(environment(this_object()),
            "The spirit wails in rage!", ({ this_object() }));
            this_object()->force_me("say "+(string)ob->query_cap_name()
            +", you show kindness. That will take you nowhere!");
            this_object()->force_me("bury "+b);
	}
    }
}
