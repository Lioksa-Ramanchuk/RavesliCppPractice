/*
Задание №1

Сэндвич с мороженым — это строка, образованная двумя одинаковыми концами и
разной серединой. Например:

AABBBAA
3&&3
yyyyymmmmmmmmyyyyy
hhhhhhhhmhhhhhhhh

Обратите внимание, что левый и правый концы сэндвича идентичны как по длине, так
и по повторяющимся символам. Середину составляет третий (отличный от первых
двух) набор символов.

Следующее не является сэндвичем с мороженным:

BBBBB // вы не можете иметь только мороженное (без сэндвича)
AAACCCAA // вы не можете иметь неравные по длине окончания в сэндвиче
AACDCAA // вы не можете иметь начинку из разных символов
A // ваш сэндвич не может быть менее трех символов

Напишите программу, которая возвращает true, если строка, введенная
пользователем, является сэндвичем с мороженым, и false — в противном случае.

Примеры:

isIcecreamSandwich ("CDC") -> true
isIcecreamSandwich ("AAABB") -> false
isIcecreamSandwich ("AA") -> false

Примечание: Сэндвич с мороженым должен иметь минимальную длину 3 символа, и как
минимум 2 из этих символов должны быть различны.
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