// ��� Seeker - [pd.iuis.org] port 5000  Sunday November 19 2000 -- 09:45
// Especially made for Forgotten Paradigm

#include <std.h>

inherit DAEMON;

int cmd_age(string arg)
{
    int years, weeks, days, hours, min, sec;
    string str;
    object ob;


    if (arg && wizardp(this_player()))
    {
	if (ob = find_player(arg))
	    sec = ob->query_age();
	else return notify_fail("No such player on.\n");
    } else
	sec = this_player()->query_age();

    min = sec / 60;
    sec -= min * 60;
    hours = min / 60;
    min -= hours * 60;
    days = hours / 24;
    hours -= days * 24;
    weeks = days / 7;
    days -= weeks * 7;
    years = weeks / 52;
    weeks -= years * 52;
    str = "";
    if (years)
	str += years + (years > 1 ? " years" : " year")+(weeks ? ", ":" ");
    if (weeks)
	str += weeks + (weeks > 1 ? " weeks" : " week")+(days ? ", ":" ");
    if (days)
	str += days  + (days > 1 ? " days" : " day")+(hours ? ", ":" ");
    if (hours)
	str += hours + (hours > 1 ? " hours" : " hour")+(min ? ", ":" ");
    if (min)
	str += min   + ( min > 1 ? " minutes" : " minute")+(sec ? ", ":" ");
    if (sec)
	str += sec   + (sec > 1 ? " seconds " : " second ");
    if (arg && wizardp(this_player()))
	write(capitalize(arg)+" is "+str+"old.");
    else
	write("You are "+str+"old.");
    return 1;
}
int help()
{
  write( @EndText
Syntax: age
Effect: gives total real time spent online.
See also: mudtime, nextreboot
EndText
  );
  return 1;
}
