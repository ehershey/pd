#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_east", "east");
}
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Hamen's Weapons");
    set_long("%^BOLD%^%^BLACK%^HAMENS WEAPONS%^RESET%^\n"
      "%^BOLD%^%^YELLOW%^This is a place for you to sell your weapons and get money for your travels.  Evi has a list posted on the wall for all to read.");
    set_items( ([ "shop": "This is a place for you to sell your weapons and get money for your travels.", "sign": "Propety of Hamen. All goods approved and commissioned for sale.", "list": "look_at_list" ]) );
    set_invis_exits( ({ "east", "west" }) );    
    set_exits( ([ "northwest" : ROOMS+"hamen_square", "east": ROOMS+"hamen_weapon_storage" ]) );
    set_listen( "default", "You hear the sound of travelers bustling around.");
}

void reset() {
    ::reset();
    if(!present("evi")) 
	new(MON+"evi")->move(this_object());
}
int go_east() {
    if(!wizardp(this_player())) {
	message("my_action", "Do you think that would be illegal?",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+ " is throw backwards by a something magical.",
	  this_object(), ({ this_player() }));
	return 1;
    }
}
