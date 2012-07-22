inherit "/std/monster";

void create() {
  ::create();
    set_name("test ghost");
    set_id( ({ "test ghost" }) );
    set_level(1);
    set("short", "test ghost");
    set("long", "Yup, it's a ghost.");
    set("race", "undead");
   set_property("no_corpse", 1);
    set_gender("neuter");
    set("aggressive", 0);
    set_alignment(200);
    set_max_hp(25);
    set_hp(25);
    set_body_type("human");
   set_die( "The ghost %^RED%^dissapates%^RESET%^ before you." );
}

void catch_tell(string str) {
    object ob;
    string a, b, c;

    if(sscanf(str, "%s gives %s to you", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
	    tell_object(ob, "The ghost thanks you for your generosity.");
	    tell_room(environment(this_object()), "The ghost thanks "+a+" for "+ob->query_possessive()+" generosity.", ({this_object(), ob}));
	}
    }
    if(sscanf(str, "%ssmiles%s", a, b) == 2) tell_room(environment(this_object()), "The little ghost asks plaintively: Why don't gods like me?", ({this_object()}));
}
