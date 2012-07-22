//  Help System
//  Revamp by Whit

#define MAIN       "/doc/help/"
#define DPATHS     ({ MAIN+"general/"})
#define SUBS	   "/doc/help/classes/subclasses/"
#define WIZ_DIR    (MAIN+"creator/")
#define HM_DIR    (MAIN+"hm/")
#define ELITE_DIR    (MAIN+"elite/")
#define LEGEND_DIR    (MAIN+"legend/")
#define ARCH_DIR    (MAIN+"arch/")
#define SONG_DIR "/cmds/song/"
#define DANCE_DIR "/cmds/dances/"
#define SPACE       "     "
#define DIR_COLOR   "%^BOLD%^%^RED%^"
#define FILE_COLOR  "%^BOLD%^%^CYAN%^"
#include <daemons.h>
string *get_paths(object o);
int fail(string s);
mapping map;

varargs void write_banner(string t, string c) {
    string bor="-----------------------------------------------";
    int i;
    if(!t) t="Unknown";
    if(!c) c="Other";
    t = replace_string(t, "_", " ");
    message("", "\nPrimal Darkness Help System Version 2", this_player());
    message("", "%^BOLD%^%^CYAN%^Topic%^RESET%^%^BOLD%^:%^RESET%^ "+arrange_string(t, 30)
      +"%^BOLD%^%^CYAN%^Category%^RESET%^%^BOLD%^:%^RESET%^ "+c, this_player());
    i=strlen(c);
    while(i--) bor += "-";
    message("", bor+"\n", this_player());
}

string get_category(string d);
int do_menu_help();

int cmd_myhelp(string s) {
    string *paths, file, cat;
    int i;
    paths=get_paths(this_player());
    if(!paths || !sizeof(paths)) return fail("Error in help system.  No paths.\n");
    if(s && s != "") {
        if(s == "feelings") {
            this_player()->more( SOUL_D->query_feelings() );
            return;
        }
        if(s == "help") return this_player()->force_me("help topic");
        i=sizeof(get_dir(MAIN));
        while(i--) 
                if(file_exists(MAIN+get_dir(MAIN)[i]+"/"+s)) {
                file=MAIN+get_dir(MAIN)[i]+"/"+s;
                cat=MAIN+get_dir(MAIN)[i];
            }
        if(!file) {
            if(!file=CMD_D->find_cmd(s, this_player()->query_search_path())) {
            if (file_size(SONG_DIR+replace_string(s, " ", "_")+".c") > -1) {
              file = SONG_DIR+replace_string(s, " ", "_");
              cat = file[0..sizeof(file)-sizeof(s)-2]+"";
            }
            else if (file_size(DANCE_DIR+replace_string(s, " ", "_")+".c") > -1) {
              file = DANCE_DIR+replace_string(s, " ", "_");
              cat = file[0..sizeof(file)-sizeof(s)-2]+"";
            }
            else
                return fail("There is no help available for that topic.\n");
            }
            if (!sizeof(cat))
            cat = file[0..sizeof(file)-sizeof(s)-3]+"";
            if(!find_object(file)) call_other(file, "???");
            if(!function_exists("help", find_object(file)) && !file->hide_help()) 
                return fail("That command exists but is without a help file.  Please bug this.\n"); else
            if(!function_exists("help", find_object(file)))
            return fail("There is no help available for that topic.\n");
message("help", "cat: "+cat+", file: "+file, this_player());
            write_banner(s, get_category(cat));
            file->help();
            return 1;
        }
        write_banner(s, get_category(cat));
        this_player()->more(file);
        return 1;
    }
    if(!map) map=([]);
    map[this_player()]="/doc/help";
    do_menu_help();
    return 1;
}

string *get_paths(object o) {
    string *out=DPATHS;

    if(o->query_level() > 0) out += ({ SUBS });
    if(high_mortalp(o)) out += ({ HM_DIR });
    if(o->query_level() > 49) out += ({ ELITE_DIR });
    if(o->query_level() > 99) out += ({ LEGEND_DIR });
    if(wizardp(o)) out += ({ WIZ_DIR });
    if(archp(o)) out += ({ ARCH_DIR });
    return out;
}

varargs string get_category(string d, string type) {
    string a,b,c,e;
    if(type == "command" && sscanf(d, "/%s/%s/%s", a,b,c)==3) {
        switch(c) {
        case "mortal": return "Mortal Command"; break;
        case "adm": return "Administrator Command"; break;
        case "ambassador": return "Ambassador Command"; break;
        case "creator": return "Creator Command"; break;
        case "gmaster": return "Guild Master Command"; break;
        case "guild": return "Guild Command"; break;
        case "hm": return "High Mortal Command"; break;
        case "skills": return "Ability"; break;
        case "dances": return "Dance"; break;
        case "song": return "Songs"; break;
        case "system": return "System Command"; break;
        case "undead": return "Undead Command"; break;
        default: return "Other"; break;
        }
    }
    if(d[0..5] == "/cmds/") {
      switch(d[6..]) {
        case "adm": return "Administrative Command"; break;
        case "system": return "System Command"; break;
        case "ambassador": return "Ambassador Command"; break;
        case "creator": return "Creator Command"; break;
        case "guild": return "Guild Command"; break;
        case "hm": return "High Mortal Command"; break;
        case "mortal": return "Mortal Command"; break;
        case "skills": return "Ability/Spell Command"; break;
        case "song": return "Songs"; break;
        case "dances": return "Dances"; break;

        default: return "Other Command"; break;
      }
    }
    if(d=="/doc/help" || d=="/doc/help/") return "Main";
    sscanf(d, "/%s/%s/%s", a,b,c);
    switch(c) {
      case "hm": return "High Mortal"; break;
      case "classes": return "Class Help"; break;
      case "subclass": return "Subclass Help"; break;
      case "commands": return "Command Help"; break;
      case "creator": return "Creator Help"; break;
      case "general": return "General Help"; break;
      case "guild": return "Guild Help"; break;
      case "race": return "Racial Help"; break;
      case "skills": return "Skills Help"; break;
        case "song": return "Song Help"; break;
        case "dances": return "Dance Help"; break;
      case "rules": return "Game Rules"; break;
      default: return "Other"; break;
    }
    return "";
}

int fail(string s) {
    message("", s, this_player());
    return 1;
}

int write_menu(string d) {
    int i, x;
    string *l, cur, *dir=({}), *f=({}), out=""+SPACE;

    i=sizeof(l=get_dir(d+"/"));
    if(map[this_player()]+"/" == MAIN)
    out = "You are currently in the category: "+
      get_category(map[this_player()])+"\n\n"+SPACE;
    if(!i) out += "No listings for this category.\n";
    while(i--) {
        if(file_size(d+"/"+l[i]) ==-2) dir += ({ l[i] });
        if(file_size(d+"/"+l[i]) >=0) f += ({ l[i] });
    }
    i=sizeof(dir);
    while(i--) {
        if(x==4) { x=0; out += "\n"+SPACE; } 
        out += DIR_COLOR+"*%^RESET%^"+arrange_string(""+dir[i], 15)+"";
        x++;
    }
    x=0;
    i=sizeof(f);
    if(sizeof(dir)) out += "\n\n"+SPACE;
    while(i--) {
        if(x==4) { x=0; out += "\n"+SPACE; } 
        out += FILE_COLOR+"%^RESET%^"+arrange_string(""+f[i], 17)+"";
        x++;
    }
    write(out+"\n");
    write("Categories are signified by the (*).  \nTo switch categories, type the category with the (*).");
    write("To choose a topic, type the topics name.\n"
          "To show this page again, type <~l>\n"
          "To return to an earlier category, type <~b>\n"
          "To quit help, type <~q>\n");
    write("Selection: ");
    return 0;
}

int do_menu_help() {
    if(!write_menu(map[this_player()]))
        input_to("accept_cmd");
    return 1;
}

void continue_help() {
   write("Type <~l> to view a list of topics.");
   input_to("accept_cmd");
   return;
}

int accept_cmd(string s) {
    string *a;
    if(!s || s=="") {
        fail("Invalid selection, Selection: ");
        input_to("accept_cmd");
        return 1;
    }
    if(s == "q" || s == "quit") s = "~q";
    if(s[0..0]=="~") {
        switch(s[1..]) {
        case "L":
        case "l":
            write_menu(map[this_player()]);
            input_to("accept_cmd");
            break;
        case "q":
        case "Q":
            return fail("Exiting help.\n"); break;
        default: fail("Invalid selection, choice: "); input_to("accept_cmd"); break;
        case "b":
        case "B":
            if(map[this_player()]+"/"==MAIN) {
                fail("You are in the biggest heirarchy of help.  Selection: ");
                input_to("accept_cmd");
                return 1;
            }
            a=explode(map[this_player()], "/"); a[sizeof(a)-1]=0; 
            map[this_player()]="/"+implode(a, "/");
            write("You are now in category: "+get_category(map[this_player()]));
         input_to("accept_cmd");
            break;
        }
        return 1;
    }
    if(s[0..0]=="*") {
        if(file_size(map[this_player()]+"/"+s[1..]) != -2) {
            fail("Category does not exist.  Selection: ");
            input_to("accept_cmd");
            return 1;
        }
        write("You are now in category: "+s[1..]);
        write_menu(map[this_player()]+"/"+s[1..]);
        map[this_player()]=map[this_player()]+"/"+s[1..];
        input_to("accept_cmd");
        return 1;
    }
    if(!file_exists(map[this_player()]+"/"+s)) {
        fail("Topic does not exist, Selection: ");
        input_to("accept_cmd");
        return 1;
    }
    this_player()->more(map[this_player()]+"/"+s, "help", (: continue_help :));
    return 1;
}
