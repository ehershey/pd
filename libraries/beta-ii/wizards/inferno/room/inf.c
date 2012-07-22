#include <std.h>
inherit ROOM;
static object var;
static int rolled;

object query_location();
void set_location(object ob);
int drive(string str);
int out();
int window(string str);

void create() {
   set_short("Inside a long, black limosine");
   set_long("You are inside of a long, black limosine. "
            "A small television sits above your head and "
            "a wine cabinet has been afixed onto the wall. "
            "The shaded windows line the side of the car.");
   set_exits(([ "out" : "/you/are/trapped" ]));
   set_items(([ "blah" : "That's right, blah.",
                "window" : "Just a normal window."]));
   set_properties((["light" : 2]));
}

void init() {
 ::init();
   add_action("out", "out");
   add_action("drive", "drive");
   add_action("window", "look");
   add_action("roll", "roll");
}

int roll(string str) {
   if (!str) return 0;
   if (str != "window") return 0;
   if (rolled) {
      write("You roll up the window.");
      tell_room(environment(this_player()), this_player()->query_cap_name()+
            " rolls up the window.", ({ this_player() }));
      rolled = 0;
      return 1;
   }
   write("You roll down the window.");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
         " rolls down the window.", ({ this_player() }));
   rolled = 1;
   return 1;
}

int drive(string str) {
   if (!str) return 0;
   if (!present("limo_keys", this_player())) return 0;
   if (var->query_exit(str) == "/d/standard/void") {
      notify_fail("You cannot drive that way!\n");
      return 0;
   }
   tell_room(var, "%^BOLD%^%^BLACK%^Inferno's limo drives "+str+".%^RESET%^", ({ }));
   present("limo", (object)var->move((object)var->query_exit(str));
   var = var->query_exit(str);
   tell_room(var, "%^BOLD%^%^BLACK%^A long black limo drives in.%^RESET%^", ({ }));
   tell_room(environment(this_player()),
             "%^CYAN%^Through the window you see:%^RESET%^", ({ }));
   tell_room(environment(this_player()), var->query_long());
   tell_room(environment(this_player()),"%^GREEN%^"+var->query_long_exits()+"%^RESET%^", ({ }));
   return 1;
}

int out() {
   write("%^BOLD%^%^GREEN%^You exit the limo%^RESET%^");
   tell_room(environment(this_player()), "%^BOLD%^%^GREEN%^"
         +this_player()->query_cap_name()+
         " leaves out.%^RESET%^", ({ this_player() }));
   this_player()->move(var);
   tell_room(var, "%^BOLD%^%^GREEN%^"+this_player()->query_cap_name()+
         " steps out of the limo.", ({ this_player() }));
   this_player()->force_me("look");
   return 1;
}

int window(string str) {
   if (!str || str != "window") return 0;
   if (!rolled) {
      write("The window is closed.");
      return 0;
   }
   write(var->query_long());
   write("%^GREEN%^Exits: "+var->query_long_exits()+"%^RESET%^");
   return 0;
}

void set_location(object ob) { var = ob; }

object query_location() { return var; }

void reset() {
 ::reset();
   if (!present("chest"))
      new("/wizards/inferno/chest")->move(this_object());
}
