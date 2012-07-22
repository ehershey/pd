/*
// Thanks to Huthar for this!
// Bug in "here" option fixed by Pallando 93-05-26
// "cwd" option added by Pallando 93-05-30
*/

string resolv_path(string curr, string neww) {
    int i;
    string *tmp;
    string t1;

    if(curr && (curr == "cwd") && this_player())
      curr = (string)this_player()->get_path();
    if(!neww || neww == ".") return curr;
    if( (neww == "here") && this_player() )
    {
        return file_name(environment(this_player())) + ".c";
    }
    if(neww == "~" || neww == "~/" )
      neww = user_path((string)this_player()->query_name());
    if(sscanf(neww,"~/%s",t1))
      neww = user_path((string)this_player()->query_name()) + t1;
    else if(sscanf(neww,"~%s",t1))
      neww = user_path(t1); 
    else if(neww[0] != '/')
      neww = curr + "/" + neww;

    if(neww == "^" || neww == "^/" )
      neww = domain_path((string)this_player()->query_name());
    if(sscanf(neww,"^/%s",t1))
      neww = user_path((string)this_player()->query_name()) + t1;
    else if(sscanf(neww,"^%s",t1))
      neww = user_path(t1);
    else if(neww[0] != '/')
      neww = curr + "/" + neww;



    if(neww[strlen(neww) - 1] != '/')
        neww += "/";
    tmp = explode(neww,"/");
    if (!tmp) tmp = ({"/"});
    for(i = 0; i < sizeof(tmp); i++)
        if(tmp[i] == "..") {
            if(sizeof(tmp) > 2) {
                tmp = tmp[0..(i-2)] + tmp[(i+1)..(sizeof(tmp)-1)];
                i -= 2;
            } else {
                tmp = tmp[2 ..(sizeof(tmp)-1)];
                i = 0;
            }
        }
     neww = "/" + implode(tmp,"/");
     if(neww == "//") neww = "/";
     return neww;
}

