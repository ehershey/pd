#include <std.h>
#include <tirun.h>

inherit ROOM;

int tombstone, code;

void create() {
    int callout;
    ::create();
    set_smell("default", "Thick dust makes breathing difficult.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "%^YELLOW%^An eerie glow fills the yard.%^RESET%^\n"
        "The enclosed yard of this mansion has a faint yellow glow covering it.  A small "
        "tombstone protrudes from the ground across the yard.  Stout shrubs create curving "
        "paths that form strange shapes.  A single willow tree droops lowly in the middle "
        "of the yard.  The ground is hidden by a thick mist that fills the yard like a dark "
        "liquid.");
    set_items(
        (["glow" : "The light seems to come from every direction...  It must come from a magical source.",
          "shrubs" : "The shrubs form a strange shape, but it cannot be discerned from close up.",
          "tree" : "The tip of each branch nearly touches the ground, the branches unable to hold up under the weight.",
          "mist" : "The mist swirls across the ground, hiding it from sight."]) );
    set_exits( ([ "out" : ROOMS"hhouse/3" ]) );
    tombstone = 1;
    code = random(10000);
    while(code < 1000)
      code = random(10000);
    callout = 7200;
//    call_out("add_note",callout);  // two to fourteen hours
    set_no_clean(1);
}

void add_note() {tombstone = 0;}

void init() {
  ::init();
  add_action("dig", "dig");

  add_action("look", "look");
}

int query_code() { return code; }

int look(string str) {
  int length;
  string message;
  if(!str)
    return 0;
  if(str != "tombstone")
    return 0;
  length = (23 - strlen(this_player()->query_cap_name())) / 2;
  message = this_player()->query_cap_name();
  while(length--)
    message = " "+message;
  write("          _________________\n"
"       .::='               '-.\n"
"      /:' ____    ___  ____   \\\n"
"     |::   |  \\    |    |  \\   :\n"
"     |::   |__/    |    |__/   |\n"
"     |::   | \\     |    |      |\n"
"     |::  _|_ \\_  _|_  _|_     |\n"
"     |::                       |\n"
"     |::       Here lies       |\n"
"     |::                       |\n"
"     |::"+arrange_string(message, 23)+"|\n"
"     |::                       |\n"
"     |::                       |\n"
"     |::                       |\n"
"     (\\O/)                     |\n"
"    (=(@)=)                    |\n"
"     (/U\\)                     |\n"
"     |:| ___      .... .. . .. :..\n"
"     |:|/__/..:.:::..::::...:::..::.....\n"
"     _'|/_..::.,:::.::::::::::::...:::..::....\n");
  write("You notice the dirt covering the grave is loose.");
  say(this_player()->query_cap_name()+" looks over the tombstone and becomes pale.");
  return 1;
}

void reset() {
  ::reset();
  if(random(2)) tombstone=0;
}

int dig(string str) {
  if(str && str != "grave")
    return notify_fail("You cannot dig through that.\n");

  if(tombstone)
    return notify_fail("You find nothing in the dirt.\n");

  write("You find a small note in the loose dirt.");

  new(ROOMS"hhouse/codenote")->move(this_player());
  tombstone=1;
  return 1;
}
