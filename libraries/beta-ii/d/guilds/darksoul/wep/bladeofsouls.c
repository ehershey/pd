#include <std.h>
inherit WEAPON;
string *guilds = ({ "AoD", "darksoul" });
create() {
    ::create();
    set_id(({"sword", "blade"}));
    set_name("blade of souls");
    set_short("%^BOLD%^%^WHITE%^B%^BLACK%^l%^WHITE%^a%^BLACK%^d%^WHITE%^e%^BLACK%^ o%^WHITE%^f%^BLACK%^ S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s%^RESET%^");
    set_long( "This sword appears to be an excellent weapon. Its blade is "
      "crafted of a deep obsidian, inscribed with ornate runes. Its hilt is made of a "
      "fine ivory. The blade casts a faint, eerie light across its surroundings."
    );
    set_mass(80+random(10));
    set_curr_value("gold",210+random(40));
    set_wc(1);
    set_type("blade");
    set_wield("The hilt of the blade molds to your hand.");
    set_unwield("You unwield the sword.");
    set_ac(1);
    set("skill level", 0);
}

int query_auto_load() {
    if(member_array(this_player()->query_guild(), guilds)==-1) return 0;
    if(this_player()->query_level() < 40) return 0;

    return 1; 
}

int slap_on_the_wrist(string str) {
    if (!str || present(str, this_player()) != this_object()) return 0;
    if (member_array(this_player()->query_guild(),guilds)!=-1) return 0;
    write("%^BOLD%^%^RED%^YOU ARE NOT A DARKSOUL!!!!!!!!!!");
    say(this_player()->query_cap_name()+" prances around like a little girly person.", this_player());
    return 1;
}

void init() {
    ::init();
    add_action("slap_on_the_wrist", "wield");
}