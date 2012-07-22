#include <std.h>
#include <daemons.h>
inherit MONSTER;
int test_heart;
void create()
{
 ::create();
 set_name("rejik the peddler");
 set_level(20);
 set_short("Rejik the peddler");
 set_long("A stout middle aged man selling gifts. Say list items to have Rejik "
          "tell you what he has and how much it costs. It is rumored he may also sell weapons.");
 set_race("human");
 set_body_type("human");
 set_gender("male");
 set_id( ({ "rejik", "peddler", "rejik the peddler" }) );
 set_heart_beat(1);
 set_patrol(12, ({ "west", "south", "south", "east", "east", "north", "north", "west", }) );
 set_emotes(3,({
   "%^CYAN%^Rejik exclaims: %^RESET%^Fresh cut roses for sale!",
}),0);
 set_exp(1);
 add_money("copper", random(1000));
}
int is_invincible() {return 1;}
void init()
{
 ::init();
 add_action("fBuy", "buy");
}
int fBuy(string str)
{
 if (!str)
   {  
    this_object()->force_me("say Buy what?");
    return 1;
   }
 if (str!="red rose" && str!="yellow rose" && str!="white rose" && str!="redrose" && str!="yellowrose" && str!="whiterose" && str!="sword" && str!="dagger" && str!="club" && str!="axe" && str!="flail" && str!="spear")
   {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
   }
 switch(str)
 {
  case "redrose": case "red rose":
  if (this_player()->query_money("copper") < 52)
   { this_object()->force_me("say You do not have enough copper for this.");
     return 1;
   }
  this_player()->add_money("copper", -52);
  write("Rejik hands you a %^BOLD%^%^GREEN%^---<--{(%^RED%^@%^RESET%^.");
  say("Rejik hands "+this_player()->query_cap_name()+" a %^BOLD%^%^GREEN%^---<--{(%^RED%^@%^RESET%^.");
  new("/d/nopk/tirun/obj/misc/gifts/redrose.c")->move(this_player());
  return 1;
  break;
  case "whiterose": case "white rose":
  if (this_player()->query_money("copper") < 52)
   { this_object()->force_me("say You do not have enough copper for this.");
     return 1;
   }
  this_player()->add_money("copper", -52);
  write("Rejik hands you a %^BOLD%^%^GREEN%^---<--{(%^WHITE%^@%^RESET%^.");
  say("Rejik hands "+this_player()->query_cap_name()+" a %^BOLD%^%^GREEN%^---<--{(%^WHITE%^@%^RESET%^.");
  new("/d/nopk/tirun/obj/misc/gifts/whiterose.c")->move(this_player());
  return 1;
  break;
  case "yellowrose": case "yellow rose":
  if (this_player()->query_money("copper") < 52)
   { this_object()->force_me("say You do not have enough copper for this.");
     return 1;
   }
  this_player()->add_money("copper", -52);
  write("Rejik hands you a %^BOLD%^%^YELLOW%^@%^GREEN%^)}-->---%^RESET%^.");
  say("Rejik hands "+this_player()->query_cap_name()+" a %^BOLD%^%^YELLOW%^@%^GREEN%^)}-->---%^RESET%^.");
  new("/d/nopk/tirun/obj/misc/gifts/yellowrose.c")->move(this_player());
  return 1;
  break;
  case "sword":
  if (this_player()->query_money("gold") < 1)
   { this_object()->force_me("say You do not have enough gold for this.");
     return 1;
   }
  this_player()->add_money("gold", -1);
  write("Rejik hands you a sword");
  say("Rejik hands "+this_player()->query_cap_name()+" a sword");
  new("/d/nopk/tirun/obj/weapon/noobsword.c")->move(this_player());
  return 1;
  break;
  case "spear":
  if (this_player()->query_money("gold") < 1)
   { this_object()->force_me("say You do not have enough copper for this.");
     return 1;
   }
  this_player()->add_money("gold", -1);
  write("Rejik hands you a spear.");
  say("Rejik hands "+this_player()->query_cap_name()+" a spear.");
  new("/d/nopk/tirun/obj/weapon/noobspear.c")->move(this_player());
  return 1;
  break;
  case "dagger":
  if (this_player()->query_money("gold") < 1)
   { this_object()->force_me("say You do not have enough copper for this.");
     return 1;
   }
  this_player()->add_money("gold", -1);
  write("Rejik hands you a dagger.");
  say("Rejik hands "+this_player()->query_cap_name()+" a dagger");
  new("/d/nopk/tirun/obj/weapon/noobdagger.c")->move(this_player());
  return 1;
  break;
  case "club":
  if (this_player()->query_money("gold") < 1)
   { this_object()->force_me("say You do not have enough gold for this.");
     return 1;
   }
  this_player()->add_money("gold", -1);
  write("Rejik hands you a club");
  say("Rejik hands "+this_player()->query_cap_name()+" a club");
  new("/d/nopk/tirun/obj/weapon/noobclub.c")->move(this_player());
  return 1;
  break;
  case "axe":
  if (this_player()->query_money("gold") < 1)
   { this_object()->force_me("say You do not have enough copper for this.");
     return 1;
   }
  this_player()->add_money("gold", -1);
  write("Rejik hands you an axe.");
  say("Rejik hands "+this_player()->query_cap_name()+" an axe");
  new("/d/nopk/tirun/obj/weapon/noobaxe.c")->move(this_player());
  return 1;
  break;
  case "flail":
  if (this_player()->query_money("gold") < 1)
   { this_object()->force_me("say You do not have enough copper for this.");
     return 1;
   }
  this_player()->add_money("gold", -1);
  write("Rejik hands you a flail.");
  say("Rejik hands "+this_player()->query_cap_name()+" a flail");
  new("/d/nopk/tirun/obj/weapon/noobflail.c")->move(this_player());
  return 1;
  break;
 }
}
int test_heart() { 
    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
 return 1; 
}
void catch_tell(string str) {
    string a, b;
    if(sscanf(str, "%slist items%s", a, b) == 2) {
        this_object()->force_me("say I have the following on sale for 52 copper each...\n"
          " red rose, white rose, and yellow rose. ");
        return;
    }
    if(sscanf(str, "%slist weapons%s", a, b) == 2) {
        this_object()->force_me("emote glances around nervously."); 
        this_object()->force_me("say How did you find out??");
        this_object()->force_me("say Well don't tell anyone, the law around here is strict about who sells weapons.");
        this_object()->force_me("emote glances around nervously."); 
        this_object()->force_me("say I have a few weapons for 1 gold each...\n"
          " axe, club, dagger, flail, spear, and sword. ");
        return;
    }
}
