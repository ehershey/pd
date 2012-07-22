#include <std.h>
#include <marsh.h>
inherit ROOM;
void init() {
    ::init();
    add_action("chop_tree", "chop");
}
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The golden tree stands proudly out on the ledge.  The "
      "island in the middle of the river is so close, but "
      "swimming across the river doesn't seem possible."
         
    );
    set_items(([
        "ledge" : "It is the closes you've ever been to "
                  "the city.",
        "island" : "It sits in the middle of the river, "
                   "and a city appears to be on it.",
        "city" : "It has torches around the outside of it, "
                 "taunting you to get to it.",
        "river" : "The current of the river is mighty strong.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"south" : HIVE "hive30",
    ])  );
}
void reset() {
 ::reset();
   if (!present("tree", this_object()))
     new( ITEMS "tree.c" )->move(this_object());
}
int chop_tree(string str) {
    int b;
    object gt;
    object *wield;
    if(!str) {
        notify_fail("Chop what?\n");
        return 0;
    }
    if(str != "tree") {
        notify_fail("You can't chop that!\n");
        return 0;
    }
    if (!present("treeaxe", this_player())){
        notify_fail("You need the right axe for the job!\n");
        return 0;
    }
    if (!b=sizeof(wield=(object *)this_player()->query_wielded("treeaxe"))) {
        notify_fail("You need to be wielding the axe to chop the tree!\n");
        return 0;
    } 
    if (!present("tree", environment(this_player()))){
        notify_fail("There is no tree here!\n");
        return 0;
    }
    message("info", (string)this_player()->query_cap_name()+" chops down the
Golden Tree.", this_object(), ({ this_player() }));
    message("info", "You take up the axe and chop down the golden tree.",
this_player());
    message("info", "The tree falls, creating a new path out of the room.",
this_player());
    gt = present("tree", this_object());
    gt->remove();
    if (!present("fallentree", this_object()))
     new( ITEMS "fallentree.c" )->move(this_object());
    add_exit(HIVE "hiv.c", "northeast");
    call_out("go_fallen", 300);
    return 1;
}
void go_fallen() {
    object gl;
    gl = present("fallentree", this_object());
    gl->remove();
    if (!present("tree", this_object()))
     new( ITEMS "tree.c" )->move(this_object());    
    remove_exit("northeast");
}
