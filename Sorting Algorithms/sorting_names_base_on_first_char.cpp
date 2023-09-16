#include <iostream>
using namespace std;

int main()
{
    string name[5] = {"subrata","sa","rakesh","sourav","antu"};
    for(int i = 0; i < 5; i++)
    {
        //---------min finding--------
        int k=0;
        int m = i;
        for(int j = i; j < 5; j++)
        {
            if(name[j][k] < name[m][k])
            {
                m = j;
            }
        }
        string an = name[m];
        //----------swaping---------
        for(int a = m; a >= 1+i; a--)
        {
            name[a]=name[a-1];
        }
        name[i]= an;
    }
    for(int i = 0; i < 5-1; i++)
    {
        cout << name[i] << ",";
    }
    cout<<name[5-1];
    return 0;
}