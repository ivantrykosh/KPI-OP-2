#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

class Text
{
private:
    vector<string> text; // ����� �����
    string Litery = "����������������������"; // ��������� �����
    string Alphabet = "�������������������������������"; // �� �����
    bool litera(char&, string); // ��� �������� ������� �� �����
public:
    void add_text(string&); // ��������� ����� �� ������
    vector<string>& get_text(); // ��������� ������ �����
    float& percent(); // ³������ ����������� ����
};

void input_text(vector<Text>&); // ������� �����
void add(vector<Text>&); // ������ �����
void output_text(vector<Text>&); // �������� ������
void out_percent(vector<Text>&); // �������� ��������� �������