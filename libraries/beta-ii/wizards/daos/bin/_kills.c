#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_kills(string who) {
    string *kills, tmp;
    object ob;
    int x, amt;

    if(!who)
        ob=this_player();
    else {
        if(!wizardp(this_player()))
            return notify_fail("You can only see your own kills.\n");
        if(!ob=find_player(who))
            return notify_fail("No such person!\n");
    }
    kills = ob->query_kills();
    message("info", "%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Kills %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+", this_player());
    if(!amt=sizeof(kills))
        return notify_fail("You havn't killed anything yet!\n");                    
    message("my_action", sprintf("You have killed %d creatures.",amt),
      this_player());
    message("info", "%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", this_player());
    for(x=0;x<amt;x++) {
        tmp = (string)PLAYER_D->query_monster(kills[x]);
        tmp = arrange_string(tmp, 27);
        x++;
        if(x == amt) {
            message("my_action", tmp, this_player());
            break;
        }
        tmp += (string)PLAYER_D->query_monster(kills[x]);
        tmp = arrange_string(tmp, 54);
        x++;
        if(x == amt) {
            message("my_action", tmp, this_player());
            break;
        }
        tmp += (string)PLAYER_D->query_monster(kills[x]);
        message("my_action", tmp, this_player());
    }
    message("info", "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=", this_player());

    return 1;
}

void help() {
    if(!wizardp(this_player())) {
        message("help", "Usage: <kills>\n\nLists all of your kills.",
          this_player());
    }
    message("help", "Usage: <kills [who]>\n\nLists your kills "
      "or kills for [who].", this_player());
    return ;
}
