#include <std.h>
inherit MONSTER;
#include <marsh.h>
void create() {
    ::create();
    set_id(({"bodyguard"}));
    set_name("bodyguard");
    set_short("bodyguard");
    set_long("Bare of armour or other items, the guard wields a stick like knife.");
    set_gender("male");
    set_race("tonberry");
    set_body_type("human");
    add_limb("tail", "torso", 3000, 0, 10);
    set_level(10);
    set_max_hp(25000);
    set_hp(25000);
    set_class("fighter");
    add_action("knife","knife");
    set_spells(({"knife"}));
    set_spell_chance(10);
    set_exp(1540000);
}
int knife() {
    object ob;
    ob = this_object()->query_current_attacker();
    tell_object(ob, "Bodyguard grins evilly at you.");
    tell_object(ob, "You start to sweat profusely.");
    tell_room(environment(this_object()), "Bodyguard grins evilly at
"+ob->query_cap_name()+".", ({ob}));
    tell_room(environment(this_object()), ob->query_cap_name()+" starts to
sweat profusely.", ({ob}));
    call_out("knife2", 5, ob);
    return 1;
}
int knife2(object ob) {
    if (!present(ob, environment())) return 1;
    tell_object(ob, "Bodyguard walks up to you slowly and %^BOLD%^stabs%^RESET%^ you with his
pointed stick!");
    tell_room(environment(this_object()), "Bodyguard walks up to
"+ob->query_cap_name()+" slowly and %^BOLD%^stabs%^RESET%^ "+ob->query_subjective()+" with his
pointed stick!", ({ob}));
    ob->die();
    if (present("corpse",environment(this_object()))) {
        tell_room(environment(this_object()), "Bodyguard stabs the corpse with his
pointed stick and puts it in his bag.");
        force_me("sacrifice corpse");
    }
    return 1;
}
