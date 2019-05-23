#pragma once
#include <list>
#include <forward_list>
#include <iostream>
#include <vector>

namespace MFun{

void print_vect(const std::vector<int>& vect_a);
int divide_first(int x);
int divide_last(int y);
void power(int c, int d, std::vector<int>& vect_c);
void showlist(const std::list <int>& list_a);
void fill_list(std::list<int>& list_y, std::vector<int>& vect_y);
void showlist_fwd(const std::forward_list<int>& list_n);
void set_vector(std::vector<int>& set_v);
}
