
#include <iostream>
#include <vector>
using namespace std;

class time {
protected:
    int hours;
    int min;
    int sec;
public:
    time(int hours, int min, int sec) {
        this->hours = hours;
        this->min = min;
        this->sec = sec;
    }
   /* ~time() {

    }*/
    void display() {
        cout << hours << ":" << min << ":" << sec << endl;
    }
    void slozhenie(time a, time b) {
        cout << "timeA + timeB = ";
        this->sec += (a.sec + b.sec) % 60;
        this->min += ((a.min + b.min) + ((a.sec + b.sec) / 60)) % 60;
        this->hours = ((a.hours + b.hours) + ((a.min + b.min + (a.sec + b.sec) / 60) / 60))% 24;
        this->display();
    }
    void vychitanie(time a, time b) {
        cout << "timeA - timeB = ";
        int sum_a = a.sec + a.min*60 + a.hours*3600;
        int sum_b = b.sec + b.min * 60 + b.hours * 3600;

        this->sec = (abs(sum_a - sum_b)) % 60;
        this->min = (abs(sum_a - sum_b)) / 60 % 60;
        this->hours = (abs(sum_a - sum_b)) / 3600 % 24;
        this->display();
    }
    void umnozhenie(time a, int b) {
        cout << "timeA * const = ";
        this->sec = (a.sec * b) % 60;
        this->min = ((a.min * b) + ((a.sec * b) / 60)) % 60;
        this->hours += ((a.hours * b) + ((a.min * b) / 60)+ ((a.sec * b) / 3600)) % 24;
        this->display();
    }
    void comparison(time a, time b) {
        int sum_a = a.sec + a.min * 60 + a.hours * 3600;
        int sum_b = b.sec + b.min * 60 + b.hours * 3600;
        if (sum_a == sum_b) cout << "timeA and timeB are equal" << endl;
        else if (sum_a > sum_b) cout << "timeA larger than time B" << endl;
        else if (sum_a < sum_b) cout << "timeB larger than time A" << endl;

        
    }
};

int main(){
    int h1, h2, m1, m2, s1, s2;
    time c(0, 0, 0);
    char o;
    cout << "info: operations\n";
    cout << "\tto add timeA plus timeB:\t'+'\n\tto subtract timeB from timeA:\t'-'\n\tto multiply timeA by constant:\t'*'\n\tto compare timeA with timeB:\t'='\n";
    cout << "enter the operation" << endl;
    cin >> o;
    if (o == '*') {
        cout << "enter timeA" << endl;
        cin >> h1 >> m1 >> s1;
        time a(h1, m1, s1);
        int n = 0;
        cout << "enter const" << endl;
        cin >> n;
        c.umnozhenie(a, n);
    }
    else {
        cout << "enter timeA" << endl;
        cin >> h1 >> m1 >> s1;
        cout << "enter timeB" << endl;
        cin >> h2 >> m2 >> s2;
        time b(h2, m2, s2), a(h1, m1, s1);
        if (o == '+') {
            c.slozhenie(a, b);
        }
        if (o == '-') {
            c.vychitanie(a, b);
        }
        if (o == '=') {
            c.comparison(a, b);
        }
    }
    return 0;
}
