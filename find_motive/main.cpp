#include "find_motive.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: ./main [PATH] [MOTIVE]\n";
        return 1;
    }
    int num;
    string path = argv[1];
    string motive = argv[2];

    ifstream file (path);
    if (!file.is_open())
    {
        cout<<"The file " << path << " could not be opened.\n";
        return 1;
    }
    
    string mystring = string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    
    num = find_motive(mystring, motive);

    cout<<"The file " << path << " contains "<< num << " words containing the motive " << motive << "\n";

    return 0;
}