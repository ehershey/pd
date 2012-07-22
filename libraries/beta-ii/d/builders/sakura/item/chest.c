#include <std.h>
#include <sakura.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("A chest");
    set_id( ({ "chest" }) );
    set_short("A chest");
    set_long("This very ornately decorated and expensive chest has no visible locking mechanism of any sort. In fact, the chest's lid is even open very slightly, and it's not locked at all.");
    set_mass(9999);
    set_value(50);
}

void init() 

{
    ::init();
    add_action("open", "open");

}

int open(str)

{
    if(!str) { return 0; }
    if(str == "chest") 

    { 
	message(0,"You lift up the lid of the chest, revealing a hungry mouth full of fangs. The mimic slams it's jaws down on your arm and injects you with a paralytic poison.", this_player());
	say(this_player()->query_cap_name()+" lifts up the lid of the chest, revealing a hungry mouth full of fangs. The mimic slams it's jaws down on "+this_player()->query_possessive()+" arm.", this_player());
	new(MOB"mimic.c")->move(environment(this_object()));
	this_player()->set_paralyzed(random(5)+1, "The mimic's poison shorts out your nervous system.", "You feel your body start to work again.");
	present("mimic")->force_me("kill "+this_player()->query_name());
	message(0,"%^CYAN%^Mimic hisses: %^RESET%^Rrraarg... 'tisssss been a while ssssince I ssssampled "+this_player()->query_race()+" meat!",environment(this_object()));
    this_object()->remove();
    return 1;
    }
    return 0;
}
