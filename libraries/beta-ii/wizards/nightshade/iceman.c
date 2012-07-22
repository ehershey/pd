#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

int count;

void blow_up();
void change_me();
int give( string str );
void set_count( int num );
int query_count();

void create() {
  ::create();
  set_name("strange wanderer");
  set_id( ({ "wanderer", "strange wanderer" }) );
  set_level(1);
  set_short("A strange wanderer");
  set_long("The unkempt wanderer shuffles about, muttering cryptic messages under his breath.  He does not respond to anything, obviously afflicted by his own demons so much that he has lost touch with reality.");
  set("race","human");
  set_gender("male");
  set_body_type("human");
  set_emotes(5, ({
  "%^RESET%^%^CYAN%^Wanderer mutters: %^RESET%^The fire shall be cleansed...",
  "%^RESET%^%^CYAN%^Wanderer mutters: %^RESET%^I need the pieces.."
  }), 0);
  set_alignment(1500);
  set_overall_ac(50);
  count = 0;
}

void init() {
  ::init();
  add_action("give","give");
}

int give(string str) {
  object ob;
  string what, who;

  if( sscanf( str, "%s to %s", what, who ) != 2 )
    return 0;

  if( present( who, environment(this_object()) ) != this_object() )
    return 0;

  if( !present( what, this_player() ) )
    return 0;

  if( base_name( present( what, this_player() ) ) != "/wizards/nightshade/iceshard" )
    return 0;

  count++;

  if( count >= 300 )
  {
    call_out( "change_me", 1 );
  }
  else
  {
    call_out( "force_me", 1, "say Yes!  More!  I need more..." );
    call_out( "force_me", 2, "emote mumbles again and trails off, returning to his usual stupor." );
  }

  return 0;
}

int query_count() { return count; }

void set_count(int num) { count = num; }

void change_me()
{
  force_me("emote begins to tremble, the ice shards he has been given clanking together...");
  call_out( "blow_up", 2 );
}

void blow_up()
{
  force_me("emote explodes into a million frosty pieces, chilling you to the bone!");
  new("/wizards/nightshade/finalshard.c")->move(environment(this_object()));
  this_object()->remove();
}
