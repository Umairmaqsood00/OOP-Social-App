#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// User class handles user credentials and bio
class User
{
public:
    string username, password, bio;
    User(string u = "", string p = "") : username(u), password(p), bio("") {}
    string getUsername() { return username; }
    bool checkPassword(string p) { return password == p; }
    void setBio(string b) { bio = b; }
    string getBio() { return bio; }
    void saveBioToFile()
    {
        vector<pair<string, string>> bios;
        ifstream in("user.txt");
        string u, b;
        bool found = false;
        while (getline(in, u) && getline(in, b))
        {
            if (u == username)
            {
                bios.push_back({u, bio});
                found = true;
            }
            else
            {
                bios.push_back({u, b});
            }
        }
        in.close();
        if (!found)
            bios.push_back({username, bio});
        ofstream out("user.txt");
        for (int i = 0; i < bios.size(); ++i)
        {
            out << bios[i].first << '\n'
                << bios[i].second << '\n';
        }
    }
    void loadBioFromFile()
    {
        ifstream in("user.txt");
        string u, b;
        while (getline(in, u) && getline(in, b))
        {
            if (u == username)
            {
                bio = b;
                return;
            }
        }
        bio = "";
    }
    static bool signup(string u, string p)
    {
        ifstream f("login.txt");
        string lineu, linep;
        while (getline(f, lineu) && getline(f, linep))
        {
            if (lineu == u)
                return false;
        }
        f.close();
        ofstream out("login.txt", ios::app);
        out << u << '\n'
            << p << '\n';
        return true;
    }
    static bool signin(string u, string p)
    {
        ifstream f("login.txt");
        string lineu, linep;
        while (getline(f, lineu) && getline(f, linep))
        {
            if (lineu == u && linep == p)
                return true;
        }
        return false;
    }
};

class Post
{
public:
    string author, content;
    Post(string a = "", string c = "") : author(a), content(c) {}
    void display(int index = -1)
    {
        if (index == -1)
            cout << author << ": " << content << endl;
        else
        {
            cout << "[" << index << "] " << author << ": " << content;
            int likes = getLikeCount(index);
            cout << " [Likes: " << likes << "]" << endl;
        }
    }
    void saveToFile()
    {
        ofstream f("feed.txt", ios::app);
        f << author << '\n'
          << content << '\n';
    }
    static vector<Post> loadAll()
    {
        vector<Post> posts;
        ifstream f("feed.txt");
        string a, c;
        while (getline(f, a) && getline(f, c))
        {
            posts.emplace_back(a, c);
        }
        return posts;
    }
    static void likePost(int postIndex, string username)
    {
        if (hasUserLiked(postIndex, username))
            return;
        ofstream f("likecom.txt", ios::app);
        f << postIndex << ' ' << username << '\n';
    }
    static int getLikeCount(int postIndex)
    {
        ifstream f("likecom.txt");
        string line;
        int count = 0, idx;
        string user;
        while (getline(f, line))
        {
            istringstream iss(line);
            if (iss >> idx >> user)
            {
                if (idx == postIndex)
                    count++;
            }
        }
        return count;
    }
    static bool hasUserLiked(int postIndex, string username)
    {
        ifstream f("likecom.txt");
        string line;
        int idx;
        string user;
        while (getline(f, line))
        {
            istringstream iss(line);
            if (iss >> idx >> user)
            {
                if (idx == postIndex && user == username)
                    return true;
            }
        }
        return false;
    }
};

class Comment
{
public:
    int postIndex;
    string author, text;
    Comment(int idx = -1, string a = "", string t = "") : postIndex(idx), author(a), text(t) {}
    void display()
    {
        cout << author << " commented: " << text << endl;
    }
    void saveToFile()
    {
        ofstream f("comments.txt", ios::app);
        f << postIndex << ' ' << author << ' ' << text << '\n';
    }
    static vector<Comment> loadAll()
    {
        vector<Comment> comments;
        ifstream f("comments.txt");
        string line;
        while (getline(f, line))
        {
            istringstream iss(line);
            int idx;
            string a, t;
            if (iss >> idx >> a)
            {
                getline(iss, t);
                if (!t.empty() && t[0] == ' ')
                    t = t.substr(1);
                comments.emplace_back(idx, a, t);
            }
        }
        return comments;
    }
};

class App
{
public:
    void run();
};
