#include <std.h>
#include <azeria.h>
inherit ROOM;
void create() {
    room::create();
    set_properties( ([ "light" : 2]) );
    set_short("Aziera");
    set_day_long(
      "The town of Azeria is surrounded by endless forest. This holy town
was once the sight of a great war. The ground shines. An aura surrounds everything.");
    set_night_long(
      "Huge shadows line the streets, bloody corpses lie still on the side of the road. Darkness blankets the area." );
    set_items(([
        "corpses" : "corpses covered in blood.",
        "shadows" : "Deep dark shadows",
        "ground" : "The ground shines",
      ]));
    set_smell("default", "Death.");
    set_listen("default", "Foot steps can be heard all around.");
    set_exits( ([
        "west" : ROOMS "square",
        "south" : ROOMS "room3",
      ]) );
    set_heart_beat(1);
}
void reset() {
    ::reset();
    // The following two lines are for night mobs
    if (query_night() && !present("werewolf", this_object())) {
        new(MOB"4")->move(this_object());
    }
    // the following two lines are for day mobs
    if (!query_night() && !present("paladin", this_object())) {
        new(MOB"1")->move(this_object());
    }
}
void init() {
    ::init();
    set_heart_beat(1);
}
void move(object ob) {
    message("info", ob->query_cap_name()+" leaves.", this_object());
    ob->move("/wizards/detach/aziera/rooms/removeroom.c");
}
void heart_beat() {
    int i, check;
    object *ob = ({ }), you;
    if (!query_night()) {
        if ((you = present("werewolf", this_object())))
            move(you);
    }
    if (query_night()) {
        if ((you = present("paladin", this_object())))
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
