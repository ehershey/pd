/*    /daemon/command.c
 *    from Nightmare IV
 *    a new commands daemon, much faster than the old
 *    created by Descartes of Borg 940119
 *    Data storage concept by Archimedes@Nightmare
 */

#include <dirs.h>

private static mapping __Cmds;
private static string *__Paths;
#define __length__ 13
void rehash(mixed *val);
string find_cmd(string cmd, string *path);
string *query_paths();
varargs string *query_commands(string str);

void create() {
    seteuid(getuid());
    __Cmds = ([]);
    __Paths = ({});
    rehash( ({ DIR_MORTAL_CMDS, DIR_CREATOR_CMDS, DIR_CLASS_CMDS,
      DIR_SYSTEM_CMDS }) );
  }

string find_cmd(string cmd, string *path) {
    string *tmp;

    if (strlen(cmd)>__length__+1) cmd=cmd[0..__length__];
    if(__Cmds[cmd] && sizeof(tmp = (path & (string *)__Cmds[cmd])))
      return sprintf("%s/_%s", tmp[0], cmd);
    else {
	tmp = (path & __Paths);
	if(sizeof(tmp = path - tmp)) rehash(tmp);
	if(__Cmds[cmd] && sizeof(tmp = (path & (string *)__Cmds[cmd])))
	  return sprintf("%s/_%s", tmp[0], cmd);
      }
    return 0;
  }

void rehash(mixed val) {
    string *choses;
    int i, j;

#if 0
// PETER DEBUG
    write("rehash\n");
#endif

    if(stringp(val)) val = ({ val });
    else if(!pointerp(val)) return;
    i = sizeof(val);
    while(i--) {
#if 0
// PETER DEBUG
write("now doing dir="+val[i]+"\n");
#endif
	if(file_size(val[i]) !=-2) continue;
	j = sizeof(choses = get_dir(val[i]+"/_*.c"));
	while(j--) {
#if 0
// PETER DEBUG
write("choses[j]="+choses[j]);
#endif
	    choses[j] = choses[j][1..strlen(choses[j])-3];
#if 0
// PETER DEBUG
write(" then choses[j]="+choses[j]+"\n");
#endif
	    if(pointerp(__Cmds[choses[j]])) __Cmds[choses[j]] += ({ val[i] });
	    else __Cmds[choses[j]] = ({ val[i] });
	  }
	__Paths = distinct_array(__Paths + ({ val[i] }));
      }
  }

string *query_paths() { return __Paths; }

varargs string *query_commands(string str) {
    string *cmds, *tmp;
    int i;

    if(!str) return keys(__Cmds);
    i = sizeof(cmds = keys(__Cmds));
    tmp = ({});
    while(i--) if(member_array(str, __Cmds[cmds[i]]) != -1) tmp += ({cmds[i]});
    return tmp;
  }
