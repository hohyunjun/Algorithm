#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, string>> id;

void createAPI(string method, string url)
{
    if (method == "GET")
    {
        cout << "405 METHOD_NOT_ALLOWED" << '\n';
        return;
    }
    bool idExists = false;
    stringstream ss(url);
    string blank, users, userid;
    getline(ss, blank, '/');
    getline(ss, users, '/');
    getline(ss, userid, '/');
    for (int i = 0; i < id.size(); i++)
    {
        if (userid == id[i].first)
        {
            idExists = true;
            break;
        }
    }
    if (idExists)
    { // 이미 존재하는 userid인 경우
        cout << "403 FORBIDDEN" << '\n';
        return;
    }
    id.push_back(make_pair(userid, ""));
    cout << "201 CREATED" << '\n';
}

void saveAPI(string method, string url, string body)
{
    if (method == "GET")
    {
        cout << "405 METHOD_NOT_ALLOWED" << '\n';
        return;
    }
    int idIndex = -1;
    stringstream ss(url);
    string blank, users, userid;
    getline(ss, blank, '/');
    getline(ss, users, '/');
    getline(ss, userid, '/');
    for (int i = 0; i < id.size(); i++)
    {
        if (id[i].first == userid)
        {
            idIndex = i;
            break;
        }
    }
    if (idIndex == -1)
    {
        cout << "403 FORBIDDEN" << '\n';
        return;
    }
    stringstream ss2(body);
    string value, data;
    getline(ss2, value, '=');
    getline(ss2, data);
    id[idIndex].second = data;
    cout << "200 OK" << '\n';
    return;
}

void selectAPI(string method, string url, string body)
{
    if (method == "POST")
    {
        cout << "405 METHOD_NOT_ALLOWED" << '\n';
        return;
    }
    int idIndex = -1;
    stringstream ss(url);
    string blank, users, userid;
    getline(ss, blank, '/');
    getline(ss, users, '/');
    getline(ss, userid, '/');
    for (int i = 0; i < id.size(); i++)
    {
        if (id[i].first == userid)
        {
            idIndex = i;
            break;
        }
    }

    if (idIndex == -1)
    {
        cout << "403 FORBIDDEN" << '\n';
        return;
    }
    else if (id[idIndex].second == "")
    {
        cout << "404 NOT_FOUND" << '\n';
        return;
    }
    else
    {
        cout << "200 OK " << id[idIndex].second << '\n';
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    while (n-- > 0)
    {
        getline(cin, line); // drop a newline traling n
        stringstream ss(line);
        string method, url, body;
        getline(ss, method, ' ');
        getline(ss, url, ' ');
        getline(ss, body);

        if (url.find("/users/") == string::npos)
        { // /users/ 가 존재하지 않을 경우
            cout << "404 NOT_FOUND" << '\n';
            continue;
        }

        if (url.find("/data") == string::npos)
        {
            createAPI(method, url);
            continue;
        }
        else if (method == "POST" && body != "")
        {
            saveAPI(method, url, body);
            continue;
        }
        else
        {
            selectAPI(method, url, body);
            continue;
        }
    }
    return 0;
}
