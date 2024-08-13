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

using namespace ravesli_cpp_practice::t1_1_icecream_sandwich;

int main() {
  std::string input;

  while (true) {
    std::cout << "Enter a string (or press <Enter> to exit):" << '\n';
    std::cout << "> ";
    getline(std::cin, input);
    if (input.empty()) {
      break;
    }

    std::cout << "The entered string "
              << (isIcecreamSandwich(input) ? "is" : "is not")
              << " an icecream sandwich." << '\n'
              << '\n';
  }

  return 0;
}