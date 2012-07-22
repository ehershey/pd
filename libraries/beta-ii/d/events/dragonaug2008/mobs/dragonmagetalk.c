
#include <std.h>
#include <dragonevent.h>
#include <id4.h>
#include <rooms.h>

inherit MONSTER;

mixed *speeches = ({
({
  "emote nods thoughtfully.",
  "say Yes, I have heard of things like this before.",
  "say There must be some sort of keys to unlock this spell.",
  "say Those accursed warlocks have even hidden their old "
    "hideouts from me somehow!",
  "emote thinks carefully.",
  "emote uncovers an old tome and begins to page through it.",
  "say Ah, this spell might prove useful.",
  "say Unfortunately, it requires \"a tree that has traveled the world\".",
  "say I am sure there is no such thing in our lands, for our trees "
    "are all quite immobile.",
  "say If you know of anything like this, please bring it to me.",
}),
({
  "",
  "say Ahhh, of course! This will do nicely.",
  "",
  "",
  "say Now I need only the object that was used to seal their caves.",
  "say With that, I can make you a way into the caves.",
  "say The ogres are foolish, but surely they tried to hide it at least.",
  "say Go forth and find it so that I can save my child!",
}),
({
  "",
  "say Excellent!",
  "say Now, stand back while I create something to help you make a way in.",
  "emote takes the dagger and %^RED%^stabs%^RESET%^ it into the wood.",
  "emote closes his eyes and begins to chant.",
  "emote spreads his wings as a %^BOLD%^%^WHITE%^glowing wand%^RESET%^ "
    "begins to form in front of him.",
  "",
  "say Take this and be careful, for the ogres probably still infest those caves.",
  "",
  "",
}),
({
  "emote looks over the black gem.",
  "emote mutters a spell.",
  "say This looks like it is one of the keys.",
  "say It seems to have lost most of its power, though.",
  "say Perhaps bringing it near the other keys would help.",
  "emote scratches his head with one claw.",
  "say It may need to be recharged some way, too.",
  "",
}),
});

int speechcounter = -1;
int speed = 1;
object pl;

void set_speech(int x) {
  if (x < -1 || x >= sizeof(speeches)) x = -1;
  DRAG_D->set_data("speechdragonelder", x);
}
void start_speech() { speechcounter = 0; }
void stop_speech() { speechcounter = -1; }
int query_speech() { return DRAG_D->query_data("speechdragonelder"); }

void drop_it(string str);

void create() {
  ::create();
  set_property("passive", 1);
  set_name("dragon mage");
  set_id( ({ "dragon", "mage", "dragon mage" }) );
  set_short("an ancient dragon mage");
  set_long(
    "This dragon is quite old. His scales are black, but faded."
    "He gazes around with eyes full of wisdom."
  );
  set_race("dragon");
  set_class("dragon");
  set_subclass("black");
  set_body_type("dragon");
  set_gender("male");
  set_level(66);
  set_spell_chance(80);
  set_spells( ({ "annihilate", "shadowfang", "void", "dragonfury" }) );
  set_heart_beat(5);
  speed = 5;
}

void heart_beat() {
  string *sentences;
  object ob, tp, maker, env, dr;
  int ok = 0;
  ::heart_beat();
  if (!this_object()) return;

  set_heart_beat(speed);
  env = environment();

  if (speechcounter > -1 && query_speech() > -1) {

    if (env && sizeof(filter(all_inventory(env), (: $1->is_player() :) )))
      ok = 1;

    sentences = speeches[query_speech()];

    switch (query_speech()+":"+speechcounter) {

      case "1:0":
        if (!(ob = present("tirun_driftwood", this_object()))) return;
        pl = ob->query_last_location();
        if (pl && pl->is_player() && DRAG_D->query_data("canfindportalpiece") != 0) {
          DRAG_D->set_data("canfindportalpiece", 0);
          DRAG_D->set_data("winnerfoundportalpiece", pl->query_name());
          ob->remove();
        }
      break;

      case "1:2":
        if (!ok) return;
        command("say Thank you, "+pl->query_cap_name()+".");
      break;

      case "1:3":
        command("emote mutters a spell.");
        if (pl) {
          pl->add_exp(350000);
          pl->set_stats("dexterity", pl->query_base_stats("dexterity")+2);
          pl->set_stats("intelligence", pl->query_base_stats("intelligence")+1);
          pl->set_stats("wisdom", pl->query_base_stats("wisdom")+1);
          message("magic", "%^BOLD%^%^BLUE%^"
            "A magical glow surrounds you.\n"
            "You feel different."
            "%^RESET%^", pl);
          message("magic", "%^BOLD%^%^BLUE%^"
            "A magical glow surrounds "+pl->query_cap_name()+".",
            environment(pl), pl);
        }
      break;

      // ---

      case "2:0":
        if (!(ob = present("ogre_ceremonial_dagger", this_object()))) return;
        pl = ob->query_last_location();
        if (DRAG_D->query_data("canfindogredagger") != 0) {
          DRAG_D->set_data("canfindogredagger", 0);
        }
        ob->remove();
      break;

      case "2:6":
        if (!ok) return;
        maker = new(DRAG_ITEMS+"portalmaker");
        maker->move(env);
      break;

      case "2:8":
        if (!ok) return;
        dr = present("guide_dragon", env);
        if (dr) {
          dr->force_me("say I'll go tell the elder!");
          dr->move(ROOM_CACHE);
          message("mout", "The little blue dragon leaves.", env);
        }
      break;

      case "2:9":
        dr = present("guide_dragon", find_object(ROOM_CACHE));
        if (dr) {
          dr->move(DRAG_ROOMS+"summit");
          message("min", "A little blue dragon arrives.", DRAG_ROOMS+"summit");
        }
      break;

      // ---

      case "3:7":
        if (!ok) return;
        if (!(ob = present("dragon_event_gem_black", this_object()))) return;
        pl = ob->query_last_location();
        if (!pl || environment(pl) != env) return;
        command("give dragon_event_gem_black to "+pl->query_name());
      break;
        

      default:
      if (!ok) return;
      command(sentences[speechcounter]);

    }

    // advance to next line of this speech
    speechcounter++;
    if (speechcounter >= sizeof(sentences)) {
      speechcounter = -1;
      // at end of speech, automatically stop talking but advance
      //   to the next speech in the list
      set_speech(query_speech()+1);
      if (query_speech() > sizeof(speeches))
        set_speech(-1);
    }
  }
}

void catch_tell(string str) {
  object tp, ob;
  string name, obname;
  if (!str) return;

  if (sscanf(str, "%s gives you %s.", name, obname) == 2) {
    switch (query_speech()) {
      case 1:
        ob = present("tirun_driftwood", this_object());
      break;
      case 2:
        ob = present("ogre_ceremonial_dagger", this_object());
      break;
      case 3:
        ob = present("dragon_event_gem_black", this_object());
      break;
    }
    if (ob && speechcounter == -1)
      start_speech();
    else
      call_out("drop_it", 0, obname);
  }
}

void drop_it(string str) {
  if (str) {
    command("drop "+str);
    command("drop "+remove_article(str));
  }
}

