#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Last Saints");
    set("long", "%^BOLD%^%^WHITE%^%^%^BOLD%^%^WHITE%^The fifth level of the guild hall was made for the leaders of the Last saints. To the north you hear the different sounds of water, sqwaking and roaring.%^RESET%^");
    set_exits( ([  "north" : GUILDROOM+"bedroom_main", "up" : GUILDROOM+"level6_main", "down" : GUILDROOM+"level4_main" ]) );
    set_pre_exit_functions( ({"north"}), ({"go_north"}) );
    new(GUILDOBJ"last_saints_statue")->move(this_object());
}
void init() {
    ::init();
    add_action("bedroom_main", "north");
    add_action("blockview", "peer");
}
int bedroom_main() { 
    if(this_player()->query_name() == "carina");  
    this_player()->move_player(load_object(GUILDROOM+"bedroom_main.c"), "into "+this_player()->query_possessive()+" room");
    if(this_player()->query_name() == "cyan");
    this_player()->move_player(load_object(GUILDROOM+"bedroom_main.c"), "into "+this_player()->query_possessive()+" room"); 
    if(this_player()->query_name() == "furiae"); 
    this_player()->move_player(load_object(GUILDROOM+"bedroom_main.c"), "into "+this_player()->query_possessive()+" room");
    if(this_player()->query_name() != "carina", "cyan", "furiae"); 
    message("info", "You are not a leader of the Last Saints.", this_player(), );  
    return 1;  
}
int blockview(string str) {
    if(str == "north" || str == "n") {
	message("info", "The leaders area is off limits.", this_player(), );
	return 1;
    }
}
