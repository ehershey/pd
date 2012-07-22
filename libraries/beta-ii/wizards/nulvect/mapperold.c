//Mapper daemon for room descriptions
//Written by Nightshade 7-10-01
//Updated by Nightshade 6-27-02
#include <std.h>
#include <daemons.h>
#include <ansi.h>
inherit DAEMON;
string nightshady(string str, int x);
string get_last_color(string str, string uncolor) {
  string colour, ret;
  int i, offset;
  if(strlen(uncolor) <= 1) return "";
  uncolor = nightshady(uncolor, strlen(uncolor));
  offset = 0;
  ret = "";
  if(!str) return "";
//  if(strsrch(str, "%^", -1) == -1)
//    return "";
  colour = str;
  i = strlen(uncolor);
  for(int x=0; x < i; x++) {
    while(uncolor[x] != colour[x+offset]) {
//      message("info", colour[x+offset..x+offset]+" = "+colour[x+offset]+"", find_player("nightshade"));
      ret += sprintf("%c",colour[x+offset]);
      offset++;
    }
    if(strlen(ret) > 0) {
      if(ret[sizeof(ret)-1] != 'm')
        ret += "m";
      if(ret[sizeof(ret)-2] == 'm')
        ret = ret[0..sizeof(ret)-2];
    }
  }
  return (string)ret;
}
string mapper(object who) {
    int tem, flg, i;
    object env, *livs, blank;
    string descript, shady, tempo, *all, *no_color, lastcolor;
    env = environment(who);
    flg = 0;
    blank = this_player();
    descript = wrap(env->query_long(0)+"\n", 61);
    all = explode(descript, "\n");
    tempo = sprintf("%-="+61+"s", TERMINAL_D->no_colours(env->query_long(0)) + "\n");
    no_color = explode(tempo, "\n");
    while(sizeof(all) < 6)
        all += ({""});
    while(sizeof(no_color) < 6)
        no_color += ({""});
    tempo = nightshady(all[0], strlen(no_color[0]));
    lastcolor = get_last_color(tempo, no_color[0]);
    tempo += "%^RESET%^%^GREEN%^|%^RESET%^ ";
    if (env->query_obvious_exit("northwest") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("northwest"))? load_object(env->query_obvious_exit("northwest")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg == 1)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_obvious_exit("north") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("north"))? load_object(env->query_obvious_exit("north")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_obvious_exit("northeast") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("northeast"))? load_object(env->query_obvious_exit("northeast")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^]\n";
        else
            tempo += "[ ]\n";
        flg = 0;
    }
    else
        tempo += "\n";
    shady = tempo;
    tempo = lastcolor+nightshady(all[1], strlen(no_color[1]));
    lastcolor = get_last_color(tempo, no_color[1]);
    tempo += "%^RESET%^%^GREEN%^|%^RESET%^    ";
    if (env->query_obvious_exit("northwest") != "/d/nopk/standard/void")
        tempo += "\\ ";
    else
        tempo += "  ";
    if (env->query_obvious_exit("north") != "/d/nopk/standard/void")
        tempo += "|";
    else
        tempo += " ";
    if (env->query_obvious_exit("up") != "/d/nopk/standard/void")
        tempo += "+";
    else
        tempo += " ";
    if (env->query_obvious_exit("northeast") != "/d/nopk/standard/void")
        tempo += "/\n";
    else
        tempo += "\n";
    shady += tempo;
    tempo = lastcolor+nightshady(all[2], strlen(no_color[2]));
    lastcolor = get_last_color(tempo, no_color[2]);
    tempo += "%^RESET%^%^GREEN%^|%^RESET%^ ";
    if (env->query_obvious_exit("west") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("west"))? load_object(env->query_obvious_exit("west")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^]-[%^RED%^X%^RESET%^]";
        else
            tempo += "[ ]-[%^RED%^X%^RESET%^]";
        flg = 0;
    }
    else
        tempo += "    [%^RED%^X%^RESET%^]";
    if (env->query_obvious_exit("east") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("east"))? load_object(env->query_obvious_exit("east")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg)
            tempo += "-[%^GREEN%^*%^RESET%^]\n";
        else
            tempo += "-[ ]\n";
        flg = 0;
    }
    else
        tempo += "\n";
    shady += tempo;
    tempo = lastcolor+nightshady(all[3], strlen(no_color[3]));
    lastcolor = get_last_color(tempo, no_color[3]);
    tempo += "%^RESET%^%^GREEN%^|%^RESET%^    ";
    if (env->query_obvious_exit("southwest") != "/d/nopk/standard/void")
        tempo += "/";
    else
        tempo += " ";
    if (env->query_obvious_exit("down") != "/d/nopk/standard/void")
        tempo += "-";
    else
        tempo += " ";
    if (env->query_obvious_exit("south") != "/d/nopk/standard/void")
        tempo += "| ";
    else
        tempo += "  ";
    if (env->query_obvious_exit("southeast") != "/d/nopk/standard/void")
        tempo += "\\\n";
    else
        tempo += "\n";
    shady += tempo;
    tempo = lastcolor+nightshady(all[4], strlen(no_color[4]));
    lastcolor = get_last_color(tempo, no_color[4]);
    tempo += "%^GREEN%^|%^RESET%^ ";
    if (env->query_obvious_exit("southwest") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("southwest"))? load_object(env->query_obvious_exit("southwest")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_obvious_exit("south") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("south"))? load_object(env->query_obvious_exit("south")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_obvious_exit("southeast") != "/d/nopk/standard/void") {
        livs = all_inventory(load_object(env->query_obvious_exit("southeast"))? load_object(env->query_obvious_exit("southeast")) : blank);
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]) && !livs[i]->query_invis())
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^]\n";
        else
            tempo += "[ ]\n";
        flg = 0;
    }
    else
        tempo += "\n";
    shady += tempo;
    tempo = "";
//    if(sizeof(all) > 6)
//        tempo = "%^%^"+lastcolor+"%^%^";
    tem = 5;
    while( tem < sizeof(all)) {
        tempo += all[tem];
        tempo += " ";
        tem++;
    }
    tempo = tempo[0..sizeof(tempo)-2];
    tempo = wrap(tempo, 80);
    tempo = lastcolor+tempo;
    shady += tempo;
    return shady;
}
string nightshady(string str, int x) {
    int num;
    if(!str || (str == ""))
        return "                         "
        "                                     ";
    num = 62 - x;
    while(num > 0) {
        str += " ";
        num--;
    }
    return str;
}
