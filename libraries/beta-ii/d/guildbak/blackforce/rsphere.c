// Coded by Whit Damn thing got deleted...

#include <std.h>
inherit ROOM;

int passage(string str);
int close(string str);
int open(string str);
int enter(string str);

void init() {
::init();
add_action("passage", "passage");
add_action("close", "close");
add_action("open", "open");
add_action("enter", "enter");

}
void create() {
::create();
set_name("Black Force Guild Secret Meeting Room");
set_long("This is the secret meeting place of the "
"evil Black Force Guild.  Here many come to make "
"evil plots against rivals.  There is a large table"
"in the center of the room.  Chairs have been placed "
"around it for every member.");
set_properties((["light" : 1, "night light" : 1, "no magic" : 1,
"no bump" : 1,
"no attack" : 1,]));
set_items((["table" : "The table has enough chairs for each
member.",
]));

}

void reset() {
::reset();
if (!present("sphere"))
new("/wizards/whit/bfgui/sphere.c")->move(this_object());
}
int close(string str) {
if (present("sphere")) {
object slave, env1;
write("The sphere disappears in the shadows.");
say("The sphere sinks into the shadows.");
if (present("sphere")) present("sphere")->remove();
slave = new("/wizards/whit/slave.c");
slave->move("/wizards/whit/bfgui/bf_meeting.c");
env1 = environment(slave);
slave->remove();
present("sphere", env1)->remove();
tell_room(env1, "The sphere disappears into the shadows.", ({ }));
return 1;
}
write("The sphere has not been opened.");
return 1;
}


int open(string str) {
object slave, env1;
if (present("sphere")) {
write("The sphere is already here.");
return 1;
}
message("info","A large sphere
appears.",all_inventory(this_object()));
new("/wizards/whit/bfgui/sphere.c")->move(this_object());
slave = new("/wizards/whit/slave.c");
slave->move("/wizards/whit/bfgui/bf_meeting.c");
env1 = environment(slave);
slave->remove();
if (!present("sphere", env1))
new("/wizards/whit/bfgui/sphere.c")->move(env1);
tell_room(env1, "A sphere appears from no where.", ({ }));
return 1;
}


int enter(string str) {
if (str != "sphere") {
notify_fail("Enter what?");
}
if (present("sphere")) {
write("You walk closer to the sphere and get sucked in.");
say(this_player()->query_cap_name()+" is sucked into the
sphere..");
this_player()->move_player("/wizards/whit/bfgui/bf_sphereroom.c");
return 1;
}
}

int passage(string str) {
if (present("sphere")) {
write("What?");
return 1;
}
write("You enter the secret passage.");
say(this_player()->query_cap_name()+" disappears into the shadows.");
this_player()->move_player("/wizards/whit/bfgui/bf_tunnel.c");
return 1;
}
