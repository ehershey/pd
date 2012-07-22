
#include <std.h>
#include <daemons.h>
#include <bboard.h>
#include <dirs.h>

inherit DAEMON;

void finish_edit(mixed *args);
void finish_report(object tp, string title, string body);
void abort();
string query_filename(object tp);

void help() {
  message("help",
    "Syntax: <praise>\n"
    "        <praise [item]>\n"
    "        <praise [description]>\n"
    "        <praise [item] [description]>\n\n"
    "Allows you to give praise for things on the mud.\n"
    "If you don't provide a description you will be placed "
    "in a text editor so you can enter one."
    "\n\n"
    "See also: typo, bug, idea",
    this_player() );
}

int cmd_praise(string str) {
  object tp = this_player();
  object env = environment(tp);
  string name = tp->query_name();
  object item;
  string itemname, itemfile;
  string filename = query_filename(tp);
  string title, body;
  int ed;

  // entered just "praise"
  if (!str) {
    item = env;
    ed = 1;
  }
  // entered "praise sword"
  else if ( (item = present(str, tp)) || (item = present(str, env)) ) {
    ed = 1;
  }
  // entered "praise sword this thing is awesome!"
  else if (sscanf(str, "%s %s", itemname, body) == 2) {
    // if there's no item named "sword"...
    if (!( (item = present(itemname, tp)) || (item = present(itemname, env)) ))
      // then user meant "praise I love this mud!"
      body = str;
  }

  if (!item)
    item = env;
  else
    title = item->query_name();

  itemfile = base_name(item);
  body = itemfile + ":\n" + (body ? body : "");

  title = (title ? title + " in " : "") + creator_file(itemfile);
  title = title[0..24];

  if (ed) {
    rm(filename);
    tp->edit(filename, "finish_edit", this_object(), ({ tp, title, body, filename }));
  }
  else
    finish_report(tp, title, body);

  return 1;
}

void finish_edit(mixed *args) {
  object tp = args[0];
  string title = args[1];
  string body = args[2];
  string filename = args[3];
  
  body = body + wrap(replace_string(read_file(filename), "\n", " "), 77);
  rm(filename);
  finish_report(tp, title, body);
}

void finish_report(object tp, string title, string body) {
  BBOARD_D->post_web_message("praise_log", tp->query_name(), title, body);
  message("info", "Praise logged, thank you!", tp);
}

void abort() {
  if (this_player()) {
    message("info", "Praise log aborted.", this_player());
    rm(query_filename(this_player()));
  }
}

string query_filename(object tp) {
  return DIR_TMP + "/" + tp->query_name() + ".praise";
}

