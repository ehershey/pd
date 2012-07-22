// I wish I could do this more cleanly, but since
// they aren't all in separate dirs, I can't...
// written by Nulvect 2006-09-15

#include <std.h>
#include <dirs.h>

#define COL "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"
#define SONG_DIR "/cmds/song/"
#define DANCE_DIR "/cmds/dances/"

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <allspells>\n\n"
    "Displays all spells and abilities currently in the game.",
    this_player());
}

int cmd_allspells(string str) {
  object tp=this_player();
  string output="";
  mapping all = ([
    "spells" : ({}),
    "abils" : ({}),
    "songs" : ({}),
    "dances" : ({})
  ]);

  foreach (string file in get_dir(DIR_CLASS_CMDS+"/*.c")) {
    object c;
    string name;
    string tmp=DIR_CLASS_CMDS+"/"+file;
    sscanf(file, "_%s.c", name);
    c=load_object(tmp);
    if (function_exists("spell", c))
      all["spells"] += ({ name });
    if (function_exists("abil", c))
      all["abils"] += ({ name });
    c=0;
  }

  foreach (string file in get_dir(SONG_DIR+"*.c")) {
    object c;
    string name;
    string tmp=SONG_DIR+"/"+file;
    c=load_object(tmp);
    name = c->query_song_name();
    all["songs"] += ({ name });
    c=0;
  }

  foreach (string file in get_dir(DANCE_DIR+"*.c")) {
    object c;
    string name;
    string tmp=DANCE_DIR+"/"+file;
    c=load_object(tmp);
    name = c->query_dance_name();
    all["dances"] += ({ name });
    c=0;
  }

  output += COL+"spells ("+sizeof(all["spells"])+")\n"+RES;
  for (int i=0; i<sizeof(all["spells"]); i++) {
    output += arrange_string(all["spells"][i], 15);
    if (i%4 == 4-1)
      output += "\n";
  }

  output += COL+"\n\nabils ("+sizeof(all["abils"])+")\n"+RES;
  for (int i=0; i<sizeof(all["abils"]); i++) {
    output += arrange_string(all["abils"][i], 15);
    if (i%4 == 4-1)
      output += "\n";
  }

  output += COL+"\n\nsongs ("+sizeof(all["songs"])+")\n"+RES;
  for (int i=0; i<sizeof(all["songs"]); i++) {
    output += arrange_string(all["songs"][i], 35);
    if (i%2 == 2-1)
      output += "\n";
  }
  
  output += COL+"\n\ndances ("+sizeof(all["dances"])+")\n"+RES;
  for (int i=0; i<sizeof(all["dances"]); i++) {
    output += arrange_string(all["dances"][i], 35);
    if (i%2 == 2-1)
      output += "\n";
  }

  message("info", output, tp);

  return 1;
}

