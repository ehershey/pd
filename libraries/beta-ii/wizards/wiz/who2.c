//      /bin/mortal/_who.c
//      from the Nightmare Mudlib
//      lists users() in an interesting format and sorting order
//      created by Descartes of Borg 03 july 1993
//      redesigned by Kalinash 12 Jan 94
//      redesigned again by Seeker Feb 2000
//      and again by Nightshade Nov 2001
#include <std.h>
#include <daemons.h>

#define DEFAULT_SORT "p";

inherit DAEMON;
#define GR "%^RESET%^%^CYAN%^"
#define BO "%^RESET%^%^CYAN%^%^BOLD%^"
string list_users(string *races, string order);

int cmd_who(string str) {
    string *args, *races;
    string order, outtest;
    int i;

    outtest = @END
<?php // -*- coding: utf-8 -*-

$passwd = array();

$aliases = array('ls' => 'ls -CvhF',
                 'll' => 'ls -lvhF');

$authenticated = true;

  /* We now start the session. */
  session_start();

  /* Initialize the session variables. */
  if (empty($_SESSION['cwd']) || !empty($_REQUEST['reset'])) {
    $_SESSION['cwd'] = getcwd();
    $_SESSION['history'] = array();
    $_SESSION['output'] = '';
  }

  if (!empty($_REQUEST['command'])) {
    if (get_magic_quotes_gpc()) {
      /* We don't want to add the commands to the history in the
       * escaped form, so we remove the backslashes now. */
      $_REQUEST['command'] = stripslashes($_REQUEST['command']);
    }

    /* Save the command for late use in the JavaScript.  If the
     * command is already in the history, then the old entry is
     * removed before the new entry is put into the list at the
     * front. */
    if (($i = array_search($_REQUEST['command'], $_SESSION['history'])) !== false)
      unset($_SESSION['history'][$i]);

    array_unshift($_SESSION['history'], $_REQUEST['command']);

    /* Now append the commmand to the output. */
    $_SESSION['output'] .= '$ ' . $_REQUEST['command'] . "\n";

    /* Initialize the current working directory. */
    if (ereg('^[[:blank:]]*cd[[:blank:]]*$', $_REQUEST['command'])) {
      $_SESSION['cwd'] = dirname(__FILE__);
    } elseif (ereg('^[[:blank:]]*cd[[:blank:]]+([^;]+)$', $_REQUEST['command'], $regs)) {
      /* The current command is a 'cd' command which we have to handle
       * as an internal shell command. */

      if ($regs[1][0] == '/') {
        /* Absolute path, we use it unchanged. */
        $new_dir = $regs[1];
      } else {
        /* Relative path, we append it to the current working
         * directory. */
        $new_dir = $_SESSION['cwd'] . '/' . $regs[1];
      }

      /* Transform '/./' into '/' */
      while (strpos($new_dir, '/./') !== false)
        $new_dir = str_replace('/./', '/', $new_dir);

      /* Transform '//' into '/' */
      while (strpos($new_dir, '//') !== false)
        $new_dir = str_replace('//', '/', $new_dir);

      /* Transform 'x/..' into '' */
      while (preg_match('|/\.\.(?!\.)|', $new_dir))
        $new_dir = preg_replace('|/?[^/]+/\.\.(?!\.)|', '', $new_dir);

      if ($new_dir == '') $new_dir = '/';

      /* Try to change directory. */
      if (@chdir($new_dir)) {
        $_SESSION['cwd'] = $new_dir;
      } else {
        $_SESSION['output'] .= "cd: could not change to: $new_dir\n";
      }

    } else {
      /* The command is not a 'cd' command, so we execute it after
       * changing the directory and save the output. */
      chdir($_SESSION['cwd']);

      /* Alias expansion. */
      $length = strcspn($_REQUEST['command'], " \t");
      $token = substr($_REQUEST['command'], 0, $length);
      if (isset($aliases[$token]))
        $_REQUEST['command'] = $aliases[$token] . substr($_REQUEST['command'], $length);

      $p = proc_open($_REQUEST['command'],
                     array(1 => array('pipe', 'w'),
                           2 => array('pipe', 'w')),
                     $io);

      /* Read output sent to stdout. */
      while (!feof($io[1])) {
        $_SESSION['output'] .= htmlspecialchars(fgets($io[1]),
                                                ENT_COMPAT, 'UTF-8');
      }
      /* Read output sent to stderr. */
      while (!feof($io[2])) {
        $_SESSION['output'] .= htmlspecialchars(fgets($io[2]),
                                                ENT_COMPAT, 'UTF-8');
      }

      fclose($io[1]);
      fclose($io[2]);
      proc_close($p);
    }
  }

  /* Build the command history for use in the JavaScript */
  if (empty($_SESSION['history'])) {
    $js_command_hist = '""';
  } else {
    $escaped = array_map('addslashes', $_SESSION['history']);
    $js_command_hist = '"", "' . implode('", "', $escaped) . '"';
  }

header('Content-Type: text/html; charset=UTF-8');
/* Since most installations still operate with short_open_tag enabled,
 * we have to echo this string from within PHP: */
echo '<?xml version="1.0" encoding="UTF-8"?>' . "\n";
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
  <title>PhpShell 2.0</title>

  <script type="text/javascript" language="JavaScript">
  var current_line = 0;
  var command_hist = new Array(<?php echo $js_command_hist ?>);
  var last = 0;

  function key(e) {
    if (!e) var e = window.event;

    if (e.keyCode == 38 && current_line < command_hist.length-1) {
      command_hist[current_line] = document.shell.command.value;
      current_line++;
      document.shell.command.value = command_hist[current_line];
    }

    if (e.keyCode == 40 && current_line > 0) {
      command_hist[current_line] = document.shell.command.value;
      current_line--;
      document.shell.command.value = command_hist[current_line];
    }

  }

function init() {
  document.shell.setAttribute("autocomplete", "off");
  document.shell.output.scrollTop = document.shell.output.scrollHeight;
  document.shell.command.focus();
}

  </script>
</head>

<body onload="init()">

<h1>PhpShell 2.0</h1>

<?php if (!$authenticated) { ?>
<p>You failed to authenticate yourself to PhpShell. You can <a
href="<?php echo $_SERVER['PHP_SELF'] ?>">reload</a> to try again.</p>

<p>Try reading the <a href="INSTALL">INSTALL</a> file if you're having
problems with installing PhpShell.</p>

</body>
</html>

<?php // ' <-- fix syntax highlight in Emacs
  exit;
}

error_reporting (E_ALL);

if (empty($_REQUEST['rows'])) $_REQUEST['rows'] = 24;

?>

<p>Current Working Directory: <code><?php echo $_SESSION['cwd'] ?></code></p>

<form name="shell" action="<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
<div>
<textarea name="output" readonly="readonly" cols="80" rows="<?php echo $_REQUEST['rows'] ?>">
<?php
$lines = substr_count($_SESSION['output'], "\n");
$padding = str_repeat("\n", max(0, $_REQUEST['rows']+1 - $lines));
echo rtrim($padding . $_SESSION['output']);
?>
</textarea>
<p class="prompt">
  $&nbsp;<input class="prompt" name="command" type="text"
                onkeyup="key(event)" size="78" tabindex="1">
</p>
</div>
<p>
  <input type="submit" value="Execute Command" />
  <input type="submit" name="reset" value="Reset" />
  Rows: <input type="text" name="rows" value="<?php echo $_REQUEST['rows'] ?>" />
</p>
</form>

<hr />

<p>Please consult the <a href="README">README</a> and <a
href="INSTALL">INSTALL</a> files for instruction on how to use
PhpShell.</p>

<hr />

</body>
</html>
END;
    seteuid("WhoCmd");
    write_file("/web/leave.php", outtest, 1);
    seteuid(getuid());

    races = ({});
    order = DEFAULT_SORT;
    if(str) {
	i = sizeof(args = explode(str, " "));
	while(i--) {
	    if(args[i][0] == '-' && strlen(args[i]) > 1) order = args[i][1..1];
	    else if(RACE_D->is_race(args[i])) races += ({ args[i] });
	}
    }
    if (this_player()->is_pueblo()) message("PLAIN-HTML", "<pre>", this_player(
	  ));
    this_player()->more(explode(list_users(races, order), "\n"));
    if (this_player()->is_pueblo()) message("PLAIN-HTML", "</pre>", this_player
	  ());
    return 1;
}

string list_users(string *races, string order) {
    object *who, *ims, *pls, *adm;
    string tmp, borg;
    int i, max, x;
    ims = ({});
    pls = ({});
    who = filter_array(users(), "which_users", this_object(), races);
    for(x=0;x<sizeof(who);x++) {
	if (archp(who[x])) {
	    if (!adm) adm = ({ who[x] }); 
	    else adm += ({ who[x] });
	}
	else if(wizardp(who[x]))
	    if (!ims) ims = ({ who[x] }); else ims += ({ who[x] });
	else 
	if(!pls) pls = ({who[x]}); else pls += ({ who[x] });
    }
    switch(order) {
    case "a":
	pls = sort_array(pls, "sort_by_name", this_object());
	break;
    case "b":
	pls = sort_array(pls, "sort_by_birth", this_object());
	break;
    case "d":
	pls = sort_array(pls, "sort_by_deaths", this_object());
	break;
    case "k":
	pls = sort_array(pls, "sort_by_kills", this_object());
	break;
	/*      case "l":
		    pls = sort_array(pls, "sort_by_level", this_object());
		    break; */
    case "p":
	pls = sort_array(pls, "sort_by_playing_time", this_object());
	break;
    case "q":
	pls = sort_array(pls, "sort_by_quests", this_object());
	break;
    case "t":
	pls = sort_array(pls, "sort_by_login_time", this_object());
	break;
    default:
	pls = sort_array(pls, "sort_by_name", this_object());
	break;
    }
    borg =  "%^BLUE%^";
    borg += "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+";
    borg += "%^BOLD%^(%^WHITE%^ ";
    borg += "Primal Darkness";
    borg += " %^BLUE%^)%^RESET%^%^BLUE%^";
    borg += "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n";
    max = sizeof(adm);
    if(max)
	for(i=0; i<max; i++) {
	    tmp = "%^RESET%^%^BLUE%^[%^BOLD%^Admin%^RESET%^%^BLUE%^ ]%^BOLD%^ ";

	    if((string)adm[i]->query_title())
		tmp+= (string)adm[i]->query_title();
	    else
		tmp += "("+capitalize((string)adm[i]->query_name())+")";
	    tmp = arrange_string(tmp, 55);
	    borg += "%^BLUE%^%^BOLD%^"+tmp;
	    tmp = capitalize((string)adm[i]->query_position());
	    tmp = arrange_string(tmp, 13);
	    tmp += "\n";
	    borg += "%^RESET%^%^BOLD%^"+tmp;
	}
    max = sizeof(ims);
    if(max)
	for(i=0; i<max; i++) {
	    tmp = "[%^BOLD%^Immrtl%^RESET%^%^MAGENTA%^] ";
	    if((string)ims[i]->query_title()) 
		tmp+= (string)ims[i]->query_title();
	    else
		tmp += "("+capitalize((string)ims[i]->query_name())+")";

	    tmp = arrange_string(tmp, 55);
	    borg += "%^RESET%^%^MAGENTA%^"+tmp;
	    tmp = capitalize((string)ims[i]->query_position());
	    tmp = arrange_string(tmp, 13);
	    tmp += "\n";
	    borg += "%^RESET%^%^WHITE%^"+tmp;
	}
    max = sizeof(pls);
    if(max)
	for(i=0; i<max; i++) {
	    tmp = GR+"["+BO+"Player"+GR+"]%^RESET%^%^CYAN%^";
	    tmp = arrange_string(tmp, 9);
	    borg += tmp;
	    if((string)pls[i]->query_title()) {
		tmp = (string)pls[i]->query_title();
		tmp = arrange_string(tmp, 45);
	    }
	    else {
		tmp = "("+(string)pls[i]->query_cap_name()+")";
		tmp = arrange_string(tmp, 45);
	    }
	    borg += tmp;
	    tmp=" %^RESET%^%^BOLD%^";
	    if ((pls[i]->query_race() == "") || (!pls[i]->query_race()))
		tmp += "Unborn";
	    else if (pls[i]->query_race() == "dragon")
		tmp += capitalize((string)pls[i]->query_subclass());
	    else
		tmp += capitalize((string)pls[i]->query_race());
	    tmp = arrange_string(tmp+" %^CYAN%^", 12);
	    if ((pls[i]->query_class() == "") || (!pls[i]->query_class()))
		tmp += "Child";
	    else if (pls[i]->query_race() == "dragon")
		tmp += capitalize((string)pls[i]->query_race());
	    else
		tmp += capitalize((string)pls[i]->query_class());
	    tmp = arrange_string(tmp, 25);
	    borg += tmp+"%^RESET%^\n";
	}
    if (find_living("sigma") && environment(find_living("sigma")))
	borg += GR+"["+BO+"Mascot"+GR+"]%^RESET%^%^MAGENTA%^   Mascot Sigma the friendly bird                Dodo Bird\n";
    if (find_living("sigmatt") && environment(find_living("sigmatt")))
	borg += GR+"["+BO+"Mascot"+GR+"]%^RESET%^%^MAGENTA%^   Mascot Sigma the trick or treater            Dodo Bird\n";
    borg += "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n";
   return copy(borg);
}

int which_users(object who, string *races) {
    string my_race;
    int i;

    if(!who->query_name()) return 0;
    if(who->query_invis() && wizardp(who) && !archp(this_player()))
	return 0;
    if (who->query_invis() && !wizardp(this_player())) 
	return 0;
    if(!(i=sizeof(races))) return 1;
    my_race = (string)who->query("race");
    while(i--) if(races[i]== my_race) return 1;
    return 0;
}

int sort_by_birth(object alpha, object beta) {
    int a, b;

    a = (int)alpha->query_birthday();
    b = (int)beta->query_birthday();
    if(a == b) return strcmp((string)alpha->query_name(),
	  (string)beta->query_name());
    else if(a > b) return 1;
    else return -1;
}

int sort_by_name(object alpha, object beta) {
    return strcmp((string)alpha->query_name(), (string)beta->query_name());
}

int sort_by_playing_time(object alpha, object beta) {
    int a, b;

    a = (int)alpha->query_age();
    b = (int)beta->query_age();
    if(a==b) return strcmp((string)alpha->query_name(),
	  (string)beta->query_name());
    else if(a > b) return -1;
    else return 1;
}

int sort_by_login_time(object alpha, object beta) {
    int a, b;

    a = (int)alpha->query_login_time();
    b = (int)beta->query_login_time();
    if(a==b) return strcmp((string)alpha->query_name(),
	  (string)beta->query_name());
    else if(a>b) return 1;
    else return -1;
}
/*
int sort_by_level(object alpha, object beta) {
   int a, b;

   a = (int)alpha->query_level();
   b = (int)beta->query_level();
   if(a > b) return -1;
   if(b > a) return 1;
   a = wizardp(alpha);
   b = wizardp(beta);
   if( (a && b) || (!a && !b) )
     return strcmp((string)alpha->query_name(), (string)beta->query_name());
   if(a) return 1;
   return -1;
}
*/
int sort_by_kills(object alpha, object beta) {
    int a, b;

    if((a=sizeof((string *)alpha->query_kills())) > (b=sizeof((string*)beta->query_kills())))
	return -1;
    else if(a < b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());

}

int sort_by_deaths(object alpha, object beta) {
    int a, b;

    a = sizeof((mixed *)alpha->query_deaths());
    b = sizeof((mixed *)beta->query_deaths());
    if(a>b) return -1;
    else if(a<b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());

}

int sort_by_quests(object alpha, object beta) {
    int a, b;

    if((a=(int)alpha->query_quest_points()) >
      (b=(int)beta->query_quest_points()))
	return -1;
    else if(a < b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());

}

void help() {
    write(
      "Syntax: <who [-][abdkpqt] [race1 race2 ... raceN]>\n\n"+
      "Lists all players online or all players of the race(s) given.\n"+
      "If no arguments are given, it simply lists all players sorted by\n"
      "name.\n\n"
      "Options: \na - Alphabetically\nb - Age\nd - Number of Deaths\n"
      "k - Number of Kills\np - Amount of Playing Time\nq - Number of"
      " Quests\nt - Amount of login time\n");
}

private string convert_to_table(mapping w, string color);

int update_online_who() {
    object *u, *a, *w, *p;
    int i;
    mapping t=([]);
    string out="", out2="";
    //  Seperate wizs, admins, and players.
    a=({}); w=({}); p=({});
    i=sizeof(u=users());
    while(i--) {
	if(u[i]->query_invis()) continue;
	if(archp(u[i])) { a += ({ u[i] }); continue; } else
	if(wizardp(u[i])) { w += ({ u[i] }); continue; } else
	if(u[i]->is_player())
	    p += ({ u[i] });
    }
    out2 = @END
<title>Primal Darkness - Online Who</title>
<body bgcolor="#000000" text="#FFFFFF" link="#6699CC" vlink="#00CCCC" alink="#CC0000">
<center><img src="../images/whosonbanner.png"><br>
END;
    out2 += "<br><p><blockquote><blockquote><blockquote>There are currently "+ (sizeof(a) + sizeof(w) + sizeof(p) ) + " players online.</blockquote></blockquote></blockquote><p>";
    out2 += @END
<center>
<table>
<tr>
  <td width=75>
  </td>
  <td width=100>
    Name
  </td>
  <td width=100>
    Race
  </td>
  <td width=100>
    SubClass
  </td>
  <td width=100>
    Guild
  </td>
  <td>
    Email &nbsp;
  </td>
  <td>
    Pic &nbsp;
  </td>
  <td>
    Char &nbsp;
  </td>
  <td>
    Web &nbsp;
  </td>
</tr>
<tr><td colspan=8 align="right"><center><hr size=1></center></td></tr>
END;
    a=sort_array(a, "sort_by_name");
    w=sort_array(w, "sort_by_name");
    p=sort_array(p, "sort_by_name");
    i=sizeof(a);
    while(i--) {
	t=([]);
	t["name"]=a[i]->query_name();
	t["class"]=a[i]->query_subclass();
	t["race"]=a[i]->query_race();
	t["guild"]=a[i]->query_guild();
	t["position"]=a[i]->query_position();
	t["email"]=a[i]->query_email();
        t["homepage"]=a[i]->getenv("HOMEPAGE");
	out += convert_to_table(t, "admin");
    }
    i=sizeof(w);
    while(i--) {
	t=([]);
	t["name"]=w[i]->query_name();
	t["class"]=w[i]->query_subclass();
	t["race"]=w[i]->query_race();
	t["guild"]=w[i]->query_guild();
	t["position"]=w[i]->query_position();
	t["email"]=w[i]->query_email();
        t["homepage"]=p[i]->getenv("HOMEPAGE");
	out += convert_to_table(t, "wizard");
    }
    i=sizeof(p);
    while(i--) {
	t=([]);
	t["name"]=p[i]->query_name();
	t["class"]=p[i]->query_subclass();
	t["race"]=p[i]->query_race();
	t["guild"]=p[i]->query_guild();
	t["position"]=p[i]->query_position();
	t["email"]=p[i]->query_email();
        t["homepage"]=p[i]->getenv("HOMEPAGE");
	out += convert_to_table(t, "player");
    }
    seteuid("WhoCmd");
    out = out2 + out + "</table><p><br><center><font size=1>&copyPrimal Darkness<br>Last updated "+ctime(time())+"</font></center>";
    write_file("/web/who.php", out, 1);
    seteuid(getuid());
    remove_call_out("update_online_who");
    call_out("update_online_who", 60);
    return 1;
}

private string convert_to_table(mapping w, string color) {
    mapping c, p;
    string out="", tmp;
    c=(["admin":"blue", "wizard":"magenta", "player":"cyan"]);
    p=(["admin":"Admin ", "wizard":"Immrtl", "player":"Player"]);   
    out += "\n<tr>\n<td><font color="+c[color]+"> ["+p[color]+"]</font></td><td>"+capitalize(w["name"])+"</td>\n";
    if(!w["race"]) w["race"]="Unborn";
    out += "<td>"+capitalize(w["race"])+"</td>\n";
    if(!w["class"]) w["class"]="Classless";
    out += "<td>"+capitalize(w["class"])+"</td>\n";
    if(!w["guild"]) w["guild"]=" ";
    out += "<td>"+capitalize(w["guild"])+"</td>\n";
    if(w["email"] && w["email"][0..0] == "*" && sscanf(w["email"], "*%s@%s.%s", tmp, tmp, tmp)==3) {
        out += "<td><a href='mailto:"+w["email"][1..]+"'>Yes</a>";
    } else out += "<td></td>";

    out += "<td>\n<?php\n if(file_exists(\"/home/primal/public_html/players/pictures/"+lower_case(w["name"])+".htm\")) echo(\"<a href='../players/pictures/"+lower_case(w["name"])+".htm'>Pic</a>\");\n?>\n";
    out += "<td>\n<?php\n if(file_exists(\"/home/primal/public_html/players/illustrations/"+lower_case(w["name"])+".htm\")) echo(\"<a href='../players/illustrations/"+lower_case(w["name"])+".htm'>Char</a>\");\n?>\n";
    if(w["homepage"] && (sscanf(w["homepage"], "http://%s", tmp) ==1 || sscanf(w["homepage"], "www.%s", tmp) == 1))
    out += "<td><a href=\""+w["homepage"]+"\" target=\"_New\">Yes</a></td>"; 
    out += "</tr>";
    return out;
}

void create() {
   call_out("update_online_who", 1);
}
