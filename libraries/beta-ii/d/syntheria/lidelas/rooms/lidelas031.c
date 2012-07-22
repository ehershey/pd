#include <std.h>
#include <lidelas.h>

inherit ROOM;

int preview();

void create()
{
    ::create();
        set_name("clergy hall");
        set_short("Clergy Hall");
        set_long("The inside of this church has a large number of small statues and paintings. At the far back of the church sits a large altar for people to pray at, it is made of solid gold. Rows of wooden seats go from the back of thechurch all the way to the alter. Huge banners hang from the ceiling, each one has a unique symbol woven into it. At the far back end of the church there are some stairs that go down. A few people are seen sitting in the wooden rows with their heads down. Children may <preview> what it is like to be a clergy.");
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,
        "indoors"     : 1,
        "town"        : 1, ]) );
        set_items(([
        "windows"    :  "Large stain glass windows that display various people and places."
            ]));
            set_listen("default", "The church is very quiet.");
            set_smell("default", "The air is very stale and dry.");
            set_exits(([
                        "south"         : ROOMS "lidelas030.c",
                        "down"          : ROOMS "lidelasChall.c",
        ]));
        add_pre_exit_function("down", "go_down");
}

void reset() {
   ::reset();
if (!present("father cearl", this_object()))
     new(MOB"father_cearl.c")->move(this_object());
}

void init() {

    ::init();
    add_action("preview","preview");
}


int preview() {
    if((string)this_player()->query_class() != "child") {
        message("info", "You have already chosen your path.", this_player());
        return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about clergys.",
this_player());

    write("Welcome, child!");
    write("Clergy are those people that believe in dedication of their "
      "lives to religion and to their holy, or unholy, beliefs.  The"
      "only uniting factor between all Clergy is that they are completely "
      "dedicated to their faith.  To become a clergy, type <become clergy>."
	);

    return 1;
}




int go_down() {
    if(!this_player()->is_player()) return 0;
    if(this_player()->query_position() == "wizard"){
        write("Mighty immortals are always welcome into the hall.");
    }else if(this_player()->query_class() != "clergy") {
        write("You can not enter!");
        return 0;
    }
    return 1;
}
