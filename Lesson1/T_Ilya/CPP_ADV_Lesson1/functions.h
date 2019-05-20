#pragma once
#include <list>
#include <iterator>
#include <forward_list>
#include <iostream>
#include <vector>

namespace MFun{

void print_vect(std::vector<int> a_vect);
int divide_first(int x);
int divide_last(int y);
void power(int c, int d, std::vector<int>& vect_c);
void print_vect_b(const std::vector<int>& vect_c);
void showlist_z(std::list <int> list_z);
void fill_list(std::list<int>& list_y, std::vector<int>& vect_y);
void showlist_fwd(std::forward_list <int> list_n);
void print_vect_a(std::vector<int> a_vect);
void set_vector(std::vector<int> set_v);
}

