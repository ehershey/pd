// last -- seeker
#include <daemons.h>
#include <std.h>
inherit DAEMON;
int cmd_last(string str)
{
    string line;
    string *chan;
    int i, b=0;
    if (!str || str=="") 
    {
	message("info", "Last what?", this_player());
	return 1;
    }
    if (str=="say")
    {
	line = LAST_D->get_say((string)this_player()->query_name());
	message("info", 
	  "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 says %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=\n"+
	  "%^RESET%^"+line+
	  "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 says %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=", this_player());
	return 1;
    }
    if (str=="partyline")
    {
	line = LAST_D->get_partyline((string)this_player()->query_name());
	message("info", 
	  "%^BLUE%^+=+=+=+=+=+=+%^BOLD%^( %^WHITE%^Last 25 PartyLine %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=\n"+
	  "%^RESET%^"+line+
	  "%^BLUE%^+=+=+=+=+=+=+%^BOLD%^( %^WHITE%^Last 25 PartyLine %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=", this_player());
	return 1;
    }
    if (str=="buddylist")
    {
	line = LAST_D->get_buddylist((string)this_player()->query_name());
	message("info",
	  "%^BLUE%^+=+=+=+=+=+=+%^BOLD%^ ( %^WHITE%^Last 25 BuddyList %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=++\n"+
	  "%^RESET%^"+line+
	  "%^BLUE%^+=+=+=+=+=+=+%^BOLD%^ ( %^WHITE%^Last 25 BuddyList %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=",
	  this_player());
	return 1;
    }
    if (str=="enemylist")
    {
	line = LAST_D->get_enemylist((string)this_player()->query_name());
	message("info",
	  "%^BLUE%^+=+=+=+=+=+=+%^BOLD%^ ( %^WHITE%^Last 25 EnemyList %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=++\n"+
	  "%^RESET%^"+line+
	  "%^BLUE%^+=+=+=+=+=+=+%^BOLD%^ ( %^WHITE%^Last 25 EnemyList %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=",
	  this_player());
	return 1;
    }
    if (str=="tell")
    {
	line = LAST_D->get_tell((string)this_player()->query_name());

	message("info", 
	  "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 tells %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=\n"+ "%^RESET%^"+line+
	  "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 tells %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=", this_player());
	return 1;
    }
    if (str=="honey")
    {
	line = LAST_D->get_honeyline((string)this_player()->query_name());

	message("info", 
	  "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 honeys %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=\n"+ "%^RESET%^"+line+
	  "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 honeys %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=", this_player());
	return 1;
    }
    chan = this_player()->query_channels();
    i = sizeof(chan);
    while(i--)
    {
	if (chan[i]==str) b = 1;
    }     
    if (!b) return notify_fail("Invalid line.\n");
    line = LAST_D->get_last(str);
    message("info", 
      "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 "+str+"s %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=\n"+
      "%^RESET%^"+line+
      "%^BLUE%^+=+=+=+=+=+=+=+=%^BOLD%^( %^WHITE%^Last 25 "+str+"s %^BLUE%^)%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=", this_player());

    return 1;
}
void help() {
    write("Syntax: <last [channel]>\n"
      "This command will display the last twenty-five lines of the "
      "channel requested.");
}
