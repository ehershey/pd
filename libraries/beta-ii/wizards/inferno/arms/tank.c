#include <std.h>
#define LROOM "/wizards/inferno/arms/tank_room"
inherit OBJECT;

static int winup, cdoors;
static object tank_ob;

string check_windows();
void check_long();
int init_tank(string str);

string check_windows() {
   string str="The windows are rolled ";
   if (winup) str += "up.";
   else str += "down.";
   return str;
}

void create() {
 ::create();
   set_name("tank");
   set_short("a huge tank");
   set_long("The large tank has been sent here from the realm of chaos. A long, "
     "thick barrel sticks out of the front.");
   set_value(0);
}

void check_long() {
   set_long("The huge tank has been sent here from the realm of chaos. "
     +check_windows()+" A long, thick barrel sticks out of the front.");
}

int check_get(string str) {
   if (!str || present(str, environment(this_player())) != this_object())
     return 0;
   write("You cannot get that!");
   return 1;
}

int init_tank(string str) {
   object ob;
   if (!str || str != "tank") return 0;
   if (!present("tank_keys", this_player())) return notify_fail(
     "You do not have the keys to the tank.\n");
   if (environment(this_object())->is_living()) {
     this_object()->move(environment(this_player()));
     write("%^GREEN%^[*]%^RESET%^ Tank moved to non-living environment.");
   }
 if (ob = (object)LROOM)
   write("%^GREEN%^[*]%^RESET%^ Tank_room object found.");
 else write("%^RED%^[-]%^RESET%^ Tank_room object not found.");
 if (ob->set_tank_ob(this_object()))
   write("%^GREEN%^[*]%^RESET%^ This tank object sent to room.");
 else write("%^RED%^[-]%^RESET%^ Could not send tank object to tank_room.");
 if (ob->update_location(environment(this_object())))
   write("%^GREEN%^[*]%^RESET%^ This tank object's environment updated in tank_room.");
 else write("%^RED%^[-]%^RESET%^ Could not update tank environment in tank_room.");
   winup = 1;
 if (ob->set_win_up(1))
   write("%^GREEN%^[*]%^RESET%^ Windows rolled up on tank and tank_room.");
 else write("%^RED%^[-]%^RESET%^ Failed to roll up windows in tank_room.");
   cdoors = 1;
 if (ob->change_doors(1))
   write("%^GREEN%^[*]%^RESET%^ Door closed on tank and tank_room.");
 else write("%^RED%^[-]%^RESET%^ Doors failed to close in tank_room.");
   tell_object(ob, "%^GREEN%^You hear the engine start!%^RESET%^");
   check_long();
   tank_ob = ob;
   write("%^GREEN%^[*]%^RESET%^ Tank started!");
   say(this_player()->query_cap_name()+" starts the tank!", this_player());
   return 1;
}

void set_win_up(int x) { winup = x; }

int close_door(string str) {
   if (!str) return 0;
   if (str != "tank door" && str != "door")
     return notify_fail("Syntax: <open tank door>\n");
   if (cdoors) return notify_fail("The tank door is already closed.\n");
   cdoors = 1;
   tank_ob->change_doors(1);
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " closes the tank door.", ({ this_player() }));
   write("You close the tank door.");
   tell_room(tank_ob, "The door slams shut.", ({ }));
   return 1;
}

int open_door(string str) {
   if (!str) return 0;
   if (str != "tank door" && str != "door")
     return notify_fail("Syntax: <open tank door>\n");
   if (!cdoors) return notify_fail("The tank door is already open.\n");
   cdoors = 0;
   tank_ob->change_doors(0);
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " opens the tank door.", ({ this_player() }));
   write("You open the tank door.");
   tell_room(tank_ob, "The door swings open.", ({ }));
   return 1;
}

int enter_tank(string str) {
   if (!str) return 0;
   if (str != "tank") return 0;
   if (cdoors) {
     write("The tank door is closed.");
     return 1;
   }
   this_player()->move_player(LROOM, "tank");
   return 1;
}

int look_inside(string str) {
   string tmp;
   if (!str || str != "inside") return 0;
   if (!tank_ob) return notify_fail("%^RED%^[*]%^RESET%^ Error: "
     "Tank_ob not defined.\n");
   if ((tmp = tank_ob->query_long()))
    write(tmp);
   tmp = "%^GREEN%^"+tank_ob->query_long_exits()+"%^RESET%^";
    write(tmp);
   if ((tmp = tank_ob->describe_living_contents(({this_player()}))) != "")
    write(tmp);
   if ((tmp = tank_ob->describe_item_contents(({}))) != "")
    write(tmp);
   tell_room(this_object(), this_player()->query_cap_name()+" looks "
    "inside the tank.", ({ this_player() }));
   return 1;
}

int splice_say(string str) {
   if (!str || winup != 0) return 0;
   if (!tank_ob) return 0;
   tell_room(tank_ob, "%^CYAN%^Outside you hear "+this_player()->query_cap_name()+
     " say:%^RESET%^ "+str, ({ }));
   return 0;
}

void init() {
 ::init();
   add_action("init_tank", "start");
   add_action("close_door", "close");
   add_action("enter_tank", "enter");
   add_action("splice_say", "say");
   add_action("check_get", "get");
   add_action("look_inside", "look");
   add_action("open_door", "open");
}

void change_doors(int x) { cdoors = x; }
