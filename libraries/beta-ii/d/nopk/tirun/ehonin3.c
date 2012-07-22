#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("South Veros Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun.  Some distance west of here is the Tirun Market.  Far to the east "
      "the city gates can be seen.  The building to the north has a sign with a "
      "%^RED%^red cross%^RESET%^ painted on it hanging above the door.  Ancient "
      "stones underfoot run east and west, making the road easy to traverse. ");
    set_night_long(
        "Honin Road is mostly deserted at night.  To the north the shadow of a "
        "building forms in the darkness. The road continues to the east and west. "
        " The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["west" : ROOMS"ehonin2",
                "east" : ROOMS"ehonin4",
                "enter hospital": ROOMS"hospital.c",
]) );
add_exit_alias("enter hospital", "hospital");
add_exit_alias("enter hospital", "enter");

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads to Arulo Juncture west and out "
            "of town east.",
          "juncture" : "The central square of Tirun."]) );
}
void reset() {
    ::reset();
     if (children("/d/nopk/tirun/obj/mon/eboy.c")==({})||
         sizeof(children("/d/nopk/tirun/obj/mon/eboy.c"))==0)
            new(MOB "eboy")->move(this_object());
        
}
