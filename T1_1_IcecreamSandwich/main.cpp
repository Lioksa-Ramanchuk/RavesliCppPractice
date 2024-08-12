/*
������� �1

������� � ��������� � ��� ������, ������������ ����� ����������� ������� �
������ ���������. ��������:

AABBBAA
3&&3
yyyyymmmmmmmmyyyyy
hhhhhhhhmhhhhhhhh

�������� ��������, ��� ����� � ������ ����� �������� ��������� ��� �� �����, ���
� �� ������������� ��������. �������� ���������� ������ (�������� �� ������
����) ����� ��������.

��������� �� �������� ��������� � ����������:

BBBBB // �� �� ������ ����� ������ ���������� (��� ��������)
AAACCCAA // �� �� ������ ����� �������� �� ����� ��������� � ��������
AACDCAA // �� �� ������ ����� ������� �� ������ ��������
A // ��� ������� �� ����� ���� ����� ���� ��������

�������� ���������, ������� ���������� true, ���� ������, ���������
�������������, �������� ��������� � ���������, � false � � ��������� ������.

�������:

isIcecreamSandwich ("CDC") -> true
isIcecreamSandwich ("AAABB") -> false
isIcecreamSandwich ("AA") -> false

����������: ������� � ��������� ������ ����� ����������� ����� 3 �������, � ���
������� 2 �� ���� �������� ������ ���� ��������.
*/

#include <iostream>
#include <string>
#include <string_view>

bool isIcecreamSandwich(std::string_view);

int main() {
  std::string input;

  while (true) {
    std::cout << "Enter a string (or press <Enter> to exit): ";
    getline(std::cin, input);
    if (input.length() == 0) {
      break;
    }

    std::cout << "The entered string "
              << (isIcecreamSandwich(input) ? "is" : "is not")
              << " an icecream sandwich.\n\n";
  }

  return 0;
}

bool isIcecreamSandwich(std::string_view str) {
  const auto kLength = str.length();
  if (kLength < 3) {
    return false;
  }

  auto start = 0;
  auto end = kLength - 1;

  const auto kBread = str[start];

  while (start < end && str[start] == str[end] && str[start] == kBread) {
    ++start;
    --end;
  }

  if (start > end) {
    return false;
  }

  const auto kIcecream = str[start];
  if (kIcecream == kBread) {
    return false;
  }

  while (start <= end) {
    if (str[start] != kIcecream) {
      return false;
    }
    ++start;
  }

  return true;
}