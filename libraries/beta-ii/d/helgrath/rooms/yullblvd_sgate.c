#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
	"light" : 2,
      ]));
    set_short("The Gates of Yalth");
    set_long("The southern gates of the inner city dominate the entire area. Massive stone "
      "walls boast impenetrable iron gates, fortified by huge, menacing guard towers standing "
      "vigil over the south wall. " );
    set_exits( ([ "north" : ROOMS "yullblvd_s05.c",
	"gate" : ROOMS "tundra_path01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A slight breeze whistles through the gates.");

}

void reset(){
    ::reset();
    if(present("guardian")) return;
    new(MOB"guardian.c")->move(this_object());
    if(present("guardian 2")) return;
    new(MOB"guardian.c")->move(this_object());
}
