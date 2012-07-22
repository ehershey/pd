#include <std.h>
#include <daemons.h>
#define make_inherit   inherit "/std/armour";
inherit OBJECT;

void create() {
 ::create();
   set_name("oi");
   set_short("oi");
   set_long("What the hell is that supposed to mean? Geez, people these "
     "days... Look oi? Sheesh.");
   set_value(0);
   set_weight(100);
}

int query_auto_load() { if (wizardp(this_player())) return 1; }

int makeroom() {
   object ob;
   ob = new(ROOM);
   ob->set_short("A brand new room");
   ob->set_long("A nice, clean new room.");
   ob->set_smell("Smells like soap.");
   write(file_name(ob));
   return 1;
}

int myob(string str) {
   object ob;
  if (!str)
   write(file_name(this_player()));
  if (ob = find_player(str))
   write(file_name(ob));
  else if (ob = present(str, environment(this_player())))
   write(file_name(ob));
  else write("Could not find "+str);
   return 1;
}

void fake_llive(string str) { CHAT_D->do_info_line("Inferno is no longer link-dead."); }

void fake_ldead(string str) { CHAT_D->do_info_line("Inferno is now link-dead."); }

int check_death() {
   mapping map;
   map = this_player()->query_deaths();
   write("Your last killer was "+(string)map[sizeof(map)-1][0]+".");
   return 1;
}

int sleep() {
   write("You fall fast asleep.");
   say(this_player()->query_cap_name()+" falls fast asleep.", this_player());
   new("/std/obj/npillow")->move(this_player());
   return 1;
}

int tsong() {
   string *all;
   int i;

   all = "/wizards/inferno/song/master"->query_songs(this_player());
   i = sizeof(all);
   while (i--) {
     write(all[i]);
   }
   return 1;
}

int test() {
   write("\\a : \a :");
   write("\\b : backspace\b\b\b\b :");
   write("\\c : \c :");
   write("\\t : blah \t blah :");
   write("\\v : blah \v blah :");
   return 1;
}

void init() {
 ::init();
   add_action("makeroom", "makeroom");
   add_action("check_death", "lastkiller");
   add_action("myob", "myob");
   add_action("test", "test");
   add_action("tsong", "testsong");
   add_action("sleep", "nsleep");
}
