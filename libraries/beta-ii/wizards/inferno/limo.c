#include <std.h>
inherit OBJECT;

static int winup, cdoors;
static object limo_ob;

string check_windows();
void check_long();
int init_limo(string str);

string check_windows() {
   string str="The windows are rolled ";
   if (winup) str += "up.";
   else str += "down.";
   return str;
}

void create() {
 ::create();
   set_name("limo");
   set_short("a long black limo");
   set_long("The long black limo has shaded windows. "+check_windows()+
      " The limo looks very expensive.");
   set_value(0);
}

void check_long() {
   set_long("The long black limo has shaded windows. "+check_windows()+
      " The limo looks very expensive.");
}

int check_get(string str) {
   if (!str || present(str, environment(this_player())) != this_object())
     return 0;
   write("You cannot get that!");
   return 1;
}

int init_limo(string str) {
   object ob;
   if (!str || str != "limo") return 0;
   if (!present("limo_keys", this_player())) return notify_fail(
     "You do not have the keys to the limo.\n");
   if (environment(this_object())->is_living()) {
     this_object()->move(environment(this_player()));
     write("%^GREEN%^[*]%^RESET%^ Limo moved to non-living environment.");
   }
 if (ob = (object)"/wizards/inferno/room/limo_room")
   write("%^GREEN%^[*]%^RESET%^ Limo_room object found.");
 else write("%^RED%^[-]%^RESET%^ Limo_room object not found.");
 if (ob->set_limo_ob(this_object()))
   write("%^GREEN%^[*]%^RESET%^ This limo object sent to room.");
 else write("%^RED%^[-]%^RESET%^ Could not send limo object to limo_room.");
 if (ob->update_location(environment(this_object())))
   write("%^GREEN%^[*]%^RESET%^ This limo object's environment updated in limo_room.");
 else write("%^RED%^[-]%^RESET%^ Could not update limo environment in limo_room.");
   winup = 1;
 if (ob->set_win_up(1))
   write("%^GREEN%^[*]%^RESET%^ Windows rolled up on limo and limo_room.");
 else write("%^RED%^[-]%^RESET%^ Failed to roll up windows in limo_room.");
   cdoors = 1;
 if (ob->change_doors(1))
   write("%^GREEN%^[*]%^RESET%^ Door closed on limo and limo_room.");
 else write("%^RED%^[-]%^RESET%^ Doors failed to close in limo_room.");
   tell_object(ob, "%^GREEN%^You hear the engine start!%^RESET%^");
   check_long();
   limo_ob = ob;
   write("%^GREEN%^[*]%^RESET%^ Limo started!");
   say(this_player()->query_cap_name()+" starts the limo!", this_player());
   return 1;
}

void set_win_up(int x) { winup = x; }

int close_door(string str) {
   if (!str) return 0;
   if (str != "limo door" && str != "door")
     return notify_fail("Syntax: <open limo door>\n");
   if (cdoors) return notify_fail("The limo door is already closed.\n");
   cdoors = 1;
   limo_ob->change_doors(1);
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " closes the limo door.", ({ this_player() }));
   write("You close the limo door.");
   tell_room(limo_ob, "The door slams shut.", ({ }));
   return 1;
}

int open_door(string str) {
   if (!str) return 0;
   if (str != "limo door" && str != "door")
     return notify_fail("Syntax: <open limo door>\n");
   if (!cdoors) return notify_fail("The limo door is already open.\n");
   cdoors = 0;
   limo_ob->change_doors(0);
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " opens the limo door.", ({ this_player() }));
   write("You open the limo door.");
   tell_room(limo_ob, "The door swings open.", ({ }));
   return 1;
}

int enter_limo(string str) {
   if (!str) return 0;
   if (str != "limousine" && str != "limo") return 0;
   if (cdoors) {
     write("The limo door is closed.");
     return 1;
   }
   this_player()->move_player("/wizards/inferno/room/limo_room", "into the limo");
   return 1;
}

int look_inside(string str) {
   string tmp;
   if (!str || str != "inside") return 0;
   if (!limo_ob) return notify_fail("%^RED%^[*]%^RESET%^ Error: "
     "Limo_ob not defined.\n");
   if ((tmp = limo_ob->query_long()))
    write(tmp);
   tmp = "%^GREEN%^"+limo_ob->query_long_exits()+"%^RESET%^";
    write(tmp);
   if ((tmp = limo_ob->describe_living_contents(({this_player()}))) != "")
    write(tmp);
   if ((tmp = limo_ob->describe_item_contents(({}))) != "")
    write(tmp);
   tell_room(this_object(), this_player()->query_cap_name()+" looks "
    "inside the limo.", ({ this_player() }));
   return 1;
}

int splice_say(string str) {
   if (!str || winup != 0) return 0;
   if (!limo_ob) return 0;
   tell_room(limo_ob, "%^CYAN%^Outside you hear "+this_player()->query_cap_name()+
     " say:%^RESET%^ "+str, ({ }));
   return 0;
}

void init() {
 ::init();
   add_action("init_limo", "start");
   add_action("close_door", "close");
   add_action("enter_limo", "enter");
   add_action("splice_say", "say");
   add_action("check_get", "get");
   add_action("look_inside", "look");
   add_action("open_door", "open");
}

void change_doors(int x) { cdoors = x; }
