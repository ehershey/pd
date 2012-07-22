// Seeker [ Pueblo Support ]

#define INIT "</xch_mudtext><img xch_mode=html><xch_page clear=text>"

static string p_md5, p_ver;

int setup_pueblo(string ver, string md5);
void initalize_pueblo();
string modify_output(string str);
void display_picture(string str);
string query_pueblo_version();
string query_pueblo_md5();

int setup_pueblo(string ver, string md5)
{
 if (!ver || !md5 || ver=="" || md5=="")
   return 0;

 p_ver = ver;
 p_md5 = md5;

 return 1;
}

void initalize_pueblo()
{
 message("html", INIT+"\n", this_object());
}
string modify_output(string str)
{
 string msg;

 if (!str || str == "") return str;

msg = str;
if (p_ver) {
  msg = substr(msg, "&", "&amp;");
  msg = substr(msg, "<", "&lt;");
  msg = substr(msg, ">", "&gt;");
  msg = substr(msg, "\"", "&quot;");
  msg = substr(msg, " ", "&nbsp;");
 }
 return msg;
}

void display_picture(string str)
{
 message("html", "<img src=\""+str+"\">", this_object());
}
string query_pueblo_version() { return p_ver; }
string query_pueblo_md5()     { return p_md5; }
