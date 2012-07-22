//  Guild System 4
//  Created by Whit
//  Added some optional arguments

#include <daemons.h>
#include <guild.h>
#define SPACE "\n"
#define BORDER "%^BOLD%^%^BLUE%^-----------------------------------------------------------------------------\n"
string *squire, *member, *council, *leader;
mapping positions;

varargs int all_by_pos(string str) {
    string g,g2;
    g=GUILD_D->query_guild(this_player()->query_name());
    if(str) g=str;
    g2=GUILD_D->query_short_name(g);
    if(!file_exists(SAVE+g+".o")) return notify_fail("Unable to find guild ob.\n");
    restore_object(SAVE+g);
    write(center("-=| "+g2+" |=-")+"\n\n");
    write("%^BOLD%^%^BLUE%^"+center(GUILD_D->query_position_name(g,"leader")+"s: ")+
      "%^RESET%^");
    write(BORDER);
    if(!sizeof(leader) || leader==({})) write("%^BOLD%^%^RED%^Error%^RESET%^: "
	  "Report this on your guild board.");
    else
	write(format_page(leader), 2);

    write(SPACE);

    write("%^BOLD%^%^RED%^"+center(GUILD_D->query_position_name(g,"council")+"s: ")+
      "%^RESET%^");
    write(BORDER);
    if(!sizeof(council) || council==({})) write("No "+
	  GUILD_D->query_position_name(g,"council")+"s.");
    else
	write(format_page(council), 2);
    write(SPACE);
    write("%^BOLD%^"+center(GUILD_D->query_position_name(g,"member")+"s: ")+
      "%^RESET%^");
    write(BORDER);
    if(!sizeof(member) || member==({})) write("No "+
	  GUILD_D->query_position_name(g,"member")+"s.");
    else
	write(format_page(member), 2);
    write(SPACE);
    write("%^BOLD%^%^GREEN%^"+center(GUILD_D->query_position_name(g,"squire")+"s: ")+
      "%^RESET%^");
    write(BORDER);
    if(!sizeof(squire) || squire==({})) write("No "+
	  GUILD_D->query_position_name(g,"squire")+"s.");
    else
	write(format_page(squire), 2);
    write(SPACE);
    return 1;
}

int all_by_online() {
    string g,g2,*all, *off,*on, out;
    object user;
    int i;
    out = "";
   g=GUILD_D->query_guild(this_player()->query_name());
    restore_object(SAVE+g);
    all=leader;
    all += council;
    all += member;
    all += squire;
    off=on=({});
    g=this_player()->query_guild();
    g2=GUILD_D->query_short_name(g);
    write(center("-=| "+g2+" |=-")+"\n\n");
    write("%^BOLD%^%^GREEN%^"+center("Online: ")+"\n"+BORDER);
    i=sizeof(all);
    while(i--) {
	if(user=find_player(all[i])) if(!interactive(user)) off += ({ all[i] });
	    else on += ({ all[i] });
	else off += ({ all[i] });
    }
    if(!sizeof(on) || on==({})) { write("No online players.\n"); i=0;}else
	i=sizeof(on);
    while(i--)  if(i==0) out += on[i]+""; else out += on[i]+", ";
    write(out);
    write("%^BOLD%^%^BLACK%^"+center("Offline: ")+"\n"+BORDER);
    out="";
    if(!sizeof(off) || off==({})) write("No offline players.\n"); else
	i=sizeof(off);
    while(i--)  if(i!=0) out += off[i]+", "; else out += off[i]+"";
    write(out);
    return 1;
}

int cmd_members(string str) {
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
	notify_fail(GUILD_D->query_lock_reason());
    if(!this_player()->query_guild() && !wizardp(this_player())) return 0;
    if(!str) return all_by_pos();
    if(str=="-o") return all_by_online();
    if(str != "-o" && wizardp(this_player())) return all_by_pos(str);
    return all_by_pos();
}

void help() {
    write("Syntax: <members [arg]>\n");
    write("Members used without an argument will display "
      "the current members and there ranks.  If [arg] is -o it "
      "will return a list of online/offline members.\n");
}

