//      /bin/user/_chfn.c
//      from the Nightmare Mudlib
//      command to change finger info
//      created by Sulam@TMI 911208
//      modified for the Nightmare 3.0 security by Descartes of Borg 930814
//     modified by seeker
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_chfn(string arg) {
    write("Changing finger information on " +
        (string) this_player()->query_name() + " at Primal Darkness.");
    write("Default values are printed inside '[]'.");
    write("To make your information public, begin with a '*' ie. '*Nightshade'.");
    write("To accept the default, type <return>.\n");
    message("no_wrap","Name ["+(string)this_player()->query_rname()+"] : ",
this_player());
    input_to("new_name");
    return 1;
}

static void
new_name(string rname) {
    if(strlen( rname ) > 56) {
        write("That is too long.\nPlease limit it to 56 characters.");
        message("no_wrap","Name ["+(string)this_player()->query_rname()+"] : ",
            this_player());
        input_to("new_name");
        return;
    }
    if( rname && strlen( rname ) > 0 ) {
        seteuid(UID_USERACCESS);
        this_player()->set_rname(rname);
        seteuid(getuid());
        this_player()->save_player((string)this_player()->query_name());
    }
    message("no_wrap", "Email address ["+this_player()->query_email()+"] :",
this_player());
    input_to("new_email");
}

static void
new_email(string e) {
    if(strlen( e ) > 56) {
        write("That is too long.\nPlease limit it to 56 characters.");
        message("no_wrap", "Email address ["+this_player()->query_email()+"] :",
            this_player());
        input_to("new_email");
        return;
    }
    if( e && strlen( e ) > 0 ) {
        seteuid(UID_USERACCESS);
        this_player()->set_email(e);
        seteuid(getuid());
    }
    message("no_wrap", "\nNote: The following information is always public.
Pressing <enter> will clear the data for the current messenger.\n",
this_player());
    message("no_wrap", "MSN ["+this_player()->query_env("MSN")+"] :",
this_player());
    input_to("new_msn");
}

static void
new_msn(string e) {
    if(strlen( e ) > 56) {
        write("That is too long.\nPlease limit it to 56 characters.");
        message("no_wrap", "MSN ["+this_player()->query_env("MSN")+"] :",
            this_player());
        input_to("new_msn");
        return;
    }
    if( e && strlen( e ) > 0 ) {
        if(e[0] == '*') e = e[1..sizeof(e)-1];
        seteuid(UID_USERACCESS);
        this_player()->set_env("MSN", e);
        seteuid(getuid());
    }
    else
        this_player()->set_env("MSN");
    message("no_wrap", "AIM ["+this_player()->query_env("AIM")+"] :",
this_player());
    input_to("new_aim");
}

static void
new_aim(string e) {
    if(strlen( e ) > 56) {
        write("That is too long.\nPlease limit it to 56 characters.");
        message("no_wrap", "AIM ["+this_player()->query_env("AIM")+"] :",
            this_player());
        input_to("new_aim");
        return;
    }
    if( e && strlen( e ) > 0 ) {
        if(e[0] == '*') e = e[1..sizeof(e)-1];
        seteuid(UID_USERACCESS);
        this_player()->set_env("AIM", e);
        seteuid(getuid());
    }
    else
        this_player()->set_env("AIM");
    message("no_wrap", "ICQ ["+this_player()->query_env("ICQ")+"] :",
this_player());
    input_to("new_icq");
}

static void
new_icq(string e) {
    if(strlen( e ) > 56) {
        write("That is too long.\nPlease limit it to 56 characters.");
        message("no_wrap", "ICQ ["+this_player()->query_env("ICQ")+"] :",
            this_player());
        input_to("new_aim");
        return;
    }
    if( e && strlen( e ) > 0 ) {
        if(e[0] == '*') e = e[1..sizeof(e)-1];
        seteuid(UID_USERACCESS);
        this_player()->set_env("ICQ", e);
        seteuid(getuid());
    }
    else
        this_player()->set_env("ICQ");
    message("no_wrap", "Yahoo ["+this_player()->query_env("YAHOO")+"] :",
this_player());
    input_to("new_yahoo");
}

static void
new_yahoo(string e) {
    if(strlen( e ) > 56) {
        write("That is too long.\nPlease limit it to 56 characters.");
        message("no_wrap", "Yahoo ["+this_player()->query_env("YAHOO")+"] :",
            this_player());
        input_to("new_yahoo");
        return;
    }
    if( e && strlen( e ) > 0 ) {
        if(e[0] == '*') e = e[1..sizeof(e)-1];
        seteuid(UID_USERACCESS);
        this_player()->set_env("YAHOO", e);
        seteuid(getuid());
    }
    else
        this_player()->set_env("YAHOO");
    message("no_wrap", "General Data:",
this_player());
    input_to("new_data");
}

static void
new_data(string e) {
    string *blah;
    blah = explode(wrap(e, 62), "\n");
    if(sizeof(blah) > 20) {
        write("That is too long.\nPlease limit it to 20 lines.");
        message("no_wrap", "General Data:", this_player());
        input_to("new_data");
        return;
    }
    e = implode(blah, "\n    ");
    e = "    "+e;
if(sizeof(blah) > 0)
    if( blah[0] && strlen( blah[0] ) > 0 ) {
        seteuid(UID_USERACCESS);
        this_player()->set_env("LFINGER", e);
        seteuid(getuid());
    }
    else
        this_player()->set_env("LFINGER");
    else
        this_player()->set_env("LFINGER");
    this_player()->force_me("save");
    message("no_wrap", "Changes completed.\n\n",
this_player());
}

int
help() {
  write("Command: chfn\nSyntax: chfn (no args)\n"+
        "This asks for and updates your information for\n"+
        "the finger command.  Please use it if you have\n"+
        "not yet.\n"
        "See also: finger, describe, timezone, passwd\n"
  );
  return 1;
}
