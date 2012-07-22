//      /cmds/mortal/_suicide
//      -- seeker
//      crack for guilds  --  Whit
#include <std.h>
#include <security.h>
#include <bank.h>
#include <dirs.h>
#include <flags.h>
#include <daemons.h>
inherit DAEMON;
object ob;
string admins;
string *member, *council, *leader;
void guild_remove(string guild, string name, string capname);
void sure_to_suicide(string pa)
{
    // mixed er;
    string pass, str;
    object ob;
    if(((pass = (string)this_player()->query_password()) != oldcrypt(pa, pass))
      &&
      ((string)this_player()->query_password() != crypt(pa, pass)))
    {
	message("info", "Suicide failed.", this_player());
	return 0;
    }
    ob = this_player();
    str = (string)ob->query_name();
    if (!str) return;
    message("info", "You terminate your existance on Primal Darkness.",ob); 
    if(this_player()->query_guild()) guild_remove(this_player()->query_guild(),
	  this_player()->query_name(), this_player()->query_cap_name());
    seteuid(UID_USERSAVE);
    rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o",DIR_USERS+"/rid/"+str+".o");
    seteuid(geteuid());
    /*
    MSQL_D->msql_delete("mud", "player_t", (string)ob->query_name());
    */
    BANK_D->remove_all_bank_accounts((string)ob->query_name());
    ob->remove();
    if (ob) destruct(ob);
    return;
}
int cmd_suicide(string str) {
    object ob;
    ob = this_player();
    message("info", "Acck eek!! This removes your existance from "
      "Primal Darkness, are you sure you want that? If so, "
      "enter your password", this_player());
    message("no_wrap", "Password: ", this_player());
    input_to("sure_to_suicide", I_NOECHO | I_NOESC);
    return 1;
}
void guild_remove(string guild, string name, string capname) {
    restore_object("/d/guilds/save/"+guild);
    member -= ({ lower_case(name) });
    council -= ({ lower_case(name) });
    leader -= ({ lower_case(name) });
    save_object("/d/guilds/save/"+guild);
}
void help() {
    write( @EndText
Syntax: suicide
Effect: Removes your character from our reality.
EndText
    );
}
