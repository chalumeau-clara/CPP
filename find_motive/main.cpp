#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return 1;
    }

    string path = argv[1];
    string motive = argv[2];

    ifstream myfile;
    myfile.open(path);

    if (myfile.fail())
    {
        cout << "The file " + path + " could not be opened." << '\n';
        return 1;
    }

    string word;
    size_t count = 0;
    while (myfile >> word)
    {
        if (word.find(motive) != string::npos)
            count++;
    }
    myfile.close();
    
    cout << "The file " + path + " contains " << count 
         << " words containing the motive " << motive << endl;

    return 0;
}