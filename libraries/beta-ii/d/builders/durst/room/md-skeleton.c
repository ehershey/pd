#include <std.h>
#include <durst.h>

inherit ROOM;

int Found;

void create() {
        ::create();
        set_property("light", 3);
       set_short("MuaBark Desert");
        set_long("Sand dunes in every direction, the desert is endless in size. The desert winds blow from different directions every few seconds, kicking up sand into the air. The air is heavy and dry from all the sand. There is a skeleton half-buried in the sand.");
        set_items(([
                ({"skeleton", "bones"}) : (: this_object(), "look_at_skel" :)
                ]));
        set_exits(([
                "east"          : ROOMS "muabark066.c"
                ]));

        set_exits(([
            "east" : ROOMS "muabark066.c"
                ]));
        Found = 0;
}

void init() {
        ::init();
        add_action("search_skeleton","search");
        if( Found != 0 )
        {
            add_item("skeleton", "Just some bleached bones." );
            add_item("bones", "Just some bleached bones." );
        }
        else
        {
            add_item("skeleton", "There's a small object in the skeleton's hand." );
            add_item("bones", "There's a small object in the skeleton's hand."
);
        }
}

void reset() {
        ::reset();
        Found = 0;
        add_item("skeleton", "There's a small object in the skeleton's hand."
);
        add_item("bones", "There's a small object in the skeleton's hand." );
}

int search_skeleton(string str) {
        if( Found != 0 )
                return 0;

        if( str == "skeleton" || str == "bones" )
        {
                write("You find a small canteen in the skeleton's hand.");
                message("other action", this_player()->query_cap_name()+
                        " finds a small canteen in the skeleton's hand.",
                this_object(), ({ this_player() }));
                new(OBJ"nes_canteen.c")->move(this_player());
                remove_action("search_skeleton","search");
                Found = 1;
                add_item("skeleton", "Just some bleached bones." );
                add_item("bones", "Just some bleached bones." );
                return 1;
        }
        else
                return 0;
}

