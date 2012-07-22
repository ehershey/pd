//   /adm/obj/master.c
//      from the Nightmare Mudlib
//      the mudlib master object
//      created by Descartes of Borg 03 august 1993
//      based upon master objects going back to mudlib.n

//              Nightmare Mudlib Version 3.0 Release 0.9.18
//              created by the founding arches of Nightmare MudOS
//              Darkone, Descartes, Flamme, Forlock, Shadowwolf
//              See detailed credits in /adm/Nightmare

// This is the master object, the second object loaded after the
// simul_efun object.  Everything written with 'write()' at startup
// will be printed to stdout.  At startup, the following functions
// will be called in the following order:
// 1) create() 
// 2) flag() will be called once for every argument to the command flag -f
// 3) epilog()
// Finally, the game will enter multiuser mode and users can login.
// At this point preload() gets called once for each object to be
// preloaded.
//    *** Warnings ***
// Do not user any instructions in create() which will need to make
// calls externally to the master object.  For example, do not
// try seteuid(UID_ROOT) since the seteuid() efun has the driver call
// valid_seteuid() in the master object.  A master object will load fine
// and start the mud if it has such a call, but you will crash the
// mud if you try to reload it since it will not be able to find
// the master object (i.e no master exists until create() is done).

// load_privs modified for msdos by peter

#include <config.h>
#include <objects.h>
#include <rooms.h>
#include <security.h>
#include <dirs.h>
#include <databases.h>
#include <daemons.h>
/*#include <law.h>*/

#define READ 0
#define WRITE 1

static mapping access, groups, privs;
int is_crash=0;

int query_crash();
string creator_file(string str);
void preload(string str);
static void crash(string err);
void load_access();
void load_groups();
void load_privs();
nomask int check_access(string file, object ob, int ind);

int set_crash(int x) { is_crash = x; }
int query_crash() { return is_crash; }
void flag(string str) {
    string file, arg;
    int i, x;

    if(previous_object()) return;
    if(sscanf(str, "for %d", x) == 1) {
        for(i=0; i<x; i++) {}
        return;
    }
    if(sscanf(str, "call %s %s", file, arg)) {
        write("Got "+(string)call_other(file, arg)+" back.\n");
        return;
    }
    write("Master: unknown flag.\n");
}

string * do_get_dir2(string fspc) {
    int i;
    int j;
    int k;
    int notthis;
    string dir;                 // Dir to search
    string searchfor;           // Filespec to search for
    string sname;               // Name to search for
    string sext;                // Ext to search for
    string cname;               // Name being examined
    string cext;                // Extension being examined
    string * tmpdir;            // Result from get_dir
    string * resdir;            // Result to be returned

    fspc=lower_case(fspc);
    if (fspc[0..0]!="/") 
        fspc=this_player()->get_path()+"/"+fspc;
    i=strsrch(fspc,"/",-1);
    if (i==0)
        dir="";
    else
        dir=fspc[0..(i-1)];
    dir=dir+"/";
    if (i==(strlen(fspc)-1))
        searchfor="*.*";
    else
        searchfor=fspc[(i+1)..(strlen(fspc)-1)];
    tmpdir=efun::get_dir(dir);
    if (sizeof(tmpdir)==0) return ({ });        // Error somewhere

    k=strsrch(searchfor,".");
    if (k<0)
        {
    /*    searchfor=searchfor+".";*/
        k=strlen(searchfor)-1;
        }
    if (k==0) sname="";
    else sname=searchfor[0..(k-1)];
    if (k==(strlen(searchfor)-1)) sext="";
    else sext=searchfor[(k+1)..(strlen(searchfor))];

    resdir=({ });
    i=sizeof(tmpdir);
    while (i--) {
        k=strsrch(tmpdir[i],".");
        if (k<0)
            {
       /*     tmpdir[i]=tmpdir[i]+".";*/
            k=strlen(tmpdir[i])-1;
            }
        if (k==0) cname="";
        else cname=tmpdir[i][0..(k-1)];
        if (k==(strlen(tmpdir[i])-1)) cext="";
        else cext=tmpdir[i][(k+1)..(strlen(tmpdir[i]))];

        notthis=0;
        j=0;
        while (j<strlen(cname)) {
            if (j>=strlen(sname)) { notthis=1; break; }
            if (sname[j..j]=="?") continue;
            if (sname[j..j]=="*") break;
            if (sname[j]!=cname[j]) { notthis=1; break; }
            j++;
            }
        j=0;
        while (j<strlen(cext)) {
            if (j>=strlen(sext)) { notthis=1; break; }
            if (sext[j..j]=="?") continue;
            if (sext[j..j]=="*") break;
            if (sext[j]!=cext[j]) { notthis=1; break; }
            j=j+1;
            }
        if (notthis==0) resdir+=({ tmpdir[i] });
        }
        
    return (resdir);
}

string *epilog(int x) {

    call_out("socket_preload", 5); 
    return read_database(PRELOAD_DB);
}

void load_groups() {
    string *lines;
    string grp, str;
    int i, max;

    groups = ([]);
    if(!(max=sizeof(lines=explode(read_file(GROUPS_DB), "\n")))) {
        write("Error in reading groups database.\n");
        shutdown();
        return;
    }
    for(i=0; i<max; i++) {
        if(!lines[i] || lines[i] == "" || lines[i][0] == '#') continue;
        if(sscanf(lines[i], "(%s): %s", grp, str) != 2) {
            write("Error in reading groups database in line "+(i+1)+".\n");
            shutdown();
            return;
        }
        if(!sizeof(groups[grp] = explode(str, " ")))
          map_delete(groups, grp);
    }
}

void load_access() {
    string *lines, *borg;
    string str, dir, tmp;
    int i, j, maxi, maxj;

    access = ([]);
    if(!(maxi=sizeof(lines=explode(read_file(ACCESS_DB), "\n")))) {
        write("Error in reading access database.\n");
        shutdown();
        return;
    }
    for(i=0; i<maxi; i++) {
        if(!lines[i] || lines[i] == "" || lines[i][0] == '#') continue;
        if(sscanf(lines[i], "(%s): %s", dir,tmp) !=2) {
            write("Error in reading access database at line "+(i+1)+".\n");
            shutdown();
            return;
        }
        if(!(maxj=sizeof(borg=explode(tmp, " ")))) continue;
        access[dir] = ([]);
        for(j=0; j<maxj; j++) {
            if(sscanf(borg[j], "(%s)[%s]", tmp, str) != 2) {
                write("Error in reading access database at line "+(i+1)+".\n");
                shutdown();
                return;
            }
            access[dir][tmp] = ({ 0, 0 });
            switch(str) {
                case "r": access[dir][tmp][READ] = 1; break;
                case "w": access[dir][tmp][WRITE] = 1; break;
                case "wr": case "rw": access[dir][tmp] = ({ 1, 1 }); break;
                default: access[dir][tmp] = ({ 0, 0 });
            }
        }
    }
}

void load_privs() {
    string *lines;
    string obj, euid;
    int i, max;

// tmp1 and tmp2 added by Galgalon

    privs = ([]);
    if(!(max = sizeof(lines=explode(read_file(PRIVS_DB), "\n")))) {
        write("Error in reading privs database.\n");
        shutdown();
        return;
    }
    for(i=0; i<max; i++) {
        if(!lines[i] || lines[i] == "" || lines[i][0] == '#') continue;
        if(sscanf(lines[i], "(%s): %s", obj, euid) != 2) {
            write("Error in reading privs database at line "+(i+1)+".\n");
            shutdown();
            return;
        }

#if 0
        if(!sizeof(privs[obj] = explode(euid, " ")))
          map_delete(privs, obj);
        write("load_privs:"+obj);
        tmp1=explode(obj,"/");
        tmp2=explode(tmp1[sizeof(tmp1)-1],".");
        if (strlen(tmp2[0])>13) tmp2[0]=tmp2[0][0..12];
        if ((sizeof(tmp2)>1)&&(strlen(tmp2[1])>3)) tmp2[1]=tmp2[1][0..2];
        tmp1[sizeof(tmp1)-1]=implode(tmp2,".");
        obj="/"+implode(tmp1,"/");
        write(" "+obj+"\n");

#endif

        if(!sizeof(privs[obj] = explode(euid, " ")))
          map_delete(privs, obj);
    }
}

void preload(string str) {
    string err;
    int t;

    if(!file_exists(str+".c")) return;
    t = time();
    write("Preloading: "+str+"...");
    if(err=catch(call_other(str, "???")))
      write("\nGot error "+err+" when loading "+str+".\n");
    else {
        t = time() - t;
        write("("+(t/60)+"."+(t%60)+")\n");
    }
}

void socket_preload() {
    string *items;
    int i, max;

    max = sizeof(items=explode(read_file(PRELOAD_SOCKET_DB), "\n"));
    for(i=0; i<max; i++) {
        if(!items[i] || items[i] == "" || items[i][0] == '#') continue;
        catch(call_other(items[i], "???"));
    }
}

int valid_write(string file, object ob, string fun) {
    return check_access(file, ob, WRITE);
}

int valid_read(string file, object ob, string fun) {
    return check_access(file, ob, READ);
}

nomask int check_access(string file, object ob, int ind) {
    string *path, *grps;
    string euid, tmp, fn;
    int i, j;

    if((euid=geteuid(ob)) == UID_ROOT) return 1;
    if (!euid) return 0;
    if(sscanf(file, user_path(euid)+"%s", tmp) ==1) return 1;
    if(sscanf(euid, "%sobj", tmp) == 1 && sscanf(file,user_path(tmp)+"%s",tmp)
      ==1) return 1;
    if(!access) load_access();
    if(!groups) load_groups();
    if(!privs) load_privs();
    fn = base_name(ob);
    if(sscanf(file, REALMS_DIRS+"/%s", tmp) ||
      sscanf(file, DOMAINS_DIRS+"/%s", tmp))
        if(groups["ambassador"] && member_array(euid, groups["ambassador"])
          != -1) return 0;
    if(!(path = explode(file, "/"))) path = ({});
    i = sizeof(path);
    while((i--) != -1) {
        if(i== -1) file = "/";
        else file = "/"+implode(path[0..(i)], "/");
        if(access[file]) {
            if(access[file]["all"] && access[file]["all"][ind] == 1) return 1;
            else if(access[file][euid]) return access[file][euid][ind];
            else {
              j = sizeof(grps = keys(access[file]));
              while(j--) {
                if(groups[grps[j]] && member_array(euid, groups[grps[j]]) != -1
                 && access[file][grps[j]][ind] == 1) return 1;
              }
              return 0;
            }
        }
    }
    return 0;
}

object connect() {
    object ob;
    string err;

    if(err=catch(ob = clone_object(OB_LOGIN))) {
        write("It looks like someone is working on the user object.\n");
        write(err);
        destruct(this_object());
    }
    return ob;
}

mixed compile_object(string file) {
  mixed mix;

  mix = (mixed)VIRTUAL_D->compile_object(file);
  /* write("geteuid() = "+geteuid(previous_object()));
  if (!mix && geteuid(previous_object())!="System")
    {
     write("%^RED%^%^BOLD%^*Error: Could not find object.%^RESET%^");
     write("\nCommon error, you forgot to put quotes around the "
           "arguments that are strings and not objects for example,\n"
           "call me;set_class;\"mage\"  %^RED%^not%^RESET%^ call me;set_class;mage\n"
           "this will still work sometimes without quotes but sometimes "
           "you may run into problems. If you want to use an object as "
           "an argument then you dont put quotes around it.\n\n");
     return 0;

    } */
  if (!mix && geteuid(previous_object())=="System")
    {
     write("%^RED%^%^BOLD%^*Could not locate file: %^RESET%^"+file);
     return 0;
    }
    return mix;
}

static void crash(string err) {
    is_crash = 1;
    log_file("crashes", mud_name()+" crashed "+ctime(time())+" with error "+
      err+".\n");
    shout("\n%^RED%^%^BOLD%^Pacix tells you: %^RESET%^I think "+mud_name()+" is crashing!\n");
    shout("Pacix forced you to: quit\n");
    users()->force_me("save");
    users()->force_me("quit");
}

int valid_shutdown(string euid) {
    
    log_file("shutdowns", mud_name()+" was shut down by "+
      (previous_object() ? (euid=geteuid(previous_object())) : euid)+" "+
      ctime(time())+"\n");
    if(euid != UID_ROOT && euid != UID_SHUTDOWN) return 0;
    return 1;
}

int valid_seteuid(object ob, string id) {
    string fn, uid;
    if (!ob || !id || id=="") return 0; 
    if((uid = getuid(ob)) == id) return 1;
    if(uid == UID_ROOT) return 1;
    if(file_name(ob) == OB_SIMUL_EFUN) return 1;
    if(uid == UID_SYSTEM && id != UID_ROOT && id != UID_BACKBONE)
      return 1;
    
    if(!privs) load_privs();
    return (privs[fn=base_name(ob)] && (member_array(id, privs[fn]) != -1));
}

int valid_shadow(object ob) { return 0; }

int valid_snoop(object snooper, object snoopee) {
    if(!snoopee && snooper) return 1;
    if(archp(snooper) && !archp(snoopee)) return 1;
    if(archp(snooper) && member_group(getuid(snoopee), "assist")) return 1;

     if(snoopee->query_snoop()) {
        tell_object(snoopee, "You are now being snooped by "+
          (string)snooper->query_cap_name()+".\n");
        return 1;
    } 
    return 0;
}

int valid_exec(string nom) {
    if(nom[0] != '/') nom = "/"+nom;
    if(nom == OB_LOGIN+".c") return 1;
    return 0;
}

int valid_hide(object who) {
    if(!objectp(who)) return 0;
    return member_group(geteuid(who), "superuser");
}

int valid_override(string file, string nom) {
    if(file == "/adm/simul_efun/overrides" || file == OB_SIMUL_EFUN) return 1;
    if(function_exists(nom, find_object(OB_SIMUL_EFUN))) return 0;
    return 1;
}

int valid_socket(object caller, string func, mixed *info) { 
if (func == "external")
  if (file_name(caller)!="/adm/daemon/fprot_d") return 0; else return 1;
return 1; 
}

string valid_database(object o,  string action, mixed *info) {
   if(previous_object() != find_object(MSQL_D)) return 0;
   return "pdleet123wooyeh";
}

int load_player_from_file(string nom, object ob) {
    int x;

    if(geteuid(previous_object()) != UID_ROOT) return 0;
    export_uid(ob);
    x = (int)ob->restore_player(nom);
    seteuid(nom);
    export_uid(ob);
    seteuid(UID_ROOT);
    return x;
}

void save_player_to_file(object ob) {
    string nom;

    if(base_name(previous_object()) != OB_USER) return;
    if(!(nom = (string)ob->query_name())) return;
    seteuid(UID_ROOT);
    export_uid(ob);
    ob->actually_save_player(nom);
    seteuid(nom);
    export_uid(ob);
    seteuid(UID_ROOT);
}

string get_wiz_name(string file) {
    string nom, tmp;

    if(file[0] != '/') file = "/"+file;
    if(sscanf(file, REALMS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    if(sscanf(file, DOMAINS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    sscanf(file, "/%s/%s", nom, tmp);
    return nom;
}

void log_error(string file, string msg) {
    string nom;

    if(!(nom = get_wiz_name(file))) nom = "log";
    
    catch(write_file(DIR_ERROR_LOGS+"/"+nom, msg));
    write("%^YELLOW%^"+msg+"%^RESET%^");
}

void destruct_environment_of(object ob) {
    if(!interactive(ob)) return;
    tell_object(ob, "The world about you swirls into nothingness, as "+
      "you are quickly teleported somewhere else.\n");
    ob->move(ROOM_VOID);
}

string make_path_absolute(string file) {
    return resolv_path((string)this_player()->get_path(), file);
}

int player_exists(string str) {
    return file_exists(DIR_USERS+"/"+str[0..0]+"/"+str+".o");
}

string get_root_uid() { return UID_ROOT; }

string get_bb_uid() { return UID_BACKBONE; }

string creator_file(string str) {
    return (string)call_other(OB_SIMUL_EFUN, "creator_file", str);
}

string domain_file(string str) {
    string nom, tmp;

    if(str[0] != '/') str = "/"+str;
    if(sscanf(str, DOMAINS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    return 0;
}

string author_file(string str) {
    string nom, tmp;

    if(str[0] != '/') str = "/"+str;
    if(sscanf(str, REALMS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    return 0;
}

static int slow_shutdown() {
    log_file("game_log", "Armageddon loaded by master: "+ctime(time())+".\n");
    new(OB_SHUT)->move(ROOM_START);
    SHUT_D->do_armageddon();
    return 1;
}

int save_ed_setup(object who, int code) {
    string file;

    if(!intp(code)) return 0;
    rm(file = user_path(getuid(who))+".edrc");
    return write_file(file, code+"");
}

int retrieve_ed_setup(object who) {
    string file;

    if(!file_exists(file = user_path(getuid(who))+".edrc")) return 0;
    return atoi(read_file(file));
}

string get_ed_buffer_save_file_name(string file) {
    string str;

    return (file_size(str=user_path(geteuid(this_player()))) == -2 ?
      str+"dead.edit" : DIR_TMP+"/"+geteuid(this_player())+".edit");
}

int is_locked() { return MUD_IS_LOCKED; }

int query_member_group(string who, string grp) {
    if(!groups) load_groups();
    if(groups[grp]) return (member_array(who, groups[grp]) != -1);
    else return 0;
}

mapping query_groups() {
    if(!groups) load_groups();
    return copy(groups);
}

