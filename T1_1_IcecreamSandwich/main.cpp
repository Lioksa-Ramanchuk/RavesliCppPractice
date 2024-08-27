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

#include "is_icecream_sandwich.hpp"

using namespace ravesli_cpp_practice;

using t1_1_icecream_sandwich::IsIcecreamSandwich;

int main() {
  std::string input;

  while (true) {
    std::cout << "Enter a string (or press <Enter> to exit):" << '\n';
    getline(std::cin, input);
    if (input.empty()) {
      break;
    }

    std::cout << "The entered string "
              << (IsIcecreamSandwich(input) ? "is" : "is not")
              << " an ice-cream sandwich." << '\n'
              << '\n';
  }

  return 0;
}