#include <std.h>
inherit ROOM;
int lock, open;
void create() {
    ::create();
    set_property("light", 1);
    set_short("Helgrath Woods");
    set_long("At the bottom of a steep, jagged rock embankment, a massive "
      "iron-bound oak "
      "door, framed by dark, stone walls of the cave entrance comes into view "
      "directly to the north. "
      "A large, twisted tree hangs precariously from its perch atop the rock "
      "walls of the cave.");
    set_exits ( (["north" :
      "/d/helgrath/rooms/draege_entrance",
      "east" : "/wizards/vhaldir/tempareas/helgrath/forest_lake_w01"]) );
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "a faint humming noise emenates from the cavern walls." );
}
void init() {
    ::init();
    add_action("go_north", "north");
    add_action("close", "close");
    add_action("lock", "lock");
    add_action("unlock", "unlock");
    add_action("open", "open");
    add_action("peer", "peer");
}
void reset() {
    ::reset();
    open=0;
    lock=1;
}
int close(string str) {
    if(!str) {
	write("Close what?\n");
	return 1;
    }
    if(str != "door") {
	write("Close what?\n");
	return 1;
    }
    if(open==0) {
	write("The door is already closed.\n");
	return 1;
    }
    write("You close the door.\n");
    say(this_player()->query_cap_name()+" closes the door.");
    open=0;
    return 1;
}
int open(string str) {
    if(!str) {
	write("Open what?\n");
	return 1;
    }
    if(str !="door") {
	write("Open what?\n");
	return 1;
    }
    if(lock==1) {
	write("The door is locked.\n");
	return 1;
    }
    if(open==1) {
	write("The door is already opened.\n");
	return 1;
    }
    write("You open the door.\n");
    say(this_player()->query_cap_name()+" opens the door.");
    open=1;
    return 1;
}
int lock(string str) {
    if(!str) {
	write("Lock what with what?\n");
	return 1;
    }
    if(str !="door with key") {
	write("Lock what with what?\n");
	return 1;
    }
    if(lock==1) return notify_fail("The door is already locked.\n");
    if(open==1) return notify_fail("The door must be closed to lock it.\n");
    if(!present("dkey", this_player())) {
	write("You do not have the key!\n");
	return 1;
    }
    write("You lock the door with the key.\n");
    say(this_player()->query_cap_name()+" locks the door.");
    lock=1;
    return 1;
}
int unlock(string str) {
    if(!str) {
	write("Unlock what with what?\n");
	return 1;
    }
    if(str !="door with key") {
	write("Unlock what with what?\n");
	return 1;
    }
    if(lock==0) {
	write("The door is already unlocked.");
	return 1;
    }
    if(!present("dkey", this_player())) {
	write("Unlock what with what?");
	return 1;
    }
    say(this_player()->query_cap_name()+" unlocks the door.");
    write("You unlock the door with your key.\n");
    lock=0;
    return 1;
}
int go_north() {
    if(open==0) {
	write("The door is closed.\n");
	say(this_player()->query_cap_name()+" bumps into the closed door.");
	return 1;
    }
    this_player()->move_player("/wizards/vhaldir/tempareas/helgrath/draege_entrance.c");
    say("The door clicks locked as "+this_player()->query_cap_name()+" leaves north.");
    open=0;
    lock=1;
    return 1;
}
int peer(string str) {
    if(!str) return 0;
    if(str !="north") return 0;
    if(open==1) {
	write("The door is in your way.\n");
	return 1;
    }
    return 0;
}
