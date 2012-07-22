#include <std.h>
inherit ROOM;

static object lob, loc;
static int winup, cdoors;

object query_location();  // Returns location of limo object (lob)
int set_win_up(int x);    // Changes window status: open/closed (1/0)
int change_doors(int x);  // Changes door status: open/closed (0/1)
int set_limo_ob(object ob);//Sets the limo object that room looks at
int update_location(object ob);// Updates location of limo
string look_windows();    // Used to look at windows: open/closed
int look_outside(string str); // Used to look outside into limo's location
int go_out();             // Exit the room to limo location
int close_door(string str);//Close the limo door
int open_door(string str);// Open the limo door
int roll_window(string str);//Allows people in limo to roll up/down window
int splice_say(string str);//Splices says to location and limo_room
int hit_n_run(string str);// Used to run over people in the limo location
int drive_dir(string str);// Drive directions

void create() {
 ::create();
   set_short("Inside a long, black limousine");
   set_long("%^BOLD%^%^BLACK%^"
      "The inside of the long, black limousine is very luxerious. "
      "Two rows of black, leather cusioned seats line the two longer "
      "sides. A clear glass partition seperates the passenger compartment "
      "from the driver's seat. A television has been afixed to the "
      "ceiling, at the front of the limo, above the isle of the two "
      "seats.");
   set_exits(([
      "out" : "/you/are/trapped"
   ]));
   set_items(([
      "seats" : "The seats are leather and very comfortable.",
      "partition" : "It seperates the driver from the passengers.",
    ({"windows", "window" }) : (: look_windows() :),
      "television" : "It has been turned off.",
      "isle" : "There is a thin isle between the two rows of seats."
   ]));
}

int go_out() {
   if (!loc) return notify_fail("%^RED%^[-]%^RESET%^ Error: "
     "No limo environment found.\n");
   if (cdoors) {
     write("The door is closed.");
     return 1;
   }
   this_player()->move_player(file_name((object)loc), "out");
   return 1;
}

int open_door(string str) {
   if (!str) return 0;
   if (str != "door" && str != "limo door") return 0;;
   if (!cdoors) return notify_fail("The limo door is already open.\n");
   cdoors = 0;
   lob->change_doors(0);
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " opens the door.", ({ this_player() }));
   write("You open the door.");
   tell_room(loc, "The limo door swings open.", ({ }));
   return 1;
}

int close_door(string str) {
   if (!str) return 0;
   if (str != "door" && str != "limo door") return 0;;
   if (cdoors) return notify_fail("The limo door is already closed.\n");
   cdoors = 1;
   lob->change_doors(1);
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " closes the door.", ({ this_player() }));
   write("You close the door.");
   tell_room(loc, "The limo door slams shut.", ({ }));
   return 1;
}

int roll_window(string str) {
   if (!str) return 0;
   if (str != "window" && str != "windows") return 0;
   if (winup) {
      write("You roll the windows down.");
      tell_room(this_object(), this_player()->query_cap_name()+
       " rolls the window down.", ({ this_player() }));
      tell_room(loc, "The limo window rolls down from the inside.", ({}));
      winup = 0;
      lob->set_win_up(0);
      lob->check_long();
      return 1;
   }
   write("You roll the window up.");
   tell_room(this_object(), this_player()->query_cap_name()+
      " rolls the window up.", ({ this_player() }));
   tell_room(loc, "The limo window rolls up from the inside.", ({ }));
   winup = 1;
   loc->set_win_up(1);
   return 1;
}

int splice_say(string str) {
   if (!str || winup != 0) return 0;
   if (!lob) return 0;
   tell_room(loc, "%^CYAN%^Inside the limo you hear "+this_player()->query_cap_name()+
     " say:%^RESET%^ "+str, ({ }));
   return 0;
}

int hit_n_run(string str) {
   object ob;
   if (!(ob = present(str, loc))) return 0;
   if (!present("limo_keys", this_player())) {
     write("You do not have the keys.");
     return 1;
   }
   write("You swerve to hit "+ob->query_cap_name()+"!");
   say(this_player()->query_cap_name()+" swerves to hit "
     +ob->query_cap_name()+"!", this_player());
   tell_room(loc, "The limo swerves and slams into "+ob->query_cap_name()+
     "!", ({ ob }));
   tell_object(ob, "The limo swerves and slams into you!");
   tell_room(this_object(), "The limo slams into "+ob->query_cap_name()+
     "!", ({ }));
   ob->die();
   return 1;
}

int drive_dir(string str) {
   int i;
   string tmp;
   object dir, *all=({});
   if (!str) return 0;
   if (!loc || !lob) {
     write("%^RED%^[-]%^RESET%^ Error: Limo/Location not found.");
     return 1;
   }
   if (loc->query_exit(str) == "/d/standard/void")
     return notify_fail("You cannot drive that way.\n");
   if (!(dir = (object)loc->query_exit(str)))
     return notify_fail("You can't drive that way.\n");
   lob->move(dir);
   write("You drive "+str+".");
   tell_room(this_object(), "The limo drives "+str+".",
     ({ this_player() }));
   tell_room(loc, "The limo drives "+str+".", ({ }));
   loc = environment(lob);
   tell_room(this_object(), loc->query_short(), ({ }));
   all = all_inventory(this_object());
   i = sizeof(all);
   while(i--) {
     if (all[i]->is_player()) {
      if ((tmp = loc->query_long()))
       message("desc", tmp, all[i]);
      tmp = "%^GREEN%^"+loc->query_long_exits()+"%^RESET%^";
       message("desc", tmp, all[i]);
      if ((tmp = loc->describe_living_contents(({this_player()}))) != "")
       message("desc", tmp, all[i]);
      if ((tmp = loc->describe_item_contents(({}))) != "")
       message("desc", tmp, all[i]);
     }
   }
   return 1;
}

void init() {
 ::init();
   add_action("look_outside", "look"); // Check for look outside
   add_action("drive_dir", "drive");
   add_action("splice_say", "say");
   add_action("close_door", "close");
   add_action("hit_n_run", "hit");
   add_action("roll_window", "roll");
   add_action("open_door", "open");
   add_action("go_out", "out"); // Leave the limo
}

int look_outside(string str) {
   string tmp;
   if (str != "outside" && str != "outside now") return 0;
   if (!loc) return notify_fail(
    "%^RED%^[-]%^RESET%^ Error: No limo environment.\n");
  if (str == "outside")
   write("You look outside.");
   if ((tmp = loc->query_long()))
    write(tmp);
   tmp = "%^GREEN%^"+loc->query_long_exits()+"%^RESET%^";
    write(tmp);
   if ((tmp = loc->describe_living_contents(({this_player()}))) != "")
    write(tmp);
   if ((tmp = loc->describe_item_contents(({}))) != "")
    write(tmp);
  if (str == "outside")
   tell_room(this_object(), this_player()->query_cap_name()+" looks "
    "outside.", ({ this_player() }));
   return 1;
}

string look_windows() {
   string str="The windows are rolled ";
   if (winup) str += "up.";
   else str += "down.";
   str += " You could look outside to see where you are.";
   return str;
}

int update_location(object ob) {
   loc = ob;
   return 1;
}

object query_location() { return loc; }

int set_limo_ob(object ob) { lob = ob; return 1; }

int set_win_up(int x) { winup = x; return 1; }

int change_doors(int x) { cdoors = x; return 1; }
