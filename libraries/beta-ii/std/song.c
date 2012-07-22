// The object for all bard songs
// ::Inferno(Aug. 08 2000);
// 
// changed a bit and included dances
// 2006-08-16 Nulvect
#include <std.h>
inherit OBJECT;

static string type, *verses, name;
static object caster, target;
static int count, max, auto, needtarget, party;

int do_stop(string str);
void end_it();

void init() {
  ::init();
  add_action("do_stop", "stop");
}

void create() {
 ::create();
   set_name("song_dance_ob_id");
   set_short("");
   set_id(({"song_dance_ob_id"}));
   set_weight(0);
   set_value(0);
}

void notify_die(object killer) { this_object()->remove(); }

void set_song_name(string str) { name = str; }

string query_song_name() { return name; }

void set_dance_name(string str) { name = str; }

string query_dance_name() { return name; }

void set_auto(int i) { auto = i; }

int query_auto() { return auto; }

void set_type(string str) { type = str; }

string query_type() { return type; }

void set_target_required(int i) { needtarget = i; }

int query_target_required() { return needtarget; }

void set_verses(string *str) { verses = str; }

void set_caster(object ob) { caster = ob; }

object query_caster() { return caster; }

void set_target(object ob) { target = ob; }

object query_target() { return target; }

void set_max_rounds(int i) { max = i; }

int query_max_rounds() { return max; }

void set_party_hit(int i) { party=i; }

int query_party_hit() { return party; }

void heart_beat() {
  int s=sizeof(verses);
  if (!this_object() || !environment(this_object()) ||
      environment(this_object()) != caster) {
        this_object()->remove();
        return;
  }
  if (caster->query_paralyzed())
    return;
  if (s) {
    message("song", "%^CYAN%^You sing:%^RESET%^ "+
      verses[count], caster);
    message("song", "%^CYAN%^"+caster->query_cap_name()+" sings:%^RESET%^ "+
      verses[count], environment(caster), caster);
    if (count >= s-1) {
      end_it();
      return;
    }
  }
  else if (count >= max) {
    end_it();
    return;
  }
  count++;
  if (function_exists("performance",this_object()) != 0)
    this_object()->performance(count);
}

void start() {
  count = 0;
  heart_beat();
  set_heart_beat(1);
}

void end_it() {
  this_object()->set_heart_beat(0);
  if (function_exists("finish", this_object()) != 0)
    this_object()->finish();
  this_object()->remove();
}

int do_stop(string str) {
  object tp=this_player();
  if (!str || str == "" || tp != this_object()->query_caster()) return 0;
  if (tp->query_paralyzed()) return 0;
  if ((sizeof(verses) && str == "singing") || str == "dancing") {
    tp->set_disable();
    this_object()->set_heart_beat(0);
    message("song", "You stop "+str+".", tp);
    this_object()->remove();
    return 1;
  }
  return 0;
}

