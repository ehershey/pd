//Made using Room generator by Nightshade
//a dungeonware.net production
#include <std.h>
#include <tirun.h>
inherit ROOM;
int fruit;
void init() {
    ::init();
    add_action("do_pluck","pluck");
    add_action("open_tree", "open");
    add_action("read_runes", "read");
}
void create() {
    ::create();
    set_short("The Druid Grove.");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_property("forest", 1);
    set_listen("default", "Birds singing can be heard.");
    set_smell("default", "It smells of a afternoon spring rain.");
    set_long("A well tended grove of trees.  The area seems to radiate magic.  Some of the trees have fruit on them.   A massive tree dominates the center of the grove.  The tree is larger than any other in this forest.  A path leads to the south.");
    set_night_long("The grove of trees is more peaceful than the rest of the forest.  The darkness of night does not dimm the beauty of the grove.  A massive tree dominates the center of the grove.");
    set_exits( (["south" : ROOMS+"clergy/druid/druid_grove"
              ]) );
    set_items( ([ "trees" : "Fruit trees."
                 ,"fruit" : "Edible delicacies, perhaps you should pluck some."
                 ,"tree" : "The largest tree in the area. Druidic runes are marked upon the bark."
,"runes" : "The runes are beautiful. Perhaps you should try to read them."
                 ]) );
}
void reset() {
    ::reset();
      fruit = 1;
}
int do_pluck(string str) {
    if(!str) {
        notify_fail("Pluck what?\n");
        return 0;
    }
    if(str != "fruit") {
        notify_fail("You can't pluck that!\n");
        return 0;
    }
    if(fruit==0) {
        notify_fail("All the fruit seems to be gone.\n");
        return 0;
    }
    if(fruit=1) {      
    write("You pluck a nice juicey piece of fruit.");
     say((string)this_player()->query_cap_name()+" plucks a large juicey piece of fruit from a tree.");
    new(OBJ"fruit")->move(this_object());
    fruit=0;
    return 1;
  }
}
int read_runes(string str) {
    if(!str) {
        notify_fail("Read what?\n");
        return 0;
    }
    if(str != "runes") {
        notify_fail("You can't read that!\n");
        return 0;
    }
    if((this_player()->query_class() != "clergy")&&(this_player()->query_subclass() != "druid")) {
        message("info", "The runes are beautiful but make no sense to you.", this_player());
        return 1;
    }
    message("info", "This great tree is the home of our sect.", this_player());
    message("info", "If you can read this and druid you are not, enter to become so.", this_player());
    message("info", "Open the tree to find the way into our inner sanctum.", this_player());
    return 1;
}
int open_tree(string str) {
    if(!str) {
        notify_fail("Open what?\n");
        return 0;
    }
    if(str != "tree") {
        notify_fail("You can't open that!\n");
        return 0;
    }
    if((this_player()->query_class() != "clergy")&&(this_player()->query_subclass() != "druid")) {
        message("info", "The tree does not change.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" stares at the tree and an opening appears.", this_object(), ({ this_player() }));
    message("info", "You open a portal into the tree.", this_player());
    add_exit("/d/nopk/tirun/clergy/druid/druid_join.c", "enter");
    call_out("go_tree", 15);
    return 1;
}
void go_tree() {
    message("info", "The opening in the tree vanishes.", all_inventory(this_object()));
    remove_exit("enter");
}
