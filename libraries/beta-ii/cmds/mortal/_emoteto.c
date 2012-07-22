// Emote across the mud
// By Inferno 070300

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_emoteto(string str) {
    string text;
    object ob;

    if(!str || sscanf(str,"%s %s",str,text) != 2 || !(ob=find_player(str)))
        return notify_fail(str ? "No such player.\n" : "Emoteto whom?\n");
    if( ob->query_ignoring(this_player()->query_name()) )
        return notify_fail(ob->query_cap_name() + " is ignoring you.\n");
    message("emoteto", "-*- "+this_player()->query_cap_name()+" "+text, ob);
    message("emoteto","You emote to "+capitalize(str)+": "+
         this_player()->query_cap_name()+" "+text,this_player());
    LAST_D->add_tell(this_player()->query_name(), "You emote to "+
         capitalize(str)+": "+this_player()->query_cap_name()+" "+text);
    LAST_D->add_tell(ob->query_name(), "-*- "+
         this_player()->query_cap_name()+" "+text);
    return 1;
}

void help() {
    message("help",
      "Syntax: <emoteto [player] [message]>\n"
      "Just like an emote, only over a long distance.",
      this_player()
    );
}

