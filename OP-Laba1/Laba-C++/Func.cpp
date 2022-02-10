#include "Func.h"

void input(vector<string>& text, string& name1)
{
    cout << "Input the text to the file " << name1 <<" . Press \"Ctrl\" + \"Q\" to exit\n";
    string str; // �������� �����
    bool flag = true; // ��� ������ � �����
    while (flag)
    {
        getline(cin, str); // ������� �����
        for (int i = 0; i < str.size(); i++) // ����������, �� � � ����� ������ � ����� 17 ("Ctrl" + "Q")
        {
            if (str[i] == 17)
            {
                flag = false; // ��� ������ �� �����
                str.erase(i); // ��������� ������ "Ctrl" + "Q" � ���, �� ��� �� ���
            }
        }
        if (str.size() > 0) // ����������, �� �� ������ �����
        {
            text.push_back(str); // ���������� ����� � ������
        }
    }
}

void record(vector<string>& text, string& name1, string& name2)
{
    // ³�������� ��� ������ �����
    ofstream file1(name1);
    ofstream file2(name2);

    for (int i = 0; i < text.size(); i++)
    {
        file1 << text[i] << endl; // �������� � ������ ���� �������� �����
        file2 << text[i].size() << " " << text[i] << " " << i + 1 << endl; // �������� � ������ ���� �������� ������������ �����
    }

    // ��������� �����
    file1.close();
    file2.close();
}

void output(vector<string>& text, string& name2)
{
    cout << "\nThe modified text from the file " << name2 << " .\n";

    // �������� ����� � �������
    for (int i = 0; i < text.size(); i++)
    {
        cout << text[i].size() << " " << text[i] << " " << i + 1 << endl;
    }
}