#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n==1){
        cout << "Move disk from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n-1, source, auxiliary, destination);
    cout << "Move disk from " << source << " to " << destination << endl;
    towerOfHanoi(n-1, auxiliary, destination, source);
}

int main(int argc, char const *argv[])
{
    towerOfHanoi(7, 'A', 'C', 'B');
    return 0;
}
