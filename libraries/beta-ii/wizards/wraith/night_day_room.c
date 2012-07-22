#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    room::create();
    set_properties( ([ "light" : 2]) );
    set_property("forest",1);
    set_short("Marsh");
    set_day_long(
      "It is day, This room loads one kind of mob in the day and a different kind of mob in the night."
    );
    set_night_long(
      "It is night, This room loads one kind of mob in the day and a different kind of mob in the night."
    );
    set_items(([
	"mob" : "An npc made for fighting.",
      ]));
    set_smell("default", "It smells.");
    set_listen("default", "Sounds.");
    set_exits( ([
	"north" : ROOMS "blah",
      ]) );
    set_heart_beat(1);
}
void reset() {
    ::reset();
    // The following two lines are for night mobs
    if (query_night() && !present("gob", this_object())) {
	new(MOB"gob")->move(this_object());
    }
    // the following two lines are for day mobs
    if (!query_night() && !present("deer", this_object())) {
	new(MOB"deer")->move(this_object());
    }
}
void init() {
    ::init();
    set_heart_beat(1);
}
void move(object ob) {
    message("info", ob->query_cap_name()+" leaves.", this_object());
    ob->move("/wizards/wraith/removeroom.c");
}
void heart_beat() {
    int i, check;
    object *ob = ({ }), you;
    if (!query_night()) {
	if ((you = present("gob", this_object())))
	    move(you);
    }
    if (query_night()) {
	if ((you = present("deer", this_object())))
	    move(you);
    }
    ob = all_inventory(this_object());
    i = sizeof(ob);
    check = 0;
    while (i--) {
	if (ob[i]->is_player())
	    check = 1;
    }
    if (!check) {
	set_heart_beat(0);
	return;
    }
}
