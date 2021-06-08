#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <QStringList>
#include <QStandardItem>
#include "mainwindow.h"

#ifndef MOVIES_H
#define MOVIES_H

struct Movie
{
    std::string title;
    std::string year;
    std::string Age;
    std::string IMDb;
    std::string RT;
    std::string Directors;
    std::string Genres;
    std::string Country;
};

class Movies
{
    public:
    Movies()
    {
        fill();
    }
    QStringList getTitles()
    {
        QStringList titles;
        std::map<std::string, Movie>::iterator it;
        for (it = mp.begin(); it != mp.end(); ++it)
        {
            titles << QString::fromStdString(it->first);
        }
        return titles;
    }


    QStringList MovieDetails (std::string title)
    {
        QStringList details;
        Movie m = mp[title];
        details << QString::fromStdString("Title: " + m.title);
        details << QString::fromStdString("Year: " + m.year);
        details << QString::fromStdString("Age: " + m.Age);
        details << QString::fromStdString("IMDb rating: " + m.IMDb);
        details << QString::fromStdString("RT rating: " + m.RT);
        details << QString::fromStdString("Directors: " + m.Directors);
        details << QString::fromStdString("Genre: " + m.Genres);
        details << QString::fromStdString("Country: " + m.Country);

        return details;
    }


    QStringList MovieDetailsExport (std::string title)
    {
        QStringList details;
        Movie m = mp[title];
        details << QString::fromStdString(m.title);
        details << QString::fromStdString(m.year);
        details << QString::fromStdString(m.Age);
        details << QString::fromStdString(m.IMDb);
        details << QString::fromStdString(m.RT);
        details << QString::fromStdString(m.Directors);
        details << QString::fromStdString(m.Genres);
        details << QString::fromStdString(m.Country);

        return details;
    }



private:
    std::map<std::string,Movie> mp;

    void fill()
    {
        
        std::ifstream inputFile("C:/Users/mirza/Documents/test_app/data/movies.txt");
        std::string line, token;
        std::getline(inputFile, line);

        while(std::getline (inputFile, line))
        {
            std::istringstream ss(line);
            std::vector<std::string> vector;
            QList<QStandardItem *> standardItemsList; 
            while (std::getline(ss, token, ';'))
            {
                
                vector.push_back(token);
                standardItemsList.append(new QStandardItem(QString::fromStdString(token)));
            }


            std::string title = vector[2];
            std::string year = vector[3];
            std::string age = vector[4];
            std::string imbd = vector[5];
            std::string rt = vector[6];
            std::string directors = vector[12];
            std::string genre = vector[13];
            std::string country = vector[14];
            Movie movie = {title, year, age, imbd, rt, directors, genre, country};

            mp[title] = movie;

        }
        inputFile.close();

    }
};





#endif // MOVIES_H
