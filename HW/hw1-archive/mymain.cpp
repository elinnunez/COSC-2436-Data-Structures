#include <iostream>
#include <sstream>
#include <vector>
#include "ArgumentManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Books
{
    string genre;
    string title;
    string author;
    string year;
};

string removeSpaces(string str)
{
    stringstream ss;
    string temp;

    //Store str into ss
    ss << str;

    // Make str empty
    str = "";

    // Running loop till end of stream
    while (!ss.eof())
    {

        // Extracting word by word from stream
        ss >> temp;

        // Concatenate str
        str = str + temp;
    }
    return str;
}

int main(int argc, char *argv[])
{

    ArgumentManager am(argc, argv);

    string infilename = am.get("input");
    string outfilename = am.get("output");
    string comfilename = am.get("command");

    ifstream infile(infilename);
    ifstream comfile(comfilename);
    ofstream outfile(outfilename);

    vector<Books> library;

    vector<string> gCommand;
    vector<string> tCommand;
    vector<string> aCommand;
    vector<string> yCommand;

    if (!infile.is_open())
    {
        cout << "File isn't open" << endl;
        return 1;
    }

    bool command = true;

    if (!comfile.is_open())
    {
        cout << "Command file isn't open" << endl;
        return 1;
    }
    else
    {

        string cline;

        while (getline(comfile, cline))
        {

            if (cline.length() == 0)
            {
                continue;
            }

            if (cline.substr(0, 5) == "genre")
            {
                gCommand.push_back(cline);
            }
            else if (cline.substr(0, 4) == "year")
            {
                yCommand.push_back(cline);
            }
            else if (cline.substr(0, 6) == "author")
            {
                aCommand.push_back(cline);
            }
            else if (cline.substr(0, 5) == "title")
            {
                tCommand.push_back(cline);
            }
            else
            {
                cout << "Command Line Can't Be Read" << endl;
            }
        }
    }

    while (!infile.eof())
    {

        string line;

        while (getline(infile, line))
        {

            if (line == "")
            { //if line in textfile is empty, skip it
                continue;
            }

            stringstream ss(line);

            string nwsLine = removeSpaces(line);

            ss << nwsLine;

            string genre, gTitle, title, tTitle, author, aTitle, year, yTitle;

            getline(ss, genre, ':');
            getline(ss, gTitle, ',');
            getline(ss, title, ':');
            getline(ss, tTitle, ',');
            getline(ss, author, ':');
            getline(ss, aTitle, ',');
            getline(ss, year, ':');
            getline(ss, yTitle, '}');

            //Logic for valid order of list

            if (genre.substr(1) == "genre" && title == "title" && author == "author" && year == "year")
            {

                Books curBook;

                curBook.genre = genre.substr(1) + ":" + gTitle;
                curBook.title = title + ":" + tTitle;
                curBook.author = author + ":" + aTitle;
                curBook.year = year + ":" + yTitle;

                if (command)
                {
                    if (gCommand.size() > 0)
                    {
                        bool included = false;
                        for (int i = 0; i < gCommand.size(); i++)
                        {
                            if (curBook.genre == gCommand.at(i))
                            {
                                included = true;
                                break;
                            }
                        }

                        if (!included)
                        {
                            continue;
                        }
                    }
                    if (yCommand.size() > 0)
                    {
                        bool included = false;
                        for (int i = 0; i < yCommand.size(); i++)
                        {
                            if (curBook.year == yCommand.at(i))
                            {
                                included = true;
                                break;
                            }
                        }

                        if (!included)
                        {
                            continue;
                        }
                    }
                    if (aCommand.size() > 0)
                    {
                        bool included = false;
                        for (int i = 0; i < aCommand.size(); i++)
                        {
                            if (curBook.author == aCommand.at(i))
                            {
                                included = true;
                                break;
                            }
                        }

                        if (!included)
                        {
                            continue;
                        }
                    }
                    if (tCommand.size() > 0)
                    {
                        bool included = false;
                        for (int i = 0; i < tCommand.size(); i++)
                        {
                            if (curBook.title == tCommand.at(i))
                            {
                                included = true;
                                break;
                            }
                        }

                        if (!included)
                        {
                            continue;
                        }
                    }
                    library.push_back(curBook);
                }

                // library.push_back(curBook);
            }
            else
            {
                continue;
            }
        }
    }

    // cout << "Valid Books" << endl;
    for (int i = 0; i < library.size(); i++)
    {
        outfile << "{" << library.at(i).genre << "," << library.at(i).title << "," << library.at(i).author << "," << library.at(i).year << "}" << endl;
    }

    infile.close();
    outfile.close();
    comfile.close();
    return 0;
}