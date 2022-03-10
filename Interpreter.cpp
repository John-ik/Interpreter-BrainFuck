#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono_literals;

const string inFileNameProc (string in);
const string setting (string set);

int main (int argc, char* argv[])
{
    const int timeOut { stoi(setting("TimeOut")) };
    string filename;
    if (argc > 1)
        filename = argv[1];
    else
    {
        cout << "Enter file name or path: ";
        cin >> filename;
    }
    auto startTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    filename = inFileNameProc(filename);
    ifstream BFfile (filename);
    if (!BFfile.is_open())
    {
        cout << "Error: File isn`t open";
        return 0;
    }
    
    BFfile.seekg(0, ios::end);
    int size = BFfile.tellg();
    if (!size)
    {
        cout << "Error: Symbol not found";
        return 0;
    }
    BFfile.seekg(0);
    vector<char> code;
    code.resize(size);
    BFfile.read(&code.at(0), size);

    BFfile.close();
    
    int i = 0;
    int deep = 0;
    vector<char> arr;
    arr.resize(30000);
    auto endTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    for (int j = 0; j < code.capacity(); j++)
    {
        endTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        if (endTime - startTime > timeOut)
        {
            cout << "Error: out of time: " << timeOut << 's';
            return 0;
        }
        if (code.at(j) == '>') 
        {
            i++;
        }else if (code.at(j) == '<')
        {
            i--;
        }else if (code.at(j) == '+')
        {
            arr.at(i)++;
        }else if (code.at(j) == '-')
        {
            arr.at(i)--;
        }else if (code.at(j) == '.')
        {
            cout << arr.at(i);
        }else if (code.at(j) == ',')
        {
            cin >> arr.at(i);
        }else  if (code.at(j) == '[')
        {
            if (!arr.at(i))
            {
                deep++;
                while (deep)
                {
                    j++;
                    if (code.at(j) == '[')
                        deep++;
                    if (code.at(j) == ']')
                        deep--;
                }
            }else
                continue;
        }else if (code.at(j) == ']')
        {
            if (!arr.at(i))
                continue;
            else
            {
                if (code.at(j) == ']')
                    deep++;
                while (deep)
                {
                    j--;
                    if (code.at(j) == '[')
                        deep--;
                    if (code.at(j) == ']')
                        deep++;
                }
            }
        }
    }

    cout << endl;
    system("pause");
}

//Processing input name or path file 
const string inFileNameProc (string in){
    if (in.find('\\') == string::npos)
    {
        in = setting("DefaultPath") + in;
    }
    if (in.find(".bf") == string::npos)
    {
        in += ".bf";
    }
    return (in);
}

// Return string of the specified seting from setting file
// DefaultPath
// TimeOut
const string setting (string set)
{
    set += ": ";
    ifstream SettingsFile ("Settings.txt");
    string out;
    out.resize(127);
    SettingsFile.getline(&out.at(0), 127, '\n');
    while (out.find(set) == string::npos)
    {
        out.clear();
        out.resize(127);
        SettingsFile.getline(&out.at(0), 127, '\n');
    }
    out.erase(0, out.find(':') + 2);
    if (out.find('\000') != string::npos)
        out.erase(out.find('\000'));
    SettingsFile.close();
    return out;
}