// Seeker
string itos(int i) {
    return ""+i+"";
}
string add_commas(int j)
{
    string start, finish;
    int i, b, neg;
    start = itos(j);
    b= 0;
    finish="";
    if (j < 0) neg = 1;
    if (neg) { sscanf(start, "-%s", finish);  start = finish; finish = ""; }
    i = strlen(start);
    while(i--)
    {
        b++;
        finish += sprintf("%c", start[i]);
        if (b >=3 && i>0) 
        {
            finish += ",";
            b=0;
        }
    }
    i = sizeof(finish);
    start ="";
    while(i--)
    {
        if (neg) { start += "-"; neg = 0; }
        start += sprintf("%c", finish[i]);
    }
    return start;
}
