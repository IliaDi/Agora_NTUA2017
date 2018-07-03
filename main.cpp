#include <iostream>
#include <fstream>

using namespace std;

// Utility function to find GCD of 'a' and 'b' found online
long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    long long int N;
    ifstream myFile;
    myFile.open(argv[1]); //open file

    if (myFile.is_open()) //file opened without a problem

    {

        myFile >> N;
        long long int a;
//read from file create list nodes
        long long int *shopping_rate = new long long int[N];
        long long int *before_i = new long long int[N];
        long long int *after_i = new long long int[N];
        for (long long int i = 0; i < N; i++) {
            myFile >> a;
            shopping_rate[i] = a;
        }
        myFile.close();

//calculating lcm of rates before village i
        before_i[0] = 1;
        before_i[1] = shopping_rate[0];
        long long int lcm_left = shopping_rate[0];
        for (long long int i = 1; i < N - 1; i++) {
            a=(gcd(shopping_rate[i], lcm_left));
            lcm_left = ((shopping_rate[i]/a) * lcm_left) ;
            before_i[i + 1] = lcm_left;
        }


//calculating lcm of rates after village i
        after_i[N - 1] = 1;
        after_i[N - 2] = shopping_rate[N - 1];
        long long int lcm_right = shopping_rate[N - 1];
        for (long long int i = N - 2; i > 0; i--) {
            a=(gcd(shopping_rate[i], lcm_right));
            lcm_right = ((shopping_rate[i]/a) * lcm_right);
            after_i[i - 1] = lcm_right;
        }

//calculating lcm when village i is missing
        long long int lcm_without_i;
        long long int missing_villagers = 0;
        a=gcd(before_i[N - 1], shopping_rate[N - 1]);
        long long int lcm_all = ((before_i[N - 1]/a) * shopping_rate[N - 1] );
        long long int next_meeting_day = lcm_all;
        for (long long int i = 0; i < N; i++) {
            a=gcd(before_i[i], after_i[i]);
            lcm_without_i = ((before_i[i]/a) * after_i[i] );
            if (lcm_without_i < next_meeting_day) {
                next_meeting_day = lcm_without_i;
                missing_villagers = i + 1;
            }
        }

        delete[]shopping_rate;
        delete[]before_i;
        delete[]after_i;
        cout << next_meeting_day << " " << missing_villagers;
    } else {
        cout << "No such input file\n";
    }
    return 0;
}


