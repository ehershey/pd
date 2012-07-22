#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_southeast", "southeast");
}
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Heaven's Armoury");
    set_long(
      "%^BOLD%^%^BLACK%^HEAVEN'S ARMOURY%^RESET%^\n"
      "%^BOLD%^%^YELLOW%^Welcome to Heaven's Armoury! This is a place for passerbys to sell their goods for a price, and to buy them for an even bigger price. The room is very chilly as a woman dressed all in white, with long platinum hair flowing down her back, stands behind the counter. She looks like a vision in white and it can be seen on her name tag that she is called 'Winter'. Winter has a list posted on the wall for all to read.%^RESET%^");
    set_invis_exits( ( { "southeast", "southwest" } ) );    
    set_exits( ([ "west" : HEVROOM "heaven_square", "southeast": HEVROOM "arm_storage" ]) );
}
void reset() {
    ::reset();
    if(!present("winter")) 
	new(HEVMOB "winter")->move(this_object());
}
int go_southeast() {
    if(!wizardp(this_player())) {
	message("my_action", "Do you think that would be illegal?",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " is throw backwards by a something magical.",
	  this_object(), ({ this_player() }));
	return 1;
    }
}
