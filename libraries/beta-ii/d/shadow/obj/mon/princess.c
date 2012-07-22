#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("princess");
  set("id",({"princess","lord","cassiopia","monster"}));
  set_level(28);
  set("short","Princess Cassiopia");
  set("long","The Princess is happily chatting with her maids.");
  set("race","elf");
  set_gender("female");
  set_body_type("human");
  set_alignment(300);
  new(ARM "wdress.c")->move(this_object());
  this_object()->force_me("wear dress");
  set("aggressive",1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi Somebody help me!"+
      (string)previous_object()->query_cap_name()+" is trying to kill me!  Aiieeeee!");
    return 0;
}
