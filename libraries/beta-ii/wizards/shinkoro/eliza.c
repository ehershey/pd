// Shinkoro's Nymph
#include <std.h>
inherit MONSTER;
static int oi;
void create() {
 ::create();
   set_name("eliza");
   set_id(({ "eliza" }));
    set_short("Eliza, Shin's Nymph");
set_level(1000);
    set_long("Standing just over 5ft, Eliza is the picture of perfection.  Long %^YELLOW%^blonde%^RESET%^ hair flows down to her heartly shaped butt."
" Her %^GREEN%^green eyes%^RESET%^ will put you in a trance if you stare too long. Her breasts are half visible from "
"the low v cut %^BOLD%^%^BLACK%^black silk%^RESET%^ and%^BOLD%^%^WHITE%^ lace%^RESET%^ dress she is wearing."
" It makes your mouth dry and your loins quiver as you look over this stunning 36-24-37 Nymph bombshell!"
" But don't get to obsessed with this ravaging beauty.  Just above the crease of her two breasts as they round down into her dress there is a small tattoo of her one and only lover....."
"%^BOLD%^RED%^SHINKORO");
   set_body_type("human");
    set_race("nymph");
    set_gender("female");
    set_class("clergy");
    new("/wizards/shinkoro/blackdress.c")->move(this_object());
    set_heart_beat(1);
}
void init()
{

  ::init();
}
void heart_beat()
{
  if(find_player("shinkoro")) {
this_object()->force_me("wear dress");
    if(environment(this_object()) != environment(find_player("shinkoro"))) {
      say(this_object()->query_cap_name()+" runs after %^RED%^Shinkoro%^RESET%^.");
      this_object()->move(environment(find_player("shinkoro")));
      say(this_object()->query_cap_name()+" walks in, and pinches Shinkoro's %^RED%^tushie!%^RESET%^ ");
}
    if(random(100) < 3)
this_object()->force_me("lick shinkoro");
    if(random(100) < 7)
this_object()->force_me("emote %^RED%^kisses%^RESET%^ Shinkoro softly on his neck and ear!");
    if(random(100) == 99)
this_object()->force_me("emote %^BOLD%^%^BLUE%^begs %^RED%^Shinkoro%^RESET%^ to take her to bed!");
  }
  ::heart_beat();
}
int die() { return 1; }
int is_invincible() { return 1; }
