
class x {
    int a;
    string b; };

class x my_test = new(class x);
void set_x(int my_num,string my_name) {
    my_test -> a = my_num;
    my_test -> b = my_name; 
}

string report() { return "number =="+my_test->a+"   name =="+my_test->b+"\n"; }
