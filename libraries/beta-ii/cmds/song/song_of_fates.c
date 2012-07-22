#include <std.h>
#include <effect_cl.h>

inherit SONG;

void create() {
  ::create();
  set_verses(({
    "Mist and twilight, cloud and shade,",
    "Soon perhaps, all may fade!",
    "Lying in pools deep with blood so red,",
    "That the 'morrow's light should find me dead!"
   }));
  set_type("beneficial");
  set_target_required(1);
  set_song_name("song of fates");
}

int song() {
  object o=this_player();
  if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 60)
    return 1;
  return 0;
}
void help() {
  message("help",
   "Syntax: <sing song of fates [to whom]>\n\n"
   "A bard song which serves to inspire the intended listener "
   "and greatly increases his endurance.",
   this_player() );
}
void finish() {
  object ob, tp;
  int amt, time;
  class Effect eff;
  tp = this_object()->query_caster();
  ob = this_object()->query_target();
  amt = tp->query_skill("euphony")/5;
  if (!ob || !present(ob, environment(tp)) ||
   ob->query_stat_bonus("constitution")) {
    message("info", "Nothing happens.", tp);
    return;
  }
  time = tp->query_skill("euphony");
  ob->add_stat_bonus("constitution", amt, time);
  tell_room(environment(tp), ob->query_cap_name()+" steps forward unto "
   +ob->query_possessive()+" fate.", ({ ob }));
  message("song", "You step forward to your fate.", ob);
  eff = new(class Effect);
  eff->name = "song of fates";
  eff->desc = "Your endurance is greatly increased.";
  eff->caster = tp;
  eff->target = ob;
  eff->castername = tp->query_name();
  eff->endtime = time()+time;
  eff->endmessages = ({
    "The fateful song fades away.",
    ob->query_cap_name()+"'s fateful inspiration fades."
  });
  ob->add_effect(eff);
  /*
  ob->set_max_hp(ob->query_max_hp()+tp->query_skill("euphony"));
  "/cmds/song/obj/fixhp.c"->do_fix(ob, tp->query_skill("euphony"));
  */
}
