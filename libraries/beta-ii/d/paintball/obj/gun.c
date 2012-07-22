#include <std.h>
inherit WEAPON;
static int loaded=3;
static string team, host="";
void add_point(int i);
void set_team(string str);
string query_team();
int scope(string str);
int shoot(string str);
void reload_gun();
void set_host(string str);

void create() {
 ::create();
   set_name("gun");
   set_short("%^BOLD%^%^MAGENTA%^a %^YELLOW%^pa%^RED%^in%^GREEN%^tb%^BLACK%^al%^RESET%^%^ORANGE%^l g%^BLUE%^un%^RESET%^");
   set_long("A small, blue and green paintball gun. You could "
            "probably %^CYAN%^<scope [person]>%^RESET%^ through the scope, or even "
            "shoot someone!");
   set_weight(3);
   set_value(100);
   set_id(({ "gun", "paintball gun" }));
   set_wc(1);
}

void init() {
 ::init();
   add_action("scope", "scope");
   add_action("shoot", "shoot");
}

int scope(string str) {
   object ob, env;
if(!str) return notify_fail("Scope who?\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
        " looks into the scope on "+this_player()->query_title_gender()+
        " paintball gun.", ({ this_player() }));
    if(!(ob = find_living(str))) {
        write("%^GREEN%^You cannot see that in your scope.%^RESET%^");
        return 1;
    }
    env = environment(ob);
    write("%^GREEN%^You see "+ob->query_cap_name()+" in your scope at:%^BOLD%^ "+env->query_short()+"%^RESET%^\n");
    return 1;
}

int shoot(string str) {
   object ob;

   if (file_name(environment(this_player()))=="/d/paintball/start")
      return notify_fail("Hey your not in the game yet.\n");

   if (!str) {
      write("Shoot whom?");
      return 1;
   }
   ob = present(str, environment(this_player()));
   if (!ob) {
      write("You do not see "+str+" here.");
      return 1;
   }
   if (!present("gun", ob)) {
      write(ob->query_cap_name()+" is not playing paintball tag!");
      ob->move("/d/standard/square");
      return 1;
   }
   if (loaded < 1) {
      write("You are still reloading!");
      return 1;
   }
   if (ob->query_paralyzed())
     return notify_fail("That player has already been shot. wait a few secs\n");
   loaded--;
  
   write("%^GREEN%^You shoot "+ob->query_cap_name()+"!");
   tell_object(ob, "%^GREEN%^"+this_player()->query_cap_name()+
         " shoots you in the stomache with a paintball gun!");
   tell_room(environment(ob), this_player()->query_cap_name()+
         " shoots "+ob->query_cap_name()+" with "
         +this_player()->query_title_gender()+" paintball gun!", ({ this_player(), ob }));
   if (present("gun", ob)->query_team() == team)
     {
     write("You shot your own team! You lose points.. tsk tsk");
     add_point(1);  
     }
   else add_point(0);
   ob->set_paralyze("You are in pain from the shot.", 2);
   call_out("reload_gun", 5, this_player());
   return 1;
}

void reload_gun() {
   tell_room(environment(this_player()), "%^MAGENTA%^"
         +this_player()->query_cap_name()+
         " reloads "+this_player()->query_title_gender()+
         " paintball gun!%^RESET%^", ({ this_player() }));
   write("%^MAGENTA%^You reload your paintball gun.%^RESET%^");
   loaded = 1;
}

void set_team(string str) { team = str; }

string query_team() { return team; }

void set_host(string str) { host = str; }
string query_host() { return host; }
void add_point(int i) {
   object ob;
   if (host == "") {
      write("%^YELLOW%^Could not find game host!");
      this_player()->move("/d/standard/square");
      this_object()->remove();
      return;
   }
   ob = find_living(host);
   if (i) present("slab", ob)->do_points(team, 1);
   else
   present("slab", ob)->do_points(team, 0);
}

