#include <wiz.h>
inherit ROOM;

void create() {
::create();
   set_short("wiz's house");
   set_long("wiz's house! yeh its the leetice place eto be its krad elite  woo yeh i am "
            "so cool.. okie now go buy some squishies and nachos mmm yummy okie buh buy");
   set_items((["carpet":"the carpet in wiz's house is a furry white, cool to the touch.",
               "stairs":"They lead down to wiz's cellar. Beware of the....", ]));
   set_properties(([ "light":2, "night light":1, "indoors":1, ]));
  set_exits(([ "up"   : HOUSEROOM "store.c",
                "down" : HOUSEROOM "cellar.c",
                "east" : "/d/arlon/room/house2.c",
                "south": HOUSEROOM "bedroom.c",
                "northeast" : HOUSEROOM "hall.c"]));
   set_invis_exits(({ "northeast" }));

}
void reset(){
 ::reset();
if(!present("cabinet"))new(HOUSEOBJ"cabinet.c")->move(this_object());
}
