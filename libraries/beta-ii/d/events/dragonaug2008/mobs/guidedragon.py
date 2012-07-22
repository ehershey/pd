
#include <std.h>
#include <dragonevent.h>
#include <rooms.h>
#include <locations.h>

inherit MONSTER;

// responses[0] has highest priority, first match is used
mixed *responses = ({
({
  "follow",
  "do_follow()",
  ({ "canleadguidedragon", }),
}),
}); // end of responses

mixed *speeches = ({
({
  "",
  "",
  "",
  "say Hello my friends!",
  "say I was sent by the elder on an urgent errand...",
  "say You see, he intended to invite you, the mortals who helped save us, "
    "into the Dragonlands at long last.",
  "say Unfortunately, we have been harassed endlessly by the ogres who infest "
    "the caves below our lands.",
  "say With some terrible spell, one of their warlocks captured the son of our "
    "most powerful mage during the latest incursion.",
  "say The ogres make sure there is no entrance to their caves large enough for "
    "dragons to get through, so our warriors cannot follow them."
  "say As if that weren't enough, they seem to have put up a magical barrier "
    "that keeps us from locating them or my friend!",
  "say We would greatly appreciate your help!",
  "say Please, our lands are far to the east, follow me and speak with our elder!",
  "",
  "",
  "say Come this way, our elder is on the summit.",
  "",
  "",
  "",
}),
({
  "emote grins.",
  "emote jumps into the water and starts swimming around to the south!",
  "",
}),
({
  "say What is this?",
  "look platform",
  "say What powerful magic!",
  "say There must be some way to counter this spell. Let's look around.",
  "",
}),
({
  "look pillar",
  "say This must be part of the ogres' spell!",
  "say I will go and tell our elder of this right away!",
  "",
  "",
  "",
}),
}); // end of speeches

int whichspeech = 0;
int speechcounter = -1;
string *queue = ({});

int dont_die(object);

void set_speech(int x) {
  if (x < -1 || x >= sizeof(speeches)) x = -1;
  whichspeech = x;
}
void start_speech() { speechcounter = 0; }
void stop_speech() { speechcounter = -1; }
int query_speech() { return whichspeech; }

void create() {
  ::create();
  set_name("blue dragon");
  set_id( ({ "guide_dragon", "dragon", "blue dragon", "little blue dragon" }) );
  set_short("a little blue dragon");
  set_long(
    "This adolescent blue dragon is truly massive. She is shorter than "
    "a grown man, but twice as wide and four times the weight. She flutters "
    "her tiny wings every now and then."
  );
  set_gender("female");
  set_race("dragon");
  set_body_type("dragon");
  set_class("dragon");
  set_subclass("blue");
  set_level(28);
  set_skill("faith", 28*5);
  set_skill("conjuring", 28*3);
  set_max_hp(query_max_hp()*2);
  set_hp(query_max_hp());
  set_spell_chance(75);
  set_spells( ({
    "cure me", "shield me", "crystallize me", "wrap 50", "cure me", "spire",
  }) );
  set_says(15, ({
    "Help!",
    "Please protect me!",
  }), 1);
  set_emotes(15, ({
    "The little dragon looks scared.",
    "The little dragon tries to get away.",
  }), 1);
  set_emotes(1, ({
    "The little dragon flutters her wings.",
  }), 0);
  set_wimpy(40);
  set_die( (: dont_die :) );
}

int dont_die(object killer) {
  message("magic", "The little blue dragon mutters a spell of healing.",
    environment() );
  add_hp(600+random(100));
  return 0;
}

int is_invincible() {
  if (this_player() && this_player()->is_player())
    return 1;
  return 0;
}

void heart_beat() {
  object *pl;
  string *sentences;
  object env, fol, dr;
  int ok = 0;
  int test;
  ::heart_beat();
  if (!this_object()) return;

  env = environment();
  test = DRAG_D->query_data("testing");

  if (env && fol = query_following()) {
    // query_speech returns the next speech to be run!
    switch (query_speech()) {
      case 2:
        if (file_name(env) == DRAG_ROOMS+"ogre120") {
          DRAG_D->set_data("canleadguidedragon", 0);
          set_heart_beat(3);
          start_speech();
        }
      break;

      case 3:
        if (file_name(env) == DRAG_ROOMS+"ogre75") {
          DRAG_D->set_data("canleadguidedragon", 0);
          set_heart_beat(3);
          start_speech();
        }
      break;
    }
    if (fol->is_linkdead())
      set_following(0);
  }

  // do the current speech if set and started
  if (speechcounter > -1 && whichspeech > -1) {

    if (env && sizeof(filter(all_inventory(env), (: $1->is_player() :) )))
      ok = 1;

    sentences = speeches[whichspeech];

    switch (whichspeech+":"+speechcounter) {

      case "0:0":
        pl = filter(users(), (:
          (environment($1) && !environment($1)->query_property("indoors")) :)
        );
        if (!sizeof(pl)) return;
        message("info", "%^BOLD%^%^WHITE%^"
          "A dragon can be seen flying towards Tirun from the east."
          "%^RESET%^", test ? DRAG_D : pl);
        // slow it down for a bit
        set_heart_beat(6);
      break;

      case "0:1":
        pl = filter(users(), (:
          (environment($1) && !environment($1)->query_property("indoors")) :)
        );
        if (!sizeof(pl)) return;
        message("info", "%^BOLD%^%^WHITE%^"
          "The dragon circles in the skies over Tirun."
          "%^RESET%^", test ? DRAG_D : pl);
      break;

      case "0:2":
        if (!ok) return;
        if (!test) move(SQUARE_LOC);
        message("min", "A little blue dragon flies down from above and lands.",
          test ? DRAG_D : SQUARE_LOC);
        set_heart_beat(2);
      break;

      case "0:12":
        if (!ok) return;
        move(ROOM_CACHE);
        // env is already set to the room he was in earlier
        message("mout", "The little blue dragon leaps into the air "
                        "and flies away east!", env);
        set_heart_beat(6);
      break;

      case "0:13":
        move(DRAG_ROOMS+"beach");
        message("min", "A little blue dragon flies down from above and lands.",
          DRAG_ROOMS+"beach");
        set_heart_beat(4);
      break;
        
      case "0:15":
        if (!ok) return;
        move(ROOM_CACHE);
        message("mout", "The little blue dragon leaves.", env);
      break;

      case "0:16":
        move(DRAG_ROOMS+"summit");
        message("min", "A little blue dragon enters.", env);
      break;

      case "0:17":
        if (!ok) return;
        dr = present("dragon elder", env);
        if (dr) {
          dr->set_speech(0);
          dr->start_speech();
        }
        set_heart_beat(2);
      break;

      // ---

      case "1:2":
        if (!ok) return;
        command("emote jumps into the water and starts swimming "
                "around to the south.");
        move(DRAG_ROOMS+"ogrebeach");
        message("min", "A little blue dragon swims in and climbs "
                       "onto the small beach.", DRAG_ROOMS+"ogrebeach" );
        DRAG_D->set_data("canleadguidedragon", 1);
        set_heart_beat(1);
      break;

      // ---

      case "2:4":
        set_heart_beat(1);
        DRAG_D->set_data("canleadguidedragon", 1);
      break;

      // ---

      case "3:3":
        if (!ok) return;
        move(ROOM_CACHE);
        message("mout", "The little blue dragon runs out.", env);
        set_heart_beat(6);
      break;

      case "3:4":
        dr = present("dragon elder", load_object(DRAG_ROOMS+"summit"));
        if (dr) {
          dr->set_speech(1);
          dr->start_speech();
        }
        set_heart_beat(1);
      break;

      case "3:5":
        move(DRAG_ROOMS+"");
        message("min", "A little blue dragon arrives.", env);
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
      whichspeech++;
      if (whichspeech > sizeof(speeches))
        whichspeech = -1;
    }
  }

  // if responses are queued up, do those, only if not in a speech
  else if (sizeof(queue)) {
    string resp = queue[0];
    if (resp[<2..<1] == "()")
      call_other(this_object(), resp[0..<3]);
    else
      command("say "+resp);
    queue = queue[1..<1];
    return;
  }

}

void receive_message(string msg_class, string str) {
  if (!str || !strlen(str)) return;
  if (!msg_class || !strlen(msg_class) || msg_class != "say") return;

  foreach (mixed *arr in responses) {
    string word = arr[0];
    string resp = arr[1];
    string *checks = arr[2];
    if (!checks) checks = ({});

    // this regexp should check if the word is there with
    //   any amount of whitespace around it
    // if not there, skip
    if (!regexp(str, "[^A-Za-z0-9]"+word+"[^A-Za-z0-9]")) continue;

    foreach (string check in checks)
      if (DRAG_D->query_data(check) == 0)
        continue;

    // should only get here if all checks are true
    // will be said one per heart beat
    queue += ({ resp });
    break;

  }

}

void do_follow() {
  object tp = this_player();
  object to = this_object();
  if (tp && tp != to && !query_following()) {
    tp->add_follower(to);
    message("info", "The little blue dragon follows you.", tp);
    message("info", "The little blue dragon follows "+tp->query_cap_name()+".",
      environment(), ({ tp, to }) );
  }
}

