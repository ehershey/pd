// coded by wiz Sun May 27 14:43:30 HST 2001
#include <std.h>
#include <terra.h>
inherit MONSTER;
int step;   

void set_step(int i){ step=i; }
int query_step(){ return step; }

void create() {
 ::create();
  set_name("girl");
  set_id( ({ "girl", "vampire", "sad girl", "very sad girl" }) );
  set_short("A very sad girl");
  set_level(1);
  set_exp(-300000);
  set_long("This girl looks extremely sad.  She is very beautiful and dressed up for the ball.\n"
           "Perhaps you should talk to her...");
  set_body_type("human");
  set_race("human");
  set_gender("female");
  set_step(0);
}

void catch_tell(string str) {
    string a, b;
    if((sscanf(str, "%shats wrong%s", a, b)==2 || sscanf(str, "%shat's wrong%s", a, b)==2)
       && this_player()->is_player() && query_step()==0) {
         set_step(-1);
         call_out("force_me", 2, "say Oh, I can't go to the ball...");
         call_out("force_me", 4, "say I waited all year for this but now I'm grounded...");
         call_out("force_me", 6, "say This invitation is worthless to me!");
         call_out("set_step", 6, 1);
    }

    if(sscanf(str, "%snvitation%s", a, b)==2 && this_player()->is_player() && query_step()==1) {
         set_step(-1);
         call_out("force_me", 2, "say You want my invitation?");
         call_out("force_me", 4, "say I suppose I could sell it to you and make my money back...");
         call_out("force_me", 6, "say Would you really like to buy it?");
         call_out("set_step", 6, 2);
    }

    if((sscanf(str, "%sYes%s", a, b)==2 || sscanf(str, "%syes%s", a, b)==2) &&
       this_player()->is_player() && query_step()==2) {
         set_step(-1);
         call_out("do_money", 1, this_player());
         new(ITEM "ballpass")->move(this_object());
         call_out("force_me", 3, "give ballpass to "+this_player()->query_cap_name());
         call_out("force_me", 5, "say Thanks!");
         call_out("force_me", 5, "smile");
         call_out("set_step", 6, 3);
         call_out("backstab", 9, this_player()->query_name());
    }
}

void do_money(object tp){
  int m=this_player()->query_money("gold");
  if(m>10000)m=10000;
  tp->add_money("gold", -m);
  message("quest", "You give the girl some gold.", this_player());
  message("quest", this_player()->query_cap_name()+" gives the girl some gold.", 
          environment(this_player()), ({ this_player(), this_object() }) );
}

void do_demon(string name){
  set_subclass("assassin");
  set_class("rogue");
  set_race("demon");
  set_exp(500000);
  set_skill("knife", 200);
  set_skill("murder", 500);
  set_alignment(-500);
  set_level(75);
  message("quest", "%^BOLD%^%^RED%^The girl's skin turns into flames!%^RESET%^",
          environment(this_object()), this_object());
  new(WEP "riskydag")->move(this_object());
}

void backstab(string name){
  if(!present(name, environment(this_object())))return;
  call_out("force_me", 0, "grin");
  call_out("do_demon", 1, name);
  call_out("force_me", 2, "wield dagger");
  call_out("force_me", 3, sprintf("backstab %s", name));
}

void heart_beat(){
 ::heart_beat();
  if(query_step()==0)if(random(100)<5)force_me("cry");
}
